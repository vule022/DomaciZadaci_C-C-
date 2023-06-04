#include <stdio.h>

int main()
{
    int mesec;

    printf("Unesite broj meseca -> jan = 1 dec = 12): ");
    scanf("%d", &mesec);

    switch (mesec)
    {
    case 2:
    {
        int godina;
        printf("Unesite godinu: ");
        scanf("%d", &godina);

        if ((godina % 4 == 0 && godina % 100 != 0) || godina % 400 == 0)
        {
            printf("Broj dana u februaru: 29\n");
        }
        else
        {
            printf("Broj dana u februaru: 28\n");
        }
        break;
    }
    case 4:
    case 6:
    case 9:
    case 11:
        printf("Broj dana u mesecu: 30\n");
        break;
    default:
        printf("Broj dana u mesecu: 31\n");
        break;
    }

    return 0;
}