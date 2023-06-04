#include "Tacka.h"
#include "Krug.h"
#include <iostream>
#include <vector>

int main()
{
    Tacka centar(0.0, 0.0);
    Krug krug(centar, 5.0);

    std::vector<Tacka> tacke(10);
    std::cout << "Unesite koordinate 10 tacaka:\n";
    for (int i = 0; i < 10; i++)
    {
        std::cin >> tacke[i];
    }
    std::cout << "\n";

    std::cout << "Tacne koje se nalaze u unutrasnjosti kruga:\n";
    for (const auto &tacka : tacke)
    {
        if (krug.tackaPripadaKrugu(tacka))
        {
            std::cout << tacka << std::endl;
        }
    }

    return 0;
}
