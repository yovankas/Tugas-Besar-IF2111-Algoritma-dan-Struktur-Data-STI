#include "string.h"
#include <stdio.h>

int main()
{
    char kata1[100], kata2[100];
    printf("Masukan kata 1: ");
    scanf("%s", kata1);
    printf("Masukan kata 2: ");
    scanf("%s", kata2);

    // printf("\nPanjang kata ke-1 : %d\n", stringLength(kata1));
    // printf("Panjang kata ke-2 : %d\n", stringLength(kata2));

    printf("\nHasil CONCAT %s dengan %s : ", kata1, kata2);
    printf("%s\n", concat(kata1, kata2));

    string kata3 = copyString(kata2);
    printf("\nHasil copy kata2 ke kata3: ");
    printf("%s\n", kata3);

    printf("\nKata 3 dan 2 sama gak:\n");
    kata2[0] = 'a';
    printf("Kata2: %s\n", kata2);
    printf("Kata3: %s\n", kata3);

    char brot = 'a';
    if (isCharInString(kata3, brot))
    {
        printf("ada");
    }
    else
    {
        printf("gaada");
    }
    return 0;
}