#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_IME 35
#define MAX_ADRESA 50

struct Ucenik
{
    char ime[MAX_IME];
    char adresa[MAX_ADRESA];
    int razred;
    int odeljenje;
};

int main()
{
    int razredN, odeljenjeM;

    printf("Unesite razred N: ");
    scanf("%d", &razredN);

    printf("Unesite odeljenje M: ");
    scanf("%d", &odeljenjeM);

    FILE *datoteka;
    datoteka = fopen("ucenik.txt", "r");

    if (datoteka == NULL)
    {
        printf("Greska pri otvaranju datoteke.\n");
        return 1;
    }

    struct Ucenik ucenik;
    while (fread(&ucenik, sizeof(struct Ucenik), 1, datoteka))
    {
        if (ucenik.razred == razredN && ucenik.odeljenje == odeljenjeM)
        {
            printf("Ime: %s\n", ucenik.ime);
            printf("Adresa: %s\n", ucenik.adresa);
            printf("Razred: %d\n", ucenik.razred);
            printf("Odeljenje: %d\n", ucenik.odeljenje);
            printf("-------------------------\n");
        }
    }

    fclose(datoteka);

    return 0;
}
