#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include <stack>
#include <string>

class Sat
{
protected:
    std::string ime;
    std::string model;
    int godinaProizvodnje;
    double trajanjeBaterije;

public:
    Sat(std::string ime, std::string model, int godina, double trajanje)
        : ime(ime), model(model), godinaProizvodnje(godina), trajanjeBaterije(trajanje) {}

    virtual void Info() const
    {
        std::cout << "Ime: " << ime << "\nModel: " << model
                  << "\nGodina proizvodnje: " << godinaProizvodnje
                  << "\nTrajanje baterije (u danima): " << trajanjeBaterije << std::endl;
    }

    bool operator==(const Sat &other) const
    {
        return ime == other.ime && model == other.model && godinaProizvodnje == other.godinaProizvodnje;
    }
};

class KvarcniSat : public Sat
{
private:
    double velicinaBaterije;

public:
    KvarcniSat(std::string ime, std::string model, int godina, double trajanje, double velicina)
        : Sat(ime, model, godina, trajanje), velicinaBaterije(velicina) {}

    void Info() const override
    {
        Sat::Info();
        std::cout << "Velicina baterije: " << velicinaBaterije << " Ah" << std::endl;
    }

    bool operator==(const KvarcniSat &other) const
    {
        return Sat::operator==(other) && velicinaBaterije == other.velicinaBaterije;
    }
};

int main()
{
    std::vector<Sat *> satovi;

    satovi.push_back(new Sat("Rolex", "Submariner", 2021, 120.0));
    satovi.push_back(new Sat("Omega", "Seamaster", 2021, 90.0));
    satovi.push_back(new KvarcniSat("Casio", "G-Shock", 2021, 168.0, 5.0));
    satovi.push_back(new KvarcniSat("Seiko", "Quartz", 2021, 168.0, 6.0));
    satovi.push_back(new Sat("Tag Heuer", "Carrera", 2021, 100.0));

    satovi.insert(satovi.begin() + 2, new KvarcniSat("Citizen", "Eco-Drive", 2021, 168.0, 4.0));

    satovi.pop_back();

    for (const auto &sat : satovi)
    {
        sat->Info();
        std::cout << "-------------------" << std::endl;
    }

    // Kreiraj novi objekat O1
    KvarcniSat O1("Casio", "G-Shock", 2021, 168.0, 5.0);

    // Proveri da li se O1 nalazi u vektoru
    auto it = std::find(satovi.begin(), satovi.end(), &O1);

    if (it != satovi.end())
    {
        std::cout << "Objekat je pronađen." << std::endl;
    }
    else
    {
        std::cout << "Objekat nije pronađen." << std::endl;
    }

    std::ifstream ulaz("ulaz.txt");
    std::stack<Sat *> stek;
    std::string ime, model;
    int godina;
    double trajanje, velicina;
    while (ulaz >> ime >> model >> godina >> trajanje >> velicina)
    {
        stek.push(new KvarcniSat(ime, model, godina, trajanje, velicina));
    }
    ulaz.close();

    std::ofstream izlaz("izlaz.txt");
    while (!stek.empty())
    {
        izlaz << stek.top()->Info() << std::endl;
        stek.pop();
    }
    izlaz.close();

    return 0;
}