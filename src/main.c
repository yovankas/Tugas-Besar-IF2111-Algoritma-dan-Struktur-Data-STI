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
    Queue Q;
    CreateQueue(&Q);
    CreateArray(&arrPenyanyi);
    CreateArray(&arrAlbum);
    CreateEmptyAlbum(&laguAlbum);
    Word command, namafile;
    char* commandchar;
    boolean isInputValid= false;
    boolean startcheck = false;
    boolean isQuit = false;

    printf("Pesan Selamat Datang (kalo rajin dibikin)\n");
    printf("=========================================================[ Main Menu WayangWave ]=========================================================\n");
    printf("1. START\n");
    printf("2. LOAD <namafile>\n");
    printf("3. HELP\n");

    while (!isInputValid)
    {
        printf("ENTER COMMAND: ");
        startInputWord();
        akuisisiCommandWord(&command, currentWord, 1);
        commandchar = wordToString(command);
        
        if (strCompare(commandchar, "START") == 0)
        {
            printf("manggil start\n");
            isInputValid = true;
            startcheck = true;
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
                    startcheck = true;
                }
                else
                {
                    printf("Saved file tidak berhasil dibaca. WayangWave gagal dijalankan.\n");
                }
            }
            else
            {
                printf("Saved file tidak berhasil dibaca. WayangWave gagal dijalankan.\n");
            }
        }
        else if (strCompare(commandchar, "HELP") == 0)
        {
            help(startcheck);
        }
        else 
        {
            printf("Command tidak dikenali. Masukin yg bner lha!!\n");

        }
    }

    while (!isQuit)
    {
        printf("\n=========================================================[ Main Menu WayangWave ]=========================================================\n");
        printf("1. LIST DEFAULT\n");
        printf("2. LIST PLAYLIST\n");
        printf("3. PLAY SONG\n");
        printf("4. PLAY PLAYLIST\n");
        printf("5. QUEUE SONG\n");
        printf("6. QUEUE PLAYLIST\n");
        printf("6. QUEUE SWAP <x> <y>\n");
        printf("7. QUEUE REMOVE <id>\n");
        printf("8. QUEUE CLEAR\n");
        printf("9. SONG NEXT\n");
        printf("10. SONG PREVIOUS\n");
        printf("11. PLAYLIST CREATE\n");
        printf("12. PLAYLIST ADD\n");
        printf("13. PLAYLIST SWAP <id> <x> <y>\n");
        printf("14. PLAYLIST REMOVE <id> <n>\n");
        printf("15. PLAYLIST DELETE\n");
        printf("16. STATUS\n");
        printf("17. SAVE <filename>\n");
        printf("18. QUIT\n");
        printf("19. HELP\n");

        printf("\nENTER COMMAND: ");
        startInputWord();
        Word commandbefore;
        akuisisiCommandWord(&command, currentWord, 1);
        akuisisiCommandWord(&commandbefore, currentWord, 2);
        string com, comcharbefore, spasi = " ";
        com = wordToString(command);
        comcharbefore = wordToString(commandbefore);
        if (strCompare(comcharbefore, "") != 0)
        {
            com = concat(com, spasi);
            com = concat(com, comcharbefore);
        }
        command = stringToWord(com);
        
        if (strCompare(com, "LIST DEFAULT") == 0)
        {
            listDefault(arrPenyanyi, albumPenyanyi, laguAlbum);
        }
        else if(strCompare(com, "LIST PLAYLIST") == 0)
        {
            printf("manggil list playlist\n");
        }
        else if(strCompare(com, "PLAY SONG") == 0)
        {
            printf("manggil play song\n");
        }
        else if(strCompare(com, "PLAY PLAYLIST") == 0)
        {
            printf("manggil play playlist\n");
        }
        else if(strCompare(com, "QUEUE SONG") == 0)
        {
            queueSong(&Q, arrPenyanyi, albumPenyanyi, laguAlbum);
            displayQueue(Q);
        }
        else if(strCompare(com, "QUEUE SWAP") == 0)
        {
            printf("manggil queue swap\n");
        }
        else if(strCompare(com, "QUEUE REMOVE") == 0)
        {
            printf("manggil queue remove\n");
        }
        else if(strCompare(com, "QUEUE CLEAR") == 0)
        {
            printf("manggil queue clear\n");
        }
        else if(strCompare(com, "SONG NEXT") == 0)
        {
            printf("manggil song next\n");
        }
        else if(strCompare(com, "SONG PREVIOUS") == 0)
        {
            printf("manggil song previous\n");
        }
        else if(strCompare(com, "PLAYLIST CREATE") == 0)
        {
            printf("manggil playlist create\n");
        }
        else if(strCompare(com, "PLAYLIST SWAP") == 0)
        {
            printf("manggil playlist swap\n");
        }
        else if(strCompare(com, "PLAYLIST REMOVE") == 0)
        {
            printf("manggil playlist remove\n");
        }
        else if(strCompare(com, "PLAYLIST DELETE") == 0)
        {
            printf("manggil playlist delete\n");
        }
        else if(strCompare(com, "STATUS") == 0)
        {
            printf("manggil status\n");
        }
        else if(strCompare(com, "QUIT") == 0)
        {
            quit();
            isQuit = true;
        }
        else if(strCompare(com, "HELP") == 0)
        {
            help(startcheck);
        }
        Delay(4);
    }

    return 0;
}