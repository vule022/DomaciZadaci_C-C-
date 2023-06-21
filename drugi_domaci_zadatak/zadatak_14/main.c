/*

14.Napisati program koji slučajno bira cele brojeve iz intervala 0 - 9,
prikazuje izabrani broj i prekida biranje brojeva kada je izabran broj
5. Koristiti funkciju rand() iz biblioteke stdlib.h.

*/

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