#include <stdio.h>
#include <stdlib.h>

int *nadjiProsteBrojeve(int N, int *brojProstih)
{
    int *prostiBrojevi = NULL;
    int *isPrime = (int *)malloc(N * sizeof(int));

    for (int i = 0; i < N; i++)
    {
        isPrime[i] = 1;
    }

    for (int i = 2; i < N; i++)
    {
        if (isPrime[i])
        {
            for (int j = i * 2; j < N; j += i)
            {
                isPrime[j] = 0;
            }
        }
    }

    *brojProstih = 0;
    for (int i = 2; i < N; i++)
    {
        if (isPrime[i])
        {
            (*brojProstih)++;
        }
    }
    prostiBrojevi = (int *)malloc((*brojProstih) * sizeof(int));

    int index = 0;
    for (int i = 2; i < N; i++)
    {
        if (isPrime[i])
        {
            prostiBrojevi[index] = i;
            index++;
        }
    }

    free(isPrime);

    return prostiBrojevi;
}

int main()
{
    int N;
    printf("Unesite broj N: ");
    scanf("%d", &N);

    int brojProstih;
    int *prostiBrojevi = nadjiProsteBrojeve(N, &brojProstih);

    printf("Prosti brojevi manji od %d:\n", N);
    for (int i = 0; i < brojProstih; i++)
    {
        printf("%d ", prostiBrojevi[i]);
    }
    printf("\n");
    printf("Broj prostih brojeva: %d\n", brojProstih);

    free(prostiBrojevi);

    return 0;
}
