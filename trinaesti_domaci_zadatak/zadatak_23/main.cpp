#include <iostream>
#include <stdexcept>
#include <string>

class ImeNijeValidnoException : public std::exception
{
public:
    const char *what() const throw()
    {
        return "Ime sata mora imati najmanje 2 karaktera!";
    }
};

class Sat
{
private:
    std::string ime;
    std::string model;
    int godinaProizvodnje;
    double trajanjeBaterije; // trajanje baterije u satima
public:
    Sat(const std::string &ime, const std::string &model, int godinaProizvodnje, double trajanjeBaterije)
        : model(model), godinaProizvodnje(godinaProizvodnje), trajanjeBaterije(trajanjeBaterije)
    {
        if (ime.size() < 2)
        {
            throw ImeNijeValidnoException();
        }
        this->ime = ime;
    }

    void IspisiInformacije()
    {
        std::cout << "Ime: " << ime << ", Model: " << model << ", Godina proizvodnje: " << godinaProizvodnje << ", Trajanje baterije: " << trajanjeBaterije << " sati" << std::endl;
    }
};

int main()
{
    try
    {
        Sat s("Q", "Model", 2022, 48);
        s.IspisiInformacije();
    }
    catch (const ImeNijeValidnoException &e)
    {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}