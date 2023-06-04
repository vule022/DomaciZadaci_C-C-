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
