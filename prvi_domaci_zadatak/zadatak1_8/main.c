#include <stdio.h>
#include <math.h>

int main()
{
    float a, H, B, P;

    printf("Unesite duzinu stranice trougla");
    scanf("%f", &a);

    printf("Unesite visinu prizme");
    scanf("%f", &H);

    B = (a * a * sqrt(3)) / 4;

    P = 2 * B + a * H;

    printf("B = (%.2f^2 * sqrt(3))/4 = (%.2f^2 * %.2f)/4 = %.2f * %.2f = %.2f / 4 = %.2f cm^2\n",
           a, a, sqrt(3), a * a * sqrt(3), 4, B, B);
    printf("P = 2 * B + M = 2 * %.2f + %.2f * %.2f = %.2f + %.2f = %.2f cm\n",
           B, a, H, 2 * B, a * H, P);

    return 0;
}