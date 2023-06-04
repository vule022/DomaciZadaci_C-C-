#include "Tacka.h"

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
