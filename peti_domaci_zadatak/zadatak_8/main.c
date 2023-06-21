/*

Data je struktura
struct Student {
char ime[10];
char prezime[10];

char smer;
double prosek;
}
a) Napisati funkciju koja učitava sa standardnog ulaza podatke o studentu.
b) Napisati funkciju koja ispisuje podatke o studentu na standardni izlaz.
U glavnom programu ucitati niz od 5 studenata i ispisati podatke o studentu sa najvecim
prosekom.

*/

#include <stdio.h>

struct Student
{
    char ime[10];
    char prezime[10];
    char smer;
    double prosek;
};

void ucitajStudenta(struct Student *student)
{
    printf("Unesite ime: ");
    scanf("%s", student->ime);

    printf("Unesite prezime: ");
    scanf("%s", student->prezime);

    printf("Unesite smer: ");
    scanf(" %c", &student->smer);

    printf("Unesite prosek: ");
    scanf("%lf", &student->prosek);
}

void ispisiStudenta(const struct Student *student)
{
    printf("Ime: %s\n", student->ime);
    printf("Prezime: %s\n", student->prezime);
    printf("Smer: %c\n", student->smer);
    printf("Prosek: %.2lf\n", student->prosek);
}

int main()
{
    struct Student studenti[5];
    double maxProsek = 0.0;
    int indexNajveciProsek = 0;

    for (int i = 0; i < 5; i++)
    {
        printf("Unos podataka za studenta %d:\n", i + 1);
        ucitajStudenta(&studenti[i]);
        printf("\n");
    }

    printf("Podaci o studentu sa najvecim prosekom:\n");
    for (int i = 0; i < 5; i++)
    {
        if (studenti[i].prosek > maxProsek)
        {
            maxProsek = studenti[i].prosek;
            indexNajveciProsek = i;
        }
    }
    ispisiStudenta(&studenti[indexNajveciProsek]);

    return 0;
}