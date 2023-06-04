#ifndef OSOBA_H
#define OSOBA_H

#include <string>

class Osoba
{
private:
    std::string ime;
    std::string adresa;
    int starost;

public:
    Osoba();
    Osoba(std::string ime, std::string adresa, int starost);
    Osoba(const Osoba &o);
    ~Osoba();

    std::string getIme() const;
    void setIme(std::string ime);

    std::string getAdresa() const;
    void setAdresa(std::string adresa);

    int getStarost() const;
    void setStarost(int starost);
};

#endif
