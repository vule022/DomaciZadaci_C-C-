#include "Tacka.h"
#include "Krug.h"
#include <iostream>
#include <vector>

Tacka::Tacka()
{
    x = 0.0;
    y = 0.0;
}

Tacka::Tacka(double x, double y)
{
    this->x = x;
    this->y = y;
}

double Tacka::getX() const
{
    return x;
}

double Tacka::getY() const
{
    return y;
}

void Tacka::setX(double x)
{
    this->x = x;
}

void Tacka::setY(double y)
{
    this->y = y;
}

Tacka Tacka::operator+(const Tacka &other) const
{
    double newX = x + other.x;
    double newY = y + other.y;
    return Tacka(newX, newY);
}

Tacka Tacka::operator-(const Tacka &other) const
{
    double newX = x - other.x;
    double newY = y - other.y;
    return Tacka(newX, newY);
}

Tacka &Tacka::operator=(const Tacka &other)
{
    if (this != &other)
    {
        x = other.x;
        y = other.y;
    }
    return *this;
}

std::istream &operator>>(std::istream &is, Tacka &tacka)
{
    is >> tacka.x >> tacka.y;
    return is;
}

std::ostream &operator<<(std::ostream &os, const Tacka &tacka)
{
    os << "(" << tacka.x << ", " << tacka.y << ")";
    return os;
}

#include "Krug.h"
#include <cmath>

Krug::Krug()
{
    poluprecnik = 0.0;
}

Krug::Krug(const Tacka &centar, double poluprecnik)
{
    this->centar = centar;
    this->poluprecnik = poluprecnik;
}

double Krug::getPovrsina() const
{
    return 3.14159 * pow(poluprecnik, 2);
}

double Krug::getObim() const
{
    return 2 * 3.14159 * poluprecnik;
}

bool Krug::tackaPripadaKrugu(const Tacka &tacka) const
{
    double udaljenost = sqrt(pow(tacka.getX() - centar.getX(), 2) + pow(tacka.getY() - centar.getY(), 2));
    return udaljenost <= poluprecnik;
}

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
