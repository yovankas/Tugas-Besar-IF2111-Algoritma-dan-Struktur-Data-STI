#include "word.h"
#include "../mesin/mesinkata.h"

int main()
{
    Word w = CreateWord();
    char *string;
    int integer;

    printf("\nMasukan string: \n");
    startInputWord();
    printf("AKUISISI kata ke-1\n");
    akuisisiCommandWord(&w, currentWord, 1);

    if (stringEQWord(w, "hehe"))
    {
        printf("Sama\n");
    }

    printf("\nConvert to string\n");
    string = wordToString(w);
    printf("Ini bertipe string lo ya : %s\n", string);

    printf("\nMasukan integer positif: \n");
    startInputWord();
    integer = wordToInt(currentWord);
    printf("Ini bertipe int lo ya : %d\n", integer);

    printf("\nMasukan integer negatif: \n");
    startInputWord();
    integer = wordToInt(currentWord);
    printf("Ini bertipe int lo ya : %d\n", integer);

    printf("\nCEK STRING TO WORD (buat variable Word iniW dan masukan string)\n");
    Word iniW = stringToWord("HALOO AKU DARI STRING");
    printf("INI PRINT WORD :\n");
    printWord(iniW);
    printf("\n");

    printf("\nCEK COPY word iniw tadi ke iniW2\n");
    Word iniW2;
    CopyWord(&iniW2, iniW);
    printf("INI PRINT WORD :\n");
    printWord(iniW2);
    printf("\n");

    printf("\nCEK IsEQWord\n");
    if (IsEQWord(iniW, iniW2))
    {
        printf("IniW dan IniW2 samaa\n");
    }
    else
    {
        printf("Yahh kita berbeda...\n");
    }

    printf("\nCEK lowerWord");
    printf("\nMasukan kata: ");
    startInputWord();
    printf("Sebelum lower: ");
    printWord(currentWord);
    printf("\nSetelah lower: ");
    printWord(lowerWord(currentWord));
    printf("\nSetelah upper: ");
    printWord(upperWord(currentWord));
    printf("\n");

    return 0;
}