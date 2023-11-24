#include "word.h"
#include "../mesin/mesinkata.h"
#include <stdio.h>

int main() {
    Word w = CreateWord();
    char *string;
    int integer;

    // Input untuk kata pertama
    printf("\nMasukkan string: \n");
    startInputWord();
    printf("AKUISISI kata ke-1\n");
    akuisisiCommandWord(&w, currentWord, 1);

    // Periksa apakah kata tersebut sama dengan "hehe"
    if (IsEQWord(w, StringToWord("hehe")))
    {
        printf("Sama\n");
    }

    // Konversi kata ke dalam bentuk string
    printf("\nKonversi ke string\n");
    string = WordToString(w);
    printf("Ini tipe string: %s\n", string);

    // Masukkan integer positif
    printf("\nMasukkan integer positif: \n");
    startInputWord();
    integer = WordToInt(currentWord);
    printf("Ini tipe int: %d\n", integer);

    // Masukkan integer negatif
    printf("\nMasukkan integer negatif: \n");
    startInputWord();
    integer = WordToInt(currentWord);
    printf("Ini tipe int: %d\n", integer);

    // Periksa fungsi stringToWord
    printf("\nCEK STRING TO WORD (buat variabel Word iniW dan masukkan string)\n");
    Word iniW = StringToWord("HALOO AKU DARI STRING");
    printf("INI PRINT WORD:\n");
    PrintWord(iniW);
    printf("\n");

    // Periksa fungsi CopyWord
    printf("\nCEK COPY word iniw tadi ke iniW2\n");
    Word iniW2;
    CopyWord(&iniW2, iniW);
    printf("INI PRINT WORD:\n");
    PrintWord(iniW2);
    printf("\n");

    // Periksa fungsi IsEQWord
    printf("\nCEK IsEQWord\n");
    if (IsEQWord(iniW, iniW2))
    {
        printf("IniW dan IniW2 samaa\n");
    }
    else
    {
        printf("Yahh kita berbeda...\n");
    }

    // Periksa fungsi lowerWord
    printf("\nCEK lowerWord");
    printf("\nMasukkan kata: ");
    startInputWord();
    printf("Sebelum lower: ");
    PrintWord(currentWord);
    printf("\nSetelah lower: ");
    PrintWord(lowerWord(currentWord));
    printf("\nSetelah upper: ");
    PrintWord(upperWord(currentWord));
    printf("\n");

    return 0;
}