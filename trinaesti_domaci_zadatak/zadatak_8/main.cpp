#include <iostream>
#include <stdexcept>
#include <string>
#include <cctype>

class ImeGradaNijeValidnoException : public std::exception
{
public:
    const char *what() const throw()
    {
        return "Pocetno slovo grada nije veliko. Prepravi svoju gresku";
    }
};

class Student
{
private:
    std::string ime;
    std::string prezime;
    std::string adresa;
    std::string grad;
    std::string indeks;

public:
    Student(const std::string &ime, const std::string &prezime, const std::string &adresa,
            const std::string &grad, const std::string &indeks)
        : ime(ime), prezime(prezime), adresa(adresa), indeks(indeks)
    {
        if (!isupper(grad[0]))
        {
            throw ImeGradaNijeValidnoException();
        }
        this->grad = grad;
    }

    void IspisiInformacije()
    {
        std::cout << "Ime: " << ime << ", Prezime: " << prezime << ", Adresa: " << adresa << ", Grad: " << grad << ", Indeks: " << indeks << std::endl;
    }
};

int main()
{
    try
    {
        Student s("Marko", "Marković", "Ulica br. 1", "beograd", "123456");
        s.IspisiInformacije();
    }
    catch (const ImeGradaNijeValidnoException &e)
    {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}