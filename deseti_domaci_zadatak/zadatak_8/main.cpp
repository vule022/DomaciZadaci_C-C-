#include <iostream>
#include <string>

class Zivotinja
{
protected:
    std::string vrsta;
    std::string boja;
    int godine;
    double tezina;
    std::string habitat;

public:
    Zivotinja(std::string vrsta, std::string boja, int godine, double tezina, std::string habitat) : vrsta(vrsta), boja(boja), godine(godine), tezina(tezina), habitat(habitat) {}

    virtual void Info()
    {
        std::cout << "Vrsta zivotinje: " << vrsta << std::endl;
        std::cout << "Boja: " << boja << std::endl;
        std::cout << "Godine: " << godine << std::endl;
        std::cout << "Tezina: " << tezina << " kg" << std::endl;
        std::cout << "Habitat: " << habitat << std::endl;
    }
};

class DomacaZivotinja : public Zivotinja
{
private:
    std::string imeVlasnika;

public:
    DomacaZivotinja(std::string vrsta, std::string boja, int godine, double tezina, std::string habitat, std::string imeVlasnika) : Zivotinja(vrsta, boja, godine, tezina, habitat), imeVlasnika(imeVlasnika) {}

    void Info() override
    {
        Zivotinja::Info();
        std::cout << "Ime vlasnika: " << imeVlasnika << std::endl;
    }
};

int main()
{
    Zivotinja zebra("Zebra", "Crno-bela", 7, 200.5, "Savane Afrike");
    DomacaZivotinja macka("Mačka", "Siva", 3, 4.2, "Kuća", "Jovan");

    zebra.Info();
    std::cout << "-------------------" << std::endl;
    macka.Info();

    return 0;
}