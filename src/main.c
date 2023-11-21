#include <stdio.h>
#include <stdlib.h>
#include "./console/load.h"
#include "./console/console.h"

int main()
{
    Array arrPenyanyi = CreateArray();
    Array arrAlbum = CreateArray();
    Penyanyi albumPenyanyi = CreateEmptyPenyanyi();
    Album laguAlbum;
    Set lagu;
    Queue Q;
    Stackchar history;
    currentSong currentSong;
    currentPlaylist currentPlaylist;
    nextSong nextSong;
    ListPlaylist ListPL = initListPlaylist();
    PlaylistManager manager = createPlaylistManager();
    CreateEmptyCurrentPlaylist(&currentPlaylist);
    CreateEmptyCurrentSong(&currentSong);
    CreateEmptyStackChar(&history);
    CreateQueue(&Q);
    CreateArray(&arrPenyanyi);
    CreateArray(&arrAlbum);
    CreateEmptyAlbum(&laguAlbum);
    Word command, namafile;
    char *commandchar;
    boolean isInputValid = false;
    boolean startcheck = false;
    boolean isQuit = false;

    printf("Welcome to\n");
    printf("$$   $$  $$$$$$$  $$  $$  $$$$$$$  $$$   $$   $$$$     $$   $$  $$$$$$$  $$   $$  $$$$$$\n");
    printf("$$   $$  $$   $$   $  $   $$   $$  $$$$  $$  $$        $$   $$  $$   $$  $$   $$  $$    \n");
    printf("$$ $ $$  $$$$$$$    $$    $$$$$$$  $$ $  $$  $$  $$    $$ $ $$  $$$$$$$  $$   $$  $$$$$$\n");
    printf("$$ $ $$  $$   $$    $$    $$   $$  $$  $$$$  $$   $    $$ $ $$  $$   $$   $$ $$   $$    \n");
    printf(" $$ $$   $$   $$    $$    $$   $$  $$   $$$   $$$$      $$ $$   $$   $$     $     $$$$$$\n");
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
            start(&arrPenyanyi, &arrAlbum, &albumPenyanyi, &laguAlbum, &lagu);
            if (!IsEmpty(arrPenyanyi))
            {
                printf("File konfigurasi aplikasi berhasil dibaca. WayangWave berhasil dijalankan.\n");
                isInputValid = true;
                startcheck = true;
            }
            else
            {
                printf("File konfigurasi aplikasi gagal dibaca. Mohon ulangi proses.\n");
            }
        }
        else if (strCompare(commandchar, "LOAD") == 0)
        {
            akuisisiCommandWord(&namafile, currentWord, 2);
            if (namafile.Length > 0)
            {
                // loadsaved(namafile, &arrPenyanyi, &arrAlbum, &albumPenyanyi, &laguAlbum, &lagu, &currentSong, &Q, &History, manager);
                if (!IsEmpty(arrPenyanyi))
                {
                    printf("Save file berhasil dibaca. WayangWave berhasil dijalankan.\n");
                    isInputValid = true;
                    startcheck = true;
                }
                else
                {
                    printf("Save file tidak ditemukan. WayangWave tidak berhasil dijalankan.\n");
                }
            }
            else
            {
                printf("Save file tidak ditemukan. WayangWave tidak berhasil dijalankan.\n");
            }
        }
        else if (strCompare(commandchar, "HELP") == 0)
        {
            help(startcheck);
        }
        else
        {
            printf("Command tidak bisa dieksekusi. Mohon masukkan command yang sesuai.\n");
        }
    }

    while (!isQuit)
    {
        boolean invalidCommand = false;

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
        printf("12. PLAYLIST ADD SONG\n");
        printf("13. PLAYLIST ADD ALBUM\n");
        printf("14. PLAYLIST SWAP <id> <x> <y>\n");
        printf("15. PLAYLIST REMOVE <id> <n>\n");
        printf("16. PLAYLIST DELETE\n");
        printf("17. STATUS\n");
        printf("18. SAVE <filename>\n");
        printf("19. QUIT\n");
        printf("20. HELP\n");

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
        else if (strCompare(com, "LIST PLAYLIST") == 0)
        {
            listPlaylist(ListPL);
        }
        else if (strCompare(com, "PLAY SONG") == 0)
        {
            playSong(&Q, &history, arrPenyanyi, albumPenyanyi, laguAlbum, &currentSong);
        }
        else if (strCompare(com, "PLAY PLAYLIST") == 0)
        {
            playPlaylist(&Q, &history, &manager, ListPL, &currentSong, &currentPlaylist);
        }
        else if (strCompare(com, "QUEUE SONG") == 0)
        {
            queueSong(&Q, arrPenyanyi, albumPenyanyi, laguAlbum);
        }
        else if (strCompare(com, "QUEUE PLAYLIST") == 0)
        {
            queuePlaylist(&Q, &manager, ListPL);
        }
        else if (strCompare(com, "QUEUE SWAP") == 0)
        {
            Word xWord, yWord;
            akuisisiCommandWord(&xWord, currentWord, 3);
            akuisisiCommandWord(&yWord, currentWord, 4);

            if (strLength(wordToString(xWord)) == 0 || strLength(wordToString(yWord)) == 0)
            {
                invalidCommand = true;
            }
            else
            {
                int x = wordToInt(xWord);
                int y = wordToInt(yWord);

                queueSwap(&Q, x, y);
            }
        }
        else if (strCompare(com, "QUEUE REMOVE") == 0)
        {
            Word idWord;
            akuisisiCommandWord(&idWord, currentWord, 3);

            if (strLength(wordToString(idWord)) == 0)
            {
                invalidCommand = true;
            }
            else
            {
                int id = wordToInt(idWord);
                queueRemove(&Q, id);
            }
        }
        else if (strCompare(com, "QUEUE CLEAR") == 0)
        {
            queueClear(&Q);
        }
        else if (strCompare(com, "SONG NEXT") == 0)
        {
            songNext(&Q, &currentSong, &nextSong, &history, &currentPlaylist, &ListPL);
        }
        else if (strCompare(com, "SONG PREVIOUS") == 0)
        {
            songPrevious(&Q, &history, &currentSong);
        }
        else if (strCompare(com, "PLAYLIST CREATE") == 0)
        {
            CreatePlaylist(&ListPL, &manager);
        }
        else if (strCompare(com, "PLAYLIST ADD") == 0)
        {
            akuisisiCommandWord(&commandbefore, currentWord, 3);
            string comcom = wordToString(commandbefore);
            if (strCompare(comcom, "SONG") == 0)
            {
                PlaylistAddSong(&ListPL, &manager, arrPenyanyi, albumPenyanyi, laguAlbum);
            }
            else if (strCompare(comcom, "ALBUM") == 0)
            {
                PlaylistAddAlbum(&ListPL, &manager, arrPenyanyi, albumPenyanyi, laguAlbum);
            }
        }
        else if (strCompare(com, "PLAYLIST SWAP") == 0)
        {
            Word idid;
            akuisisiCommandWord(&idid, currentWord, 3);
            int IDPlaylist = wordToInt(idid);
            akuisisiCommandWord(&idid, currentWord, 4);
            int idxlagu1 = wordToInt(idid);
            akuisisiCommandWord(&idid, currentWord, 5);
            int idxlagu2 = wordToInt(idid);
            PlaylistSwap(&ListPL, &manager, IDPlaylist, idxlagu1, idxlagu2);
        }
        else if (strCompare(com, "PLAYLIST REMOVE") == 0)
        {
            Word iid;
            akuisisiCommandWord(&iid, currentWord, 3);
            int IDPlaylist = wordToInt(iid);
            akuisisiCommandWord(&iid, currentWord, 4);
            int idxLagu = wordToInt(iid);
            PlaylistRemove(&ListPL, &manager, IDPlaylist, idxLagu);
        }
        else if (strCompare(com, "PLAYLIST DELETE") == 0)
        {
            PlaylistDelete(&ListPL, &manager);
        }
        else if (strCompare(com, "STATUS") == 0)
        {
            status(&Q, currentSong, currentPlaylist);
        }
        else if (strCompare(com, "QUIT") == 0)
        {
            quit();
            isQuit = true;
        }
        else if (strCompare(com, "HELP") == 0)
        {
            help(startcheck);
        }
        else
        {
            invalidCommand = true;
        }

        if (invalidCommand)
        {
            printf("Command tidak bisa dieksekusi!\n");
        }
        // Delay(4);
    }

    return 0;
}