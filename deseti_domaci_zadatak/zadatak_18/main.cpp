/*

Napraviti program na osnovu sledećeg teksta: Naša firma se bavi proizvodnjom prehrambrenih
proizvoda. O svim proizvodima čuvamo sledeće informacije: Ime proizvoda, cena proizvoda, rok
trajanja. Klasa Proizvod treba da sadrži i funkciju Info() koja štampa sve podatke o proizvodu. Jedna
od kategorija mogu biti i Sokovi. Kod sokova čuvamo i podataka od čega je sok. Klasa Sokovi treba
da sadrži i funkciju Info() koja osim svih podataka o proizvodu štampa i podatak o od čega je sok.
Kod opstih proizvoda PDV je 20% dok je za Sokovi PDV na cenu 12%.

*/
#include <iostream>
#include <string>

class Proizvod
{
protected:
    std::string ime;
    double cena;
    int rokTrajanja;

public:
    Proizvod(const std::string &ime, double cena, int rokTrajanja)
        : ime(ime), cena(cena), rokTrajanja(rokTrajanja) {}

    virtual void Info() const
    {
        std::cout << "Ime proizvoda: " << ime << std::endl;
        std::cout << "Cena proizvoda: " << cena << " RSD" << std::endl;
        std::cout << "Rok trajanja: " << rokTrajanja << " dana" << std::endl;
    }
};

class Sokovi : public Proizvod
{
private:
    std::string sastojak;

public:
    Sokovi(const std::string &ime, double cena, int rokTrajanja, const std::string &sastojak)
        : Proizvod(ime, cena, rokTrajanja), sastojak(sastojak) {}

    void Info() const override
    {
        Proizvod::Info();
        std::cout << "Sastojak: " << sastojak << std::endl;
    }
};

int main()
{
    Proizvod opstiProizvod("Hleb", 120.0, 7);
    Sokovi sok("Narandza sok", 150.0, 14, "Narandza");

    std::cout << "Opsti proizvod:" << std::endl;
    opstiProizvod.Info();

    std::cout << std::endl;

    std::cout << "Sok:" << std::endl;
    sok.Info();

    return 0;
}