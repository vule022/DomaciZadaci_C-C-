/*

23. Cena čokolade na tržistu svakim danom raste za 2%. Korisnik unosi početnu
cenu čokolade i broj dana. Na osnovu unetih informacija treba izračunati
koliko će biti cena čokolade za 20 dana. (Rast cene na dnevnom nivou je
jednak ceni proizvoda * 0.02).

*/

#include <stdio.h>

int main()
{
    double pocetnaCena;
    int brojDana;

    printf("Unesite pocetnu cenu cokolade: ");
    scanf("%lf", &pocetnaCena);

    printf("Unesite broj dana: ");
    scanf("%d", &brojDana);

    double cenaCokolade = pocetnaCena;
    for (int i = 1; i <= brojDana; i++)
    {
        cenaCokolade += cenaCokolade * 0.02;
    }

    printf("Cena cokolade za %d dana: %.2lf\n", brojDana, cenaCokolade);

    return 0;
}
