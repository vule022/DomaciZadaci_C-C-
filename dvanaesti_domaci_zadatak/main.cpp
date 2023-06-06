#include <iostream>
#include <vector>
#include <stack>
#include <fstream>
#include <algorithm>
#include <string>

class Sat
{
protected:
    std::string ime;
    std::string model;
    int godinaProizvodnje;
    double trajanjeBaterije;

public:
    Sat(std::string ime, std::string model, int godinaProizvodnje, double trajanjeBaterije)
        : ime(ime), model(model), godinaProizvodnje(godinaProizvodnje), trajanjeBaterije(trajanjeBaterije) {}

    virtual double preostaloTrajanjeBaterije()
    {
        return (trajanjeBaterije * 2) * 7;
    }

    virtual void info()
    {
        std::cout << "Ime: " << ime << "\nModel: " << model << "\nGodina proizvodnje: " << godinaProizvodnje
                  << "\nTrajanje baterije: " << trajanjeBaterije << std::endl;
    }
};

class KvarcniSat : public Sat
{
protected:
    double velicinaBaterije;

public:
    KvarcniSat(std::string ime, std::string model, int godinaProizvodnje, double trajanjeBaterije, double velicinaBaterije)
        : Sat(ime, model, godinaProizvodnje, trajanjeBaterije), velicinaBaterije(velicinaBaterije) {}

    double preostaloTrajanjeBaterije() override
    {
        return (trajanjeBaterije * 24) * 7;
    }

    void info() override
    {
        Sat::info();
        std::cout << "Velicina baterije: " << velicinaBaterije << " Ah" << std::endl;
    }

    static KvarcniSat ucitajIzFajla(std::istream &is)
    {
        std::string ime, model, line;
        int godinaProizvodnje;
        double trajanjeBaterije, velicinaBaterije;

        std::getline(is, ime);
        std::getline(is, model);
        std::getline(is, line);
        godinaProizvodnje = std::stoi(line);
        std::getline(is, line);
        trajanjeBaterije = std::stod(line);
        std::getline(is, line);
        velicinaBaterije = std::stod(line);

        return KvarcniSat(ime, model, godinaProizvodnje, trajanjeBaterije, velicinaBaterije);
    }

    void upisiUFajl(std::ostream &os)
    {
        os.write(ime.data(), ime.size());
        os.put('\n');
        os.write(model.data(), model.size());
        os.put('\n');
        os.write(std::to_string(godinaProizvodnje).data(), std::to_string(godinaProizvodnje).size());
        os.put('\n');
        os.write(std::to_string(trajanjeBaterije).data(), std::to_string(trajanjeBaterije).size());
        os.put('\n');
        os.write(std::to_string(velicinaBaterije).data(), std::to_string(velicinaBaterije).size());
        os.put('\n');
    }
};

int main()
{
    std::stack<KvarcniSat> stek;
    std::ifstream ulaz("ulaz.txt");
    std::ofstream izlaz("izlaz.txt");

    while (ulaz.good())
    {
        stek.push(KvarcniSat::ucitajIzFajla(ulaz));
    }

    while (!stek.empty())
    {
        KvarcniSat &sat = stek.top();
        sat.info();
        sat.upisiUFajl(izlaz);
        stek.pop();
    }

    ulaz.close();
    izlaz.close();

    return 0;
}