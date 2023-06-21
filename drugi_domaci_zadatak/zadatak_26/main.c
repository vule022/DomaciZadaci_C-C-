/*

26.Napisati funkciju koja štampa ceobroj N u binarnom zapisu.

*/

#include <stdio.h>

void printBinary(int N)
{
    if (N == 0)
    {
        printf("0");
        return;
    }

    if (N > 0)
    {
        printBinary(N / 2);
        printf("%d", N % 2);
    }
}

int main()
{
    int broj;

    printf("Unesite ceo broj: ");
    scanf("%d", &broj);

    printf("Binarni zapis broja %d: ", broj);
    printBinary(broj);
    printf("\n");

    return 0;
}
