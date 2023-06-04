#ifndef TACKA_H
#define TACKA_H

#include <iostream>

class Tacka
{
private:
    double x;
    double y;

public:
    Tacka();
    Tacka(double x, double y);

    double getX() const;
    double getY() const;

    void setX(double x);
    void setY(double y);

    Tacka operator+(const Tacka &other) const;
    Tacka operator-(const Tacka &other) const;
    Tacka &operator=(const Tacka &other);

    friend std::istream &operator>>(std::istream &is, Tacka &tacka);
    friend std::ostream &operator<<(std::ostream &os, const Tacka &tacka);
};

#endif
