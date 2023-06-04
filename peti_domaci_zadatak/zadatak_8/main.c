#include <stdio.h>
#include <stdlib.h>

struct Student
{
    char ime[10];
    char prezime[10];
    char smer;
    double prosek;
};

void ucitajStudenta(struct Student *student)
{
    printf("Unesite ime studenta: ");
    scanf("%s", student->ime);

    printf("Unesite prezime studenta: ");
    scanf("%s", student->prezime);

    printf("Unesite smer studenta: ");
    scanf(" %c", &(student->smer));

    printf("Unesite prosek studenta: ");
    scanf("%lf", &(student->prosek));
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
    struct Student nizStudenata[5];
    int i;
    double najveciProsek = 0.0;
    int indeksNajveceg = 0;

    for (i = 0; i < 5; i++)
    {
        printf("Unos podataka za studenta %d:\n", i + 1);
        ucitajStudenta(&nizStudenata[i]);
        printf("\n");
    }

    for (i = 0; i < 5; i++)
    {
        printf("Podaci o studentu %d:\n", i + 1);
        ispisiStudenta(&nizStudenata[i]);
        printf("\n");

        if (nizStudenata[i].prosek > najveciProsek)
        {
            najveciProsek = nizStudenata[i].prosek;
            indeksNajveceg = i;
        }
    }

    printf("Student s najvećim prosekom:\n");
    ispisiStudenta(&nizStudenata[indeksNajveceg]);

    return 0;
}
