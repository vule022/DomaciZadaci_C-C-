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
    int n;
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
