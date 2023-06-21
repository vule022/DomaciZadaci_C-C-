/*

Napisati program koji učitava podatke iz datoteke ucenik.txt čija je struktura (ime*35+,
adresa*50+, razred, odeljenje) data na slici ispod i prikazuje samo učenike razreda N i
odeljenja M. N i M unosimo u programu.

*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_IME_LENGTH 35
#define MAX_ADRESA_LENGTH 50

struct Ucenik
{
    char ime[MAX_IME_LENGTH + 1];
    char adresa[MAX_ADRESA_LENGTH + 1];
    int razred;
    char odeljenje;
};

void prikaziUcenike(const char *filename, int razred, char odeljenje)
{
    FILE *file = fopen(filename, "r");
    if (file == NULL)
    {
        printf("Greska pri otvaranju datoteke.\n");
        return;
    }

    struct Ucenik ucenik;

    while (fscanf(file, "%[^|]|%[^|]|%d | %c\n", ucenik.ime, ucenik.adresa, &ucenik.razred, &ucenik.odeljenje) == 4)
    {
        if (ucenik.razred == razred && ucenik.odeljenje == odeljenje)
        {
            printf("Ime: %s\n", ucenik.ime);
            printf("Adresa: %s\n", ucenik.adresa);
            printf("Razred: %d\n", ucenik.razred);
            printf("Odeljenje: %c\n", ucenik.odeljenje);
            printf("\n");
        }
    }

    fclose(file);
}

int main()
{
    int razred;
    char odeljenje;

    printf("Unesite razred: ");
    scanf("%d", &razred);

    printf("Unesite odeljenje: ");
    scanf(" %c", &odeljenje);

    prikaziUcenike("ucenik.txt", razred, odeljenje);

    return 0;
}
