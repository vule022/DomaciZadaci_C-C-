#ifndef KRUG_H
#define KRUG_H

#include "Tacka.h"

class Krug
{
private:
    Tacka centar;
    double poluprecnik;

public:
    Krug();
    Krug(const Tacka &centar, double poluprecnik);

    double getPovrsina() const;
    double getObim() const;
    bool tackaPripadaKrugu(const Tacka &tacka) const;
};

#endif // KRUG_H
