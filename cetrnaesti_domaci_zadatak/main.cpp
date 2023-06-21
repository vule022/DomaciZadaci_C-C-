#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>

struct Ucenik
{
    std::string ime;
    std::string adresa;
    int razred;
    int odeljenje;
};

int main()
{
    std::ifstream file("ucenik.txt");
    if (!file.is_open())
    {
        std::cout << "Greska prilikom otvaranja fajla." << std::endl;
        return 1;
    }

    std::vector<Ucenik> ucenici;

    std::string line;
    while (std::getline(file, line))
    {
        std::stringstream ss(line);
        Ucenik ucenik;
        std::getline(ss, ucenik.ime, ',');
        std::getline(ss, ucenik.adresa, ',');
        ss >> ucenik.razred;
        ss.ignore(1, ',');
        ss >> ucenik.odeljenje;
        ucenici.push_back(ucenik);
    }

    file.close();

    int N, M;
    std::cout << "Unesite razred (N): ";
    std::cin >> N;
    std::cout << "Unesite odeljenje (M): ";
    std::cin >> M;

    for (const auto &ucenik : ucenici)
    {
        if (ucenik.razred == N && ucenik.odeljenje == M)
        {
            std::cout << ucenik.ime << ", " << ucenik.adresa << ", " << ucenik.razred << ", " << ucenik.odeljenje << std::endl;
        }
    }

    return 0;
}
