#include <iostream>
#include <array>
#include <random>

double aritmeticka_sredina_dvocifrenih(const std::array<int, 1000> &niz)
{
    int suma = 0;
    int brojac = 0;

    for (const auto &element : niz)
    {
        suma += element;
        brojac++;
    }

    if (brojac != 0)
    {
        return static_cast<double>(suma) / brojac;
    }
    else
    {
        return 0;
    }
}

int main()
{
    std::array<int, 1000> niz;

    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(0, 9);

    for (auto &element : niz)
    {
        int prvaCifra = dis(gen);
        int drugaCifra = dis(gen);
        element = prvaCifra * 10 + drugaCifra; // formiranje dvocifrenog broja
    }

    std::cout << "Aritmeticka sredina dvocifrenih elemenata niza: "
              << aritmeticka_sredina_dvocifrenih(niz) << std::endl;

    return 0;
}