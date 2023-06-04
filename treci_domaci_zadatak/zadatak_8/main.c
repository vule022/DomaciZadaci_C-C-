#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int niz[20];
    int i;
    int maksimalni_parni = -1;
    int minimalni_neparni = 101;

    srand(time(0));

    for (i = 0; i < 20; i++)
    {
        niz[i] = rand() % 101;

        if (niz[i] % 2 == 0 && niz[i] > maksimalni_parni)
        {
            maksimalni_parni = niz[i];
        }

        if (niz[i] % 2 != 0 && niz[i] < minimalni_neparni)
        {
            minimalni_neparni = niz[i];
        }
    }

    printf("Generisani niz: ");
    for (i = 0; i < 20; i++)
    {
        printf("%d ", niz[i]);
    }
    printf("\n");

    printf("Maksimalni parni element: %d\n", maksimalni_parni);
    printf("Minimalni neparni element: %d\n", minimalni_neparni);

    return 0;
}
