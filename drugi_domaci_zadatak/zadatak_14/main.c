#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int broj;

    srand(time(0));

    do
    {
        broj = rand() % 10;

        printf("Broj: %d\n", broj);
    } while (broj != 5);

    return 0;
}