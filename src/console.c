#include "console.h"

void quit()
{
    printf("Apakah kamu ingin menyimpan data sesi sekarang? ");
    startInputWord();
    Word command;
    akuisisiCommandWord(&command, currentWord, 1);
    char* confirm;
    confirm = wordToString(command);
    if (strcmp(confirm, "Y") == 0)
    {
        printf("manggil save disini\n");
        //save(); // BELUM ADA FUNCTIONNYA

    }
    printf("Kamu keluar dari WayangWave.\n");
    printf("Dadah ^_^/\n");
}

void help(boolean startcheck)
{
    if(!startcheck)
    {
        printf("=========================================================[ Menu Help WayangWave ]=========================================================\n");
        printf("1. START -> Untuk masuk sesi baru\n");
        printf("2. LOAD -> Untuk memulai sesi berdasarkan file konfigurasi\n");
    }
    else 
    {
        printf("=========================================================[ Menu Help WayangWave ]=========================================================\n");
        printf("1. LIST DEFAULT -> Untuk menampilkan list penyanyi, list album dari seorang penyanyi, serta list lagu dari suatu album\n");
        printf("2. LIST PLAYLIST -> Untuk menampilkan playlist yang ada pada pengguna\n");
        printf("3. PLAY SONG -> Untuk memainkan lagu berdasarkan nama penyanyi, nama album, dan ID lagu\n");
        printf("4. PLAY PLAYLIST -> Untuk memainkan lagu berdasarkan ID playlist\n");
        printf("5. QUEUE SONG -> Untuk menambahkan lagu ke dalam queue\n");
        printf("6. QUEUE PLAYLIST -> Untuk menambahkan lagu yang ada dalam playlist ke dalam queue\n");
        printf("6. QUEUE SWAP <x> <y> -> Untuk menukar lagu pada urutan ke (x) dan juga urutan ke (y)\n");
        printf("7. QUEUE REMOVE <id> -> Untuk menghapus lagu dari queue dengan inputan urutan (id) lagu yang ingin dihapus dari queue\n");
        printf("8. QUEUE CLEAR -> Untuk mengosongkan queue\n");
        printf("9. SONG NEXT -> Untuk memutar lagu selanjutnya dalam queue jika ada\n");
        printf("10. SONG PREVIOUS -> Untuk memutar lagu yang sebelumnya diputar jika ada\n");
        printf("11. PLAYLIST CREATE -> Untuk membuat playlist baru dan ditambahkan pada daftar playlist pengguna\n");
        printf("12. PLAYLIST ADD -> Untuk menambahkan lagu atau album ke dalam playlist yang sudah dimiliki pengguna dalam daftar playlist\n");
        printf("13. PLAYLIST SWAP <id> <x> <y> -> Untuk menukar lagu pada urutan ke (x) dan juga urutan ke (y) di playlist dengan index (id)\n");
        printf("14. PLAYLIST REMOVE <id> <n> -> Untuk menghapus lagu dengan urutan (n) pada playlist dengan index (id)\n");
        printf("15. PLAYLIST DELETE -> Untuk melakukan penghapusan suatu existing playlist dalam daftar playlist\n");
        printf("16. STATUS -> Untuk menampilkan lagu yang sedang diputar, dari playlist mana lagu tersebut, serta queue song (jika ada)\n");
        printf("17. SAVE <filename> -> Untuk menyimpan state WayangWave terbaru ke dalam suatu file bernama (filename) dengan tipe txt\n");
        printf("18. QUIT -> Untuk keluar dari aplikasi WayangWave\n");
    }
}

void listDefault(Array arrPenyanyi, Penyanyi albumPenyanyi, Album laguAlbum)
{
    printf("Daftar Penyanyi:\n");
    PrintArrayPenyanyi(arrPenyanyi);

    printf("Ingin melihat album yang ada?(Y/N): ");
    startInputWord();
    Word command;
    akuisisiCommandWord(&command, currentWord, 1);
    char *com;
    com = wordToString(command);
    boolean wrong = false;

    if (strcmp(com, "Y") == 0)
    {
        printf("Pilih penyanyi untuk melihat album mereka: ");
        startInputWord();
        Word namePenyanyi;
        akuisisiCommandWord(&namePenyanyi, currentWord, 1);
        char* com = wordToString(namePenyanyi);
        akuisisiCommandWord(&namePenyanyi, currentWord, 2);
        char* penyanyi2 = wordToString(namePenyanyi);
        char* spasi = " ";

        if (strcmp(penyanyi2, "") != 0)
        {
            com = concat(com, spasi);
            com = concat(com, penyanyi2);
        }

        printf("Daftar Album oleh %s :\n", com);
        if (strcmp(com, "BLACKPINK") == 0)
        {
            PrintAlbumPenyanyi(albumPenyanyi, "BLACKPINK");
        }
        else if (strcmp(com, "Arctic Monkeys") == 0)
        {
            PrintAlbumPenyanyi(albumPenyanyi, "Arctic Monkeys");
        }
        else 
        {
            wrong = true;
        }

        if (!wrong)
        {
            printf("Ingin melihat lagu yang ada?(Y/N): ");
            startInputWord();
            akuisisiCommandWord(&command, currentWord, 1);
            com = wordToString(command);

            if (strcmp(com, "Y") == 0)
            {
                printf("Pilih album untuk melihat lagu yang ada di album: ");
                startInputWord();
                Word nameAlbum;
                akuisisiCommandWord(&nameAlbum, currentWord, 1);
                char* com = wordToString(nameAlbum);
                akuisisiCommandWord(&nameAlbum, currentWord, 2);
                char* album2 = wordToString(nameAlbum);
                akuisisiCommandWord(&nameAlbum, currentWord, 3);
                char* album3 = wordToString(nameAlbum);

                if (strcmp(album2, "") != 0)
                {
                    com = concat(com, spasi);
                    com = concat(com, album2);
                }

                if (strcmp(album3, "") != 0)
                {
                    com = concat(com, spasi);
                    com = concat(com, album3);
                }

                printf("Daftar Lagu di %s:\n", com);
                if (strcmp(com, "BORN PINK") == 0)
                {
                    PrintAlbumLagu(laguAlbum, "BORN PINK");
                }
                else if (strcmp(com, "THE ALBUM") == 0)
                {
                    PrintAlbumLagu(laguAlbum, "THE ALBUM");
                }
                else if (strcmp(com, "Favourite Worst Nightmare") == 0)
                {
                    PrintAlbumLagu(laguAlbum, "Favourite Worst Nightmare");
                }
                else if (strcmp(com, "Humbug") == 0)
                {
                    PrintAlbumLagu(laguAlbum, "Humbug");
                }
                else if (strcmp(com, "AM") == 0)
                {
                    PrintAlbumLagu(laguAlbum, "AM");
                }
                else 
                {
                    wrong = true;
                }
            }
        }
    }

}

void queueSong (Queue *Q, Array arrPenyanyi, Penyanyi albumPenyanyi, Album laguAlbum)
{
    printf("Daftar Penyanyi:\n");
    PrintArrayPenyanyi(arrPenyanyi);

    printf("Masukkan Nama Penyanyi: ");
    startInputWord();
    Word namePenyanyi;
    akuisisiCommandWord(&namePenyanyi, currentWord, 1);
    char* penyanyi = wordToString(namePenyanyi);
    akuisisiCommandWord(&namePenyanyi, currentWord, 2);
    char* penyanyi2 = wordToString(namePenyanyi);
    char* spasi = " ";

    if (strcmp(penyanyi2, "") != 0)
    {
        penyanyi = concat(penyanyi, spasi);
        penyanyi = concat(penyanyi, penyanyi2);
    }

    printf("Daftar Album oleh %s :\n", penyanyi);
    if (strcmp(penyanyi, "BLACKPINK") == 0)
    {
        PrintAlbumPenyanyi(albumPenyanyi, "BLACKPINK");
    }
    else if (strcmp(penyanyi, "Arctic Monkeys") == 0)
    {
        PrintAlbumPenyanyi(albumPenyanyi, "Arctic Monkeys");
    }
    else if (strcmp(penyanyi, "NewJeans") == 0)
    {
        PrintAlbumPenyanyi(albumPenyanyi, "NewJeans");
    }
    else if (strcmp(penyanyi, "Hivi!") == 0)
    {
        PrintAlbumPenyanyi(albumPenyanyi, "Hivi!");
    }

    printf("Masukkan Nama Album yang dipilih: ");
    startInputWord();
    Word nameAlbum;
    akuisisiCommandWord(&nameAlbum, currentWord, 1);
    char* album = wordToString(nameAlbum);
    akuisisiCommandWord(&nameAlbum, currentWord, 2);
    char* album2 = wordToString(nameAlbum);
    int i = 2;
    while(strcmp(album2, "") != 0)
    {
        album = concat(album, spasi);
        album = concat(album, album2);
        i +=1;
        akuisisiCommandWord(&nameAlbum, currentWord, i);
        album2 = wordToString(nameAlbum);
    }

    printf("Daftar Lagu di %s:\n", album);
    if (strcmp(album, "BORN PINK") == 0)
    {
        PrintAlbumLagu(laguAlbum, "BORN PINK");
    }
    else if (strcmp(album, "THE ALBUM") == 0)
    {
        PrintAlbumLagu(laguAlbum, "THE ALBUM");
    }
    else if (strcmp(album, "SQUARE ONE") == 0)
    {
        PrintAlbumLagu(laguAlbum, "SQUARE ONE");
    }
    else if (strcmp(album, "SQUARE TWO") == 0)
    {
        PrintAlbumLagu(laguAlbum, "SQUARE TWO");
    }
    else if (strcmp(album, "SQUARE UP") == 0)
    {
        PrintAlbumLagu(laguAlbum, "SQUARE UP");
    }
    else if (strcmp(album, "Favourite Worst Nightmare") == 0)
    {
        PrintAlbumLagu(laguAlbum, "Favourite Worst Nightmare");
    }
    else if (strcmp(album, "Humbug") == 0)
    {
        PrintAlbumLagu(laguAlbum, "Humbug");
    }
    else if (strcmp(album, "AM") == 0)
    {
        PrintAlbumLagu(laguAlbum, "AM");
    }
    else if (strcmp(album, "New Jeans") == 0)
    {
        PrintAlbumLagu(laguAlbum, "New Jeans");
    }
    else if (strcmp(album, "OMG") == 0)
    {
        PrintAlbumLagu(laguAlbum, "OMG");
    }
    else if (strcmp(album, "Get Up") == 0)
    {
        PrintAlbumLagu(laguAlbum, "Get Up");
    }
    else if (strcmp(album, "CERITERA") == 0)
    {
        PrintAlbumLagu(laguAlbum, "CERITERA");
    }
    else if (strcmp(album, "Kereta Kencan") == 0)
    {
        PrintAlbumLagu(laguAlbum, "Kereta Kencan");
    }
    else if (strcmp(album, "Say Hi To Hivi!") == 0)
    {
        PrintAlbumLagu(laguAlbum, "Say Hi To Hivi!");
    }
    
    printf("Masukkan ID Lagu yang dipilih: ");
    startInputWord();
    Word IDs;
    akuisisiCommandWord(&IDs, currentWord, 1);
    int IDsong = wordToInt(IDs);
    infotype song = LaguFromAlbum(laguAlbum, album, IDsong);

    ElTypeQueue El;
    El.artist = (char *)malloc(strlen(penyanyi) + 1);
    El.album = (char *)malloc(strlen(album) + 1);
    El.song = (char *)malloc(strlen(song) + 1);
    if (El.artist != NULL && El.album != NULL && El.song != NULL)
    {
        // Copy strings to allocated memory
        strcpy(El.artist, penyanyi);
        strcpy(El.album, album);
        strcpy(El.song, song);

        // Enqueue the element
        enqueue(Q, El);
    }
}

void playSong (Queue *Q, Stackchar *History, Array arrPenyanyi, Penyanyi albumPenyanyi, Album laguAlbum, currentSong currentSong)
{
    printf("Daftar Penyanyi:\n");
    PrintArrayPenyanyi(arrPenyanyi);

    printf("Masukkan Nama Penyanyi: ");
    startInputWord();
    Word namePenyanyi;
    akuisisiCommandWord(&namePenyanyi, currentWord, 1);
    char* penyanyi = wordToString(namePenyanyi);
    akuisisiCommandWord(&namePenyanyi, currentWord, 2);
    char* penyanyi2 = wordToString(namePenyanyi);
    char* spasi = " ";

    if (strcmp(penyanyi2, "") != 0)
    {
        penyanyi = concat(penyanyi, spasi);
        penyanyi = concat(penyanyi, penyanyi2);
    }

    printf("Daftar Album oleh %s :\n", penyanyi);
    if (strcmp(penyanyi, "BLACKPINK") == 0)
    {
        PrintAlbumPenyanyi(albumPenyanyi, "BLACKPINK");
    }
    else if (strcmp(penyanyi, "Arctic Monkeys") == 0)
    {
        PrintAlbumPenyanyi(albumPenyanyi, "Arctic Monkeys");
    }
    else if (strcmp(penyanyi, "NewJeans") == 0)
    {
        PrintAlbumPenyanyi(albumPenyanyi, "NewJeans");
    }
    else if (strcmp(penyanyi, "Hivi!") == 0)
    {
        PrintAlbumPenyanyi(albumPenyanyi, "Hivi!");
    }

    printf("Masukkan Nama Album yang dipilih: ");
    startInputWord();
    Word nameAlbum;
    akuisisiCommandWord(&nameAlbum, currentWord, 1);
    char* album = wordToString(nameAlbum);
    akuisisiCommandWord(&nameAlbum, currentWord, 2);
    char* album2 = wordToString(nameAlbum);
    int i = 2;
    while(strcmp(album2, "") != 0)
    {
        album = concat(album, spasi);
        album = concat(album, album2);
        i +=1;
        akuisisiCommandWord(&nameAlbum, currentWord, i);
        album2 = wordToString(nameAlbum);
    }

    printf("Daftar Lagu di %s:\n", album);
    if (strcmp(album, "BORN PINK") == 0)
    {
        PrintAlbumLagu(laguAlbum, "BORN PINK");
    }
    else if (strcmp(album, "THE ALBUM") == 0)
    {
        PrintAlbumLagu(laguAlbum, "THE ALBUM");
    }
    else if (strcmp(album, "SQUARE ONE") == 0)
    {
        PrintAlbumLagu(laguAlbum, "SQUARE ONE");
    }
    else if (strcmp(album, "SQUARE TWO") == 0)
    {
        PrintAlbumLagu(laguAlbum, "SQUARE TWO");
    }
    else if (strcmp(album, "SQUARE UP") == 0)
    {
        PrintAlbumLagu(laguAlbum, "SQUARE UP");
    }
    else if (strcmp(album, "Favourite Worst Nightmare") == 0)
    {
        PrintAlbumLagu(laguAlbum, "Favourite Worst Nightmare");
    }
    else if (strcmp(album, "Humbug") == 0)
    {
        PrintAlbumLagu(laguAlbum, "Humbug");
    }
    else if (strcmp(album, "AM") == 0)
    {
        PrintAlbumLagu(laguAlbum, "AM");
    }
    else if (strcmp(album, "New Jeans") == 0)
    {
        PrintAlbumLagu(laguAlbum, "New Jeans");
    }
    else if (strcmp(album, "OMG") == 0)
    {
        PrintAlbumLagu(laguAlbum, "OMG");
    }
    else if (strcmp(album, "Get Up") == 0)
    {
        PrintAlbumLagu(laguAlbum, "Get Up");
    }
    else if (strcmp(album, "CERITERA") == 0)
    {
        PrintAlbumLagu(laguAlbum, "CERITERA");
    }
    else if (strcmp(album, "Kereta Kencan") == 0)
    {
        PrintAlbumLagu(laguAlbum, "Kereta Kencan");
    }
    else if (strcmp(album, "Say Hi To Hivi!") == 0)
    {
        PrintAlbumLagu(laguAlbum, "Say Hi To Hivi!");
    }
    
    printf("Masukkan ID Lagu yang dipilih: ");
    startInputWord();
    Word IDs;
    akuisisiCommandWord(&IDs, currentWord, 1);
    int IDsong = wordToInt(IDs);
    infotype song = LaguFromAlbum(laguAlbum, album, IDsong);

    printf("Memutar lagu %s oleh %s\n", song, penyanyi);
    CreateQueue(Q);
    CreateEmptyStackChar(History);
    currentSong.album = album;
    currentSong.artist = penyanyi;
    currentSong.song = song;
}

void status(Queue *Q, Playlist *PL)
{
    if (!IsEmpty(*PL)){
        printf("Current Playlist: %s", Info(First(*PL))); 
    }
    printf("Now Playing:");
        if(IsEmptyQueue(*Q)){
            printf("No songs have been played yet. Please search for a song to begin playback.");
        }
        else {
            printf("%s - %s - %s", (*Q).Tab[(*Q).idxHead].artist, (*Q).Tab[(*Q).idxHead].song, (*Q).Tab[(*Q).idxHead].album);
        }
        printf("Queue:");
        displayQueue(*Q);
}