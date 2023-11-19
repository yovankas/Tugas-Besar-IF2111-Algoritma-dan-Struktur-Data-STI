#include <stdio.h>
#include <stdlib.h>
#include "load.h"
#include "console.h"

int main()
{
    Array arrPenyanyi = CreateArray();
    Array arrAlbum = CreateArray();
    Penyanyi albumPenyanyi = CreateEmptyPenyanyi();
    Album laguAlbum;
    Set lagu;
    CreateArray(&arrPenyanyi);
    CreateArray(&arrAlbum);
    CreateEmptyAlbum(&laguAlbum);
    Word command, namafile;
    char* commandchar;
    boolean isInputValid= false;

    while (!isInputValid)
    {
        printf("Pesan Selamat Datang (kalo rajin dibikin)\n");
        printf("ENTER COMMAND: ");
        startInputWord();
        akuisisiCommandWord(&command, currentWord, 1);
        commandchar = wordToString(command);
        
        if (strCompare(commandchar, "START") == 0)
        {
            printf("manggil start\n");
            isInputValid = true;
        }
        else if (strCompare(commandchar, "LOAD") == 0)
        {
            akuisisiCommandWord(&namafile, currentWord, 2);
            if (namafile.Length > 0)
            {
                load(wordToString(namafile), &arrPenyanyi, &arrAlbum, &albumPenyanyi, &laguAlbum, &lagu);
                if(!IsEmpty(arrPenyanyi))
                {
                    printf("Saved file berhasil dibaca. WayangWave berhasil dijalankan\n");
                    isInputValid = true;
                }
                else
                {
                    printf("Saved file tidak berhasil dibaca. WayangWave gagal dijalankan\n");
                }
            }
            else
            {
                printf("Saved file tidak berhasil dibaca. WayangWave gagal dijalankan\n");
            }
        }
        else 
        {
            printf("manggil command invalid (?)\n");
        }

        
    }

    return 0;
}