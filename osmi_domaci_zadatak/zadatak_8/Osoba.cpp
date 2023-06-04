#include "Osoba.h"
#include <iostream>

Osoba::Osoba() : ime(""), adresa(""), starost(0) {}

Osoba::Osoba(std::string ime, std::string adresa, int starost)
{
    this->ime = ime;
    this->adresa = adresa;
    this->starost = starost;
}

Osoba::Osoba(const Osoba &o) : ime(o.ime), adresa(o.adresa), starost(o.starost) {}

Osoba::~Osoba()
{
    std::cout << "Objekat je uništen\n";
}

std::string Osoba::getIme() const
{
    return this->ime;
}

void Osoba::setIme(std::string ime)
{
    this->ime = ime;
}

std::string Osoba::getAdresa() const
{
    return this->adresa;
}

void Osoba::setAdresa(std::string adresa)
{
    this->adresa = adresa;
}

int Osoba::getStarost() const
{
    return this->starost;
}

void Osoba::setStarost(int starost)
{
    this->starost = starost;
}
