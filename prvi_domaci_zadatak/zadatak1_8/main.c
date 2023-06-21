/*

8. Ako se unosi stranica jednakostraničnog trougla koji je osnova prave
trostrane prizme, i H visina te prizme. Napisati program koji prikazuje
sledeću poruku.

B = ( a^2 * sqrt(3))/4 = ( __^2 * __ )/4=( __ * __ ) = __ /4= __cm P = 2*B
+ M = 2* __ + __ = ___cm

*/

#include <stdio.h>
#include <math.h>

int main()
{
       float a, H, B, P;

       printf("Unesite duzinu stranice trougla \n");
       scanf("%f", &a);

       printf("Unesite visinu prizme \n");
       scanf("%f", &H);

       B = (a * a * sqrt(3)) / 4;

       P = 2 * B + a * H;

       printf("B = (%.2f^2 * sqrt(3))/4 = (%.2f^2 * %.2f)/4 = %.2f * %.2f = %.2f / 4 = %.2f cm^2\n",
              a, a, sqrt(3), a * a * sqrt(3), 4, B, B);
       printf("P = 2 * B + M = 2 * %.2f + %.2f * %.2f = %.2f + %.2f = %.2f cm\n",
              B, a, H, 2 * B, a * H, P);

       return 0;
}