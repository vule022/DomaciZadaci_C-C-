#include <iostream>
#include <fstream>
#include <string>

struct Ucenik
{
    std::string ime;
    std::string adresa;
    int razred;
    int odeljenje;
};

int main()
{
    int trazeniRazred, trazenoOdeljenje;
    std::cout << "Unesite razred: ";
    std::cin >> trazeniRazred;
    std::cout << "Unesite odeljenje: ";
    std::cin >> trazenoOdeljenje;

    std::ifstream inputFile("ucenik.txt");
    if (!inputFile)
    {
        std::cerr << "Greska pri otvaranju datoteke." << std::endl;
        return 1;
    }

    Ucenik ucenik;
    while (inputFile >> ucenik.ime >> ucenik.adresa >> ucenik.razred >> ucenik.odeljenje)
    {
        if (ucenik.razred == trazeniRazred && ucenik.odeljenje == trazenoOdeljenje)
        {
            std::cout << "Ime: " << ucenik.ime << std::endl;
            std::cout << "Adresa: " << ucenik.adresa << std::endl;
            std::cout << "Razred: " << ucenik.razred << std::endl;
            std::cout << "Odeljenje: " << ucenik.odeljenje << std::endl;
            std::cout << "------------------------" << std::endl;
        }
    }

    inputFile.close();

    return 0;
}