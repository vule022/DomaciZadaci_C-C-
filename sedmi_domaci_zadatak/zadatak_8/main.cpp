#include <iostream>
#include <iomanip>

int main()
{
    double cenaProizvoda;

    std::cout << "Unesite vrednost proizvoda u dinarima: ";
    std::cin >> cenaProizvoda;

    int brojNovcanica500 = cenaProizvoda / 500;
    cenaProizvoda -= brojNovcanica500 * 500;

    int brojNovcanica100 = cenaProizvoda / 100;
    cenaProizvoda -= brojNovcanica100 * 100;

    int brojNovcanica1 = cenaProizvoda;

    std::cout << "Za placanje proizvoda je potrebno:\n";
    std::cout << std::setw(2) << brojNovcanica500 << " novcanica od 500 dinara\n";
    std::cout << std::setw(2) << brojNovcanica100 << " novcanica od 100 dinara\n";
    std::cout << std::setw(2) << brojNovcanica1 << " novcanica od 1 dinara\n";

    return 0;
}
