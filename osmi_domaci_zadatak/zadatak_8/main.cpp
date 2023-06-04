#include <iostream>
#include <vector>
#include "Osoba.h"

int main()
{
    std::vector<Osoba> osobe;

    for (int i = 0; i < 5; i++)
    {
        std::string ime, adresa;
        int starost;

        std::cout << "Unesite ime osobe: ";
        std::cin >> ime;

        std::cout << "Unesite adresu osobe: ";
        std::cin >> adresa;

        std::cout << "Unesite starost osobe: ";
        std::cin >> starost;

        osobe.push_back(Osoba(ime, adresa, starost));
    }

    Osoba najmladja = osobe[0], najstarija = osobe[0];
    for (auto &osoba : osobe)
    {
        if (osoba.getStarost() < najmladja.getStarost())
        {
            najmladja = osoba;
        }
        if (osoba.getStarost() > najstarija.getStarost())
        {
            najstarija = osoba;
        }
        if (osoba.getIme() == "Petar")
        {
            std::cout << "Osoba imenom Petar: " << osoba.getAdresa() << ", " << osoba.getStarost() << "\n";
        }
    }

    std::cout << "Najmladja osoba: " << najmladja.getIme() << ", " << najmladja.getAdresa() << ", " << najmladja.getStarost() << "\n";
    std::cout << "Najstarija osoba: " << najstarija.getIme() << ", " << najstarija.getAdresa() << ", " << najstarija.getStarost() << "\n";

    return 0;
}
