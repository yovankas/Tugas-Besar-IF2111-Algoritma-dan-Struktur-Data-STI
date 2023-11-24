#include "mesinkata.h"
#include <stdio.h>

int main()
{
    Word satu, dua;
    printf("Input 2 kata: ");
    startInputWord();
    printf("Panjang total 2 kata : %d\n", currentWord.Length);
    akuisisiCommandWord(&satu, currentWord, 1);
    akuisisiCommandWord(&dua, currentWord, 2);
    printWord(satu);
    printf("\nPanjang kata pertama: %d\n", satu.Length);
    printWord(dua);
    printf("\nPanjang kata kedua: %d\n", dua.Length);

    printf("\nCEK FILE JALAN GA\n");
    STARTWORD("../data/default.txt");
    printWord(currentWord);
    while (!EOP)
    {
        ADVWORD();
        printf("\nPrint Current Word\n");
        printWord(currentWord);
    }

    return 0;
}