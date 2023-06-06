#include <iostream>
#include <string>

class Sat
{
protected:
    std::string ime;
    std::string model;
    int godinaProizvodnje;
    int trajanjeBaterije;

public:
    Sat(std::string ime, std::string model, int godinaProizvodnje, int trajanjeBaterije) : ime(ime), model(model), godinaProizvodnje(godinaProizvodnje), trajanjeBaterije(trajanjeBaterije) {}

    virtual int PreostaloTrajanjeBaterije()
    {
        return (trajanjeBaterije * 2) * 7;
    }

    void Info()
    {
        std::cout << "Ime sata: " << ime << std::endl;
        std::cout << "Model: " << model << std::endl;
        std::cout << "Godina proizvodnje: " << godinaProizvodnje << std::endl;
        std::cout << "Preostalo trajanje baterije (u satima): " << PreostaloTrajanjeBaterije() << std::endl;
    }
};

class KvarcniSat : public Sat
{
private:
    double velicinaBaterije;

public:
    KvarcniSat(std::string ime, std::string model, int godinaProizvodnje, int trajanjeBaterije, double velicinaBaterije) : Sat(ime, model, godinaProizvodnje, trajanjeBaterije), velicinaBaterije(velicinaBaterije) {}

    int PreostaloTrajanjeBaterije() override
    {
        return (trajanjeBaterije * 24) * 7;
    }

    void Info()
    {
        Sat::Info();
        std::cout << "Velicina baterije: " << velicinaBaterije << " Ah" << std::endl;
    }
};

int main()
{
    Sat s("Rolex", "GMT Master II", 2023, 1000);
    KvarcniSat ks("Casio", "Quartz", 2023, 1000, 10.5);

    s.Info();
    std::cout << "-------------------" << std::endl;
    ks.Info();

    return 0;
}