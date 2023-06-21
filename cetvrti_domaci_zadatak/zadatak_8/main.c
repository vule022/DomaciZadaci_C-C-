/*

Napisati program koji formira niz od n elemenata i određuje minimalni element niza kao i
njegovu poziciju u nizu. Funkciju koja računa minimalni element niza i indeks implementirati
kao:
void MinIndex(int *niz, int n, int *minElem, int *minIndex); gde je n broj elemenata.

*/

#include <stdio.h>

void MinIndex(int *niz, int n, int *minElem, int *minIndex)
{
    *minElem = niz[0];
    *minIndex = 0;

    for (int i = 1; i < n; i++)
    {
        if (niz[i] < *minElem)
        {
            *minElem = niz[i];
            *minIndex = i;
        }
    }
}

int main()
{
    int n = 0;
    printf("Unesite broj elemenata niza: ");
    scanf("%d", &n);

    int niz[n];
    printf("Unesite elemente niza:\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &niz[i]);
    }

    int minElem, minIndex;
    MinIndex(niz, n, &minElem, &minIndex);

    printf("Minimalni element niza: %d\n", minElem);
    printf("Pozicija minimalnog elementa: %d\n", minIndex);

    return 0;
}
