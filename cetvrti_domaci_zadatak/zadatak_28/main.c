/**
 *
 * Napisati funkciju koja uklanja podstring od s počev od pozicije p na dužini d i vraća
pokazivač na s. Implementirati funkciju isključivo korišćenjem pokazivača.
 *
*/

#include <stdio.h>

char *ukloniPodstring(char *s, int p, int d)
{
    char *dest = s + p;

    while (*(dest + d) != '\0')
    {
        *dest = *(dest + d);
        dest++;
    }
    *dest = '\0';

    return s;
}

int main()
{
    char s[100];
    int p, d;

    printf("Unesite string: ");
    fgets(s, sizeof(s), stdin);

    printf("Unesite poziciju p: ");
    scanf("%d", &p);

    printf("Unesite duzinu d: ");
    scanf("%d", &d);

    char *rezultat = ukloniPodstring(s, p, d);

    printf("Rezultat: %s\n", rezultat);

    return 0;
}
