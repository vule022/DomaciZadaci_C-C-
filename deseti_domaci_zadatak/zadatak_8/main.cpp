/*

Napraviti klasu Zivotinja. Klasa Zivotinja mora imati makar 5 atributa po slobodnom izboru. Klasa
Zivotinja treba da sadrži i funkciju Info() koja štampa naziv životinje. Potom kreirati izvedenu klasu
DomacaZivotinja za koju čuvamo i string promenljivu za ime vlasnika. Kreirati nadglasavajuću
funkciju Info() klase DomacaZivotinja koja osim opštih podataka o zivotinji štampa i ime vlasnika.

*/

#include <iostream>
#include <string>

class Zivotinja
{
protected:
    std::string vrsta;
    std::string boja;
    int godine;
    double tezina;
    std::string sredina;

public:
    Zivotinja(std::string vrsta, std::string boja, int godine, double tezina, std::string sredina) : vrsta(vrsta), boja(boja), godine(godine), tezina(tezina), sredina(sredina) {}

    virtual void Info()
    {
        std::cout << "Vrsta zivotinje: " << vrsta << std::endl;
        std::cout << "Boja: " << boja << std::endl;
        std::cout << "Godine: " << godine << std::endl;
        std::cout << "Tezina: " << tezina << " kg" << std::endl;
        std::cout << "Zivotna sredina: " << sredina << std::endl;
    }
};

class DomacaZivotinja : public Zivotinja
{
private:
    std::string imeVlasnika;

public:
    DomacaZivotinja(std::string vrsta, std::string boja, int godine, double tezina, std::string sredina, std::string imeVlasnika) : Zivotinja(vrsta, boja, godine, tezina, sredina), imeVlasnika(imeVlasnika) {}

    void Info() override
    {
        Zivotinja::Info();
        std::cout << "Ime vlasnika: " << imeVlasnika << std::endl;
    }
};

int main()
{
    Zivotinja zebra("Zebra", "Crno-bela", 7, 200.5, "Savana");
    DomacaZivotinja macka("Mačka", "Siva", 3, 4.2, "Kuca, stan...", "Jovan");

    zebra.Info();
    std::cout << "-------------------" << std::endl;
    macka.Info();

    return 0;
}