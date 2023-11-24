#include "load.h"

void loaddefault(char *namafile, Array *arrPenyanyi, Array *arrAlbum, Penyanyi *albumPenyanyi, Album *laguAlbum, Set *lagu)
{
    STARTWORD(concat("data/", namafile));

    if (!EOP)
    {
        int countPenyanyi = wordToInt(ambilKataKe(currentWord, 1));

        // Bikin list buat semua penyanyi
        // printf("Count Penyanyi: %d\n", countPenyanyi);
        for (int i = 0; i < countPenyanyi; i++)
        {
            ADVWORD();
            // printf("Indeks: %d\n", i);
            int countAlbum = wordToInt(ambilKataKe(currentWord, 1));
            char *namaPenyanyi = wordToString(ambilMulaiKataKe(currentWord, 2));
            SetEl(arrPenyanyi, i, namaPenyanyi);

            // printf("Penyanyi: %s\n", namaPenyanyi);

            // Bikin map buat semua album dalam satu penyanyi
            for (int j = 0; j < countAlbum; j++)
            {
                ADVWORD();
                int countLagu = wordToInt(ambilKataKe(currentWord, 1));
                char *namaAlbum = wordToString(ambilMulaiKataKe(currentWord, 2));
                SetEl(arrAlbum, j, namaAlbum);

                // printf("Album: %s\n", namaAlbum);
                //  Bikin set buat semua lagu dalam satu album
                // printf("Jumlah Lagu: ");
                // printf("%d\n", countLagu);
                CreateEmptySet(lagu);
                for (int k = 0; k < countLagu; k++)
                {
                    ADVWORD();
                    char *namaLagu = wordToString(currentWord);
                    // printf("Lagu: %s\n", namaLagu);
                    InsertSet(lagu, namaLagu);
                }
                InsertInAlbum(laguAlbum, namaAlbum, *lagu);
            }
            InsertInPenyanyi(albumPenyanyi, namaPenyanyi, *arrAlbum);
        }
        ADVWORD();
    }
}


void loadsaved(char *namafile, Array *arrPenyanyi, Array *arrAlbum, Penyanyi *albumPenyanyi, Album *laguAlbum, Set *lagu, currentSong *currentSong, Queue *Q, Stackchar *History, PlaylistManager *manager, ListPlaylist *listPL)
{
    STARTWORD(concat("data/", namafile));

    if (!EOP)
    {
        // printWord(currentWord);
        int countPenyanyi = wordToInt(ambilKataKe(currentWord, 1));

        // Bikin list buat semua penyanyi
        // printf("Count Penyanyi: %d\n", countPenyanyi);
        for (int i = 0; i < countPenyanyi; i++)
        {
            ADVWORD();
            // printf("Indeks: %d\n", i);
            int countAlbum = wordToInt(ambilKataKe(currentWord, 1));
            char *namaPenyanyi = wordToString(ambilMulaiKataKe(currentWord, 2));
            SetEl(arrPenyanyi, i, namaPenyanyi);

            // printf("Penyanyi: %s\n", namaPenyanyi);

            // Bikin map buat semua album dalam satu penyanyi
            for (int j = 0; j < countAlbum; j++)
            {
                ADVWORD();
                int countLagu = wordToInt(ambilKataKe(currentWord, 1));
                char *namaAlbum = wordToString(ambilMulaiKataKe(currentWord, 2));
                SetEl(arrAlbum, j, namaAlbum);

                // printf("Album: %s\n", namaAlbum);
                //  Bikin set buat semua lagu dalam satu album
                // printf("Jumlah Lagu: ");
                // printf("%d\n", countLagu);
                CreateEmptySet(lagu);
                for (int k = 0; k < countLagu; k++)
                {
                    ADVWORD();
                    char *namaLagu = wordToString(currentWord);
                    // printf("Lagu: %s\n", namaLagu);
                    InsertSet(lagu, namaLagu);
                }
                InsertInAlbum(laguAlbum, namaAlbum, *lagu);
            }
            InsertInPenyanyi(albumPenyanyi, namaPenyanyi, *arrAlbum);
        }
        ADVWORD();
        // Membaca Current Song atau Now Playing
        string Now = wordToString(sebelumSemicolon(currentWord, 1));
        currentSong->artist = Now;
        Now = wordToString(sebelumSemicolon(currentWord, 2));
        currentSong->album = Now;
        Now = wordToString(sebelumSemicolon(currentWord, 3));
        currentSong->song = Now;
        ADVWORD();
        // printf("%s", currentSong.artist);
        // printf("\n%s", currentSong.album);
        // printf("\n%s", currentSong.song);

        // Membaca Queue
        int countQueue = wordToInt(ambilKataKe(currentWord, 1));
        for (int i = 0; i < countQueue; i++)
        {
            ADVWORD();
            ElTypeQueue ElQueue;
            Now = wordToString(sebelumSemicolon(currentWord, 1));
            ElQueue.artist = Now;
            Now = wordToString(sebelumSemicolon(currentWord, 2));
            ElQueue.album = Now;
            Now = wordToString(sebelumSemicolon(currentWord, 3));
            ElQueue.song = Now;
            enqueue(Q, ElQueue);
        }
        ADVWORD();
        // displayQueue(*Q);

        // Membaca History
        Stackchar Temp;
        CreateEmptyStackChar(&Temp);
        int countStack = wordToInt(ambilKataKe(currentWord, 1));
        for (int i = 0; i < countStack; i++)
        {
            ADVWORD();
            infotypeStackchar HistStack;
            Now = wordToString(sebelumSemicolon(currentWord, 1));
            HistStack.artist = Now;
            Now = wordToString(sebelumSemicolon(currentWord, 2));
            HistStack.album = Now;
            Now = wordToString(sebelumSemicolon(currentWord, 3));
            HistStack.song = Now;
            PushStackChar(&Temp, HistStack);
        }
        CopyStackChar(Temp, History);
        // printStackchar(*History);
        ADVWORD();

        int countPlaylist = wordToInt(ambilKataKe(currentWord, 1));

        for (int i = 0; i < countPlaylist; i++)
        {
            ADVWORD();
            int countSong = wordToInt(ambilKataKe(currentWord, 1));
            char *playlistTitle = wordToString(ambilMulaiKataKe(currentWord, 2));

            addElement(listPL, playlistTitle);

            Playlist playlist = createPlaylist();

            for (int j = 0; j < countSong; j++)
            {
                ADVWORD();
                string artist = wordToString(sebelumSemicolon(currentWord, 1));
                string album = wordToString(sebelumSemicolon(currentWord, 2));
                string song = wordToString(sebelumSemicolon(currentWord, 3));
                addSong(&playlist, song, artist, album);
            }

            addPlaylist(manager, &playlist);
        }

        ADVWORD();
    }
}