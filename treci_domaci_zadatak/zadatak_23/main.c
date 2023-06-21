/*

Napisati program koji umeće string s2 u string s1 počev od pozicije p. Korisnik unosi p.

*/

#include <stdio.h>
#include <string.h>

#define MAX_LENGTH 100

void umetniString(char s1[], char s2[], int p)
{
    int len1 = strlen(s1);
    int len2 = strlen(s2);

    if (p < 0 || p > len1)
    {
        printf("Pogresna pozicija!\n");
        return;
    }

    for (int i = len1; i >= p; i--)
    {
        s1[i + len2] = s1[i];
    }

    for (int i = 0; i < len2; i++)
    {
        s1[p + i] = s2[i];
    }
}

int main()
{
    char s1[MAX_LENGTH];
    char s2[MAX_LENGTH];
    int p;

    printf("Unesite string s1: ");
    fgets(s1, sizeof(s1), stdin);

    printf("Unesite string s2: ");
    fgets(s2, sizeof(s2), stdin);

    printf("Unesite poziciju p: ");
    scanf("%d", &p);

    s1[strcspn(s1, "\n")] = '\0';
    s2[strcspn(s2, "\n")] = '\0';

    umetniString(s1, s2, p);

    printf("Rezultat: %s\n", s1);

    return 0;
}
