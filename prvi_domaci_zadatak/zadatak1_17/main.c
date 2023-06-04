#include <stdio.h>
#include <math.h>
#define PI 3.14159

int main()
{
    float radius;
    float obim, povrsina;

    printf("Unesite vrednost radijusa kruga: ");
    scanf("%f", &radius);

    obim = 2 * radius * PI;
    povrsina = radius * radius * PI;

    printf("Obim kruga: %.2f\n", obim);
    printf("Povrsina kruga: %.2f\n", povrsina);

    return 0;
}