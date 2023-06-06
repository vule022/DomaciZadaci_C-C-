#include <iostream>
#include <string>

class Zivotinja
{
protected:
    std::string vrsta;
    std::string boja;
    int godine;
    double tezina;
    std::string habitat;

public:
    Zivotinja(std::string vrsta, std::string boja, int godine, double tezina, std::string habitat) : vrsta(vrsta), boja(boja), godine(godine), tezina(tezina), habitat(habitat) {}

    virtual void Info()
    {
        std::cout << "Vrsta zivotinje: " << vrsta << std::endl;
        std::cout << "Boja: " << boja << std::endl;
        std::cout << "Godine: " << godine << std::endl;
        std::cout << "Tezina: " << tezina << " kg" << std::endl;
        std::cout << "Habitat: " << habitat << std::endl;
    }
};

class DivljaZivotinja : public Zivotinja
{
private:
    std::string loviste;

public:
    DivljaZivotinja(std::string vrsta, std::string boja, int godine, double tezina, std::string habitat, std::string loviste) : Zivotinja(vrsta, boja, godine, tezina, habitat), loviste(loviste) {}

    void Info() override
    {
        Zivotinja::Info();
        std::cout << "Loviste: " << loviste << std::endl;
    }
};

int main()
{
    Zivotinja zebra("Zebra", "Crno-bela", 7, 200.5, "Savane Afrike");
    DivljaZivotinja vuk("Vuk", "Sivi", 5, 60, "Planine", "Durmitor");

    zebra.Info();
    std::cout << "-------------------" << std::endl;
    vuk.Info();

    return 0;
}