#include "console.h"

void Delay (unsigned int Sec)
{
    clock_t ticks1 = clock(), ticks2 = ticks1;
    while ( ( ticks2/CLOCKS_PER_SEC - ticks1/CLOCKS_PER_SEC ) < Sec)
    {
        ticks2 = clock();
    }
}

void start(Array *arrPenyanyi, Array *arrAlbum, Penyanyi *albumPenyanyi, Album *laguAlbum, Set *lagu)
{
    load("default.txt", arrPenyanyi, arrAlbum, albumPenyanyi, laguAlbum, lagu);
}

void quit()
{
    printf("Apakah kamu ingin menyimpan data sesi sekarang?(Y/N) ");
    startInputWord();
    Word command;
    akuisisiCommandWord(&command, currentWord, 1);
    char* confirm;
    confirm = wordToString(command);
    if (strCompare(confirm, "Y") == 0)
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

    if (strCompare(com, "Y") == 0)
    {
        printf("Pilih penyanyi untuk melihat album mereka: ");
        startInputWord();
        Word namePenyanyi;
        akuisisiCommandWord(&namePenyanyi, currentWord, 1);
        char* com = wordToString(namePenyanyi);
        akuisisiCommandWord(&namePenyanyi, currentWord, 2);
        char* penyanyi2 = wordToString(namePenyanyi);
        char* spasi = " ";

        if (strCompare(penyanyi2, "") != 0)
        {
            com = concat(com, spasi);
            com = concat(com, penyanyi2);
        }

        printf("Daftar Album oleh %s :\n", com);
        if (strCompare(com, "BLACKPINK") == 0)
        {
            PrintAlbumPenyanyi(albumPenyanyi, "BLACKPINK");
        }
        else if (strCompare(com, "Arctic Monkeys") == 0)
        {
            PrintAlbumPenyanyi(albumPenyanyi, "Arctic Monkeys");
        }
        else if (strCompare(com, "NewJeans") == 0)
        {
            PrintAlbumPenyanyi(albumPenyanyi, "NewJeans");
        }
        else if (strCompare(com, "Hivi!") == 0)
        {
            PrintAlbumPenyanyi(albumPenyanyi, "Hivi!");
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

            if (strCompare(com, "Y") == 0)
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

                if (strCompare(album2, "") != 0)
                {
                    com = concat(com, spasi);
                    com = concat(com, album2);
                }

                if (strCompare(album3, "") != 0)
                {
                    com = concat(com, spasi);
                    com = concat(com, album3);
                }

                printf("Daftar Lagu di %s:\n", com);
                if (strCompare(com, "BORN PINK") == 0)
                {
                    PrintAlbumLagu(laguAlbum, "BORN PINK");
                }
                else if (strCompare(com, "THE ALBUM") == 0)
                {
                    PrintAlbumLagu(laguAlbum, "THE ALBUM");
                }
                else if (strCompare(com, "SQUARE ONE") == 0)
                {
                    PrintAlbumLagu(laguAlbum, "SQUARE ONE");
                }
                else if (strCompare(com, "SQUARE TWO") == 0)
                {
                    PrintAlbumLagu(laguAlbum, "SQUARE TWO");
                }
                else if (strCompare(com, "SQUARE UP") == 0)
                {
                    PrintAlbumLagu(laguAlbum, "SQUARE UP");
                }
                else if (strCompare(com, "Favourite Worst Nightmare") == 0)
                {
                    PrintAlbumLagu(laguAlbum, "Favourite Worst Nightmare");
                }
                else if (strCompare(com, "Humbug") == 0)
                {
                    PrintAlbumLagu(laguAlbum, "Humbug");
                }
                else if (strCompare(com, "AM") == 0)
                {
                    PrintAlbumLagu(laguAlbum, "AM");
                }
                else if (strCompare(com, "New Jeans") == 0)
                {
                    PrintAlbumLagu(laguAlbum, "New Jeans");
                }
                else if (strCompare(com, "OMG") == 0)
                {
                    PrintAlbumLagu(laguAlbum, "OMG");
                }
                else if (strCompare(com, "Get Up") == 0)
                {
                    PrintAlbumLagu(laguAlbum, "Get Up");
                }
                else if (strCompare(com, "CERITERA") == 0)
                {
                    PrintAlbumLagu(laguAlbum, "CERITERA");
                }
                else if (strCompare(com, "Kereta Kencan") == 0)
                {
                    PrintAlbumLagu(laguAlbum, "Kereta Kencan");
                }
                else if (strCompare(com, "Say Hi To Hivi!") == 0)
                {
                    PrintAlbumLagu(laguAlbum, "Say Hi To Hivi!");
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

    if (strCompare(penyanyi2, "") != 0)
    {
        penyanyi = concat(penyanyi, spasi);
        penyanyi = concat(penyanyi, penyanyi2);
    }

    printf("Daftar Album oleh %s :\n", penyanyi);
    if (strCompare(penyanyi, "BLACKPINK") == 0)
    {
        PrintAlbumPenyanyi(albumPenyanyi, "BLACKPINK");
    }
    else if (strCompare(penyanyi, "Arctic Monkeys") == 0)
    {
        PrintAlbumPenyanyi(albumPenyanyi, "Arctic Monkeys");
    }
    else if (strCompare(penyanyi, "NewJeans") == 0)
    {
        PrintAlbumPenyanyi(albumPenyanyi, "NewJeans");
    }
    else if (strCompare(penyanyi, "Hivi!") == 0)
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
    while(strCompare(album2, "") != 0)
    {
        album = concat(album, spasi);
        album = concat(album, album2);
        i +=1;
        akuisisiCommandWord(&nameAlbum, currentWord, i);
        album2 = wordToString(nameAlbum);
    }

    printf("Daftar Lagu di %s:\n", album);
    if (strCompare(album, "BORN PINK") == 0)
    {
        PrintAlbumLagu(laguAlbum, "BORN PINK");
    }
    else if (strCompare(album, "THE ALBUM") == 0)
    {
        PrintAlbumLagu(laguAlbum, "THE ALBUM");
    }
    else if (strCompare(album, "SQUARE ONE") == 0)
    {
        PrintAlbumLagu(laguAlbum, "SQUARE ONE");
    }
    else if (strCompare(album, "SQUARE TWO") == 0)
    {
        PrintAlbumLagu(laguAlbum, "SQUARE TWO");
    }
    else if (strCompare(album, "SQUARE UP") == 0)
    {
        PrintAlbumLagu(laguAlbum, "SQUARE UP");
    }
    else if (strCompare(album, "Favourite Worst Nightmare") == 0)
    {
        PrintAlbumLagu(laguAlbum, "Favourite Worst Nightmare");
    }
    else if (strCompare(album, "Humbug") == 0)
    {
        PrintAlbumLagu(laguAlbum, "Humbug");
    }
    else if (strCompare(album, "AM") == 0)
    {
        PrintAlbumLagu(laguAlbum, "AM");
    }
    else if (strCompare(album, "New Jeans") == 0)
    {
        PrintAlbumLagu(laguAlbum, "New Jeans");
    }
    else if (strCompare(album, "OMG") == 0)
    {
        PrintAlbumLagu(laguAlbum, "OMG");
    }
    else if (strCompare(album, "Get Up") == 0)
    {
        PrintAlbumLagu(laguAlbum, "Get Up");
    }
    else if (strCompare(album, "CERITERA") == 0)
    {
        PrintAlbumLagu(laguAlbum, "CERITERA");
    }
    else if (strCompare(album, "Kereta Kencan") == 0)
    {
        PrintAlbumLagu(laguAlbum, "Kereta Kencan");
    }
    else if (strCompare(album, "Say Hi To Hivi!") == 0)
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
    El.artist = (char *)malloc(strLength(penyanyi) + 1);
    El.album = (char *)malloc(strLength(album) + 1);
    El.song = (char *)malloc(strLength(song) + 1);
    if (El.artist != NULL && El.album != NULL && El.song != NULL)
    {
        // Copy strings to allocated memory
        strCopy(El.artist, penyanyi);
        strCopy(El.album, album);
        strCopy(El.song, song);

        // Enqueue the element
        enqueue(Q, El);
    }
}

void playSong (Queue *Q, Stackchar *History, Array arrPenyanyi, Penyanyi albumPenyanyi, Album laguAlbum, currentSong *currentSong)
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

    if (strCompare(penyanyi2, "") != 0)
    {
        penyanyi = concat(penyanyi, spasi);
        penyanyi = concat(penyanyi, penyanyi2);
    }

    printf("Daftar Album oleh %s :\n", penyanyi);
    if (strCompare(penyanyi, "BLACKPINK") == 0)
    {
        PrintAlbumPenyanyi(albumPenyanyi, "BLACKPINK");
    }
    else if (strCompare(penyanyi, "Arctic Monkeys") == 0)
    {
        PrintAlbumPenyanyi(albumPenyanyi, "Arctic Monkeys");
    }
    else if (strCompare(penyanyi, "NewJeans") == 0)
    {
        PrintAlbumPenyanyi(albumPenyanyi, "NewJeans");
    }
    else if (strCompare(penyanyi, "Hivi!") == 0)
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
    while(strCompare(album2, "") != 0)
    {
        album = concat(album, spasi);
        album = concat(album, album2);
        i +=1;
        akuisisiCommandWord(&nameAlbum, currentWord, i);
        album2 = wordToString(nameAlbum);
    }

    printf("Daftar Lagu di %s:\n", album);
    if (strCompare(album, "BORN PINK") == 0)
    {
        PrintAlbumLagu(laguAlbum, "BORN PINK");
    }
    else if (strCompare(album, "THE ALBUM") == 0)
    {
        PrintAlbumLagu(laguAlbum, "THE ALBUM");
    }
    else if (strCompare(album, "SQUARE ONE") == 0)
    {
        PrintAlbumLagu(laguAlbum, "SQUARE ONE");
    }
    else if (strCompare(album, "SQUARE TWO") == 0)
    {
        PrintAlbumLagu(laguAlbum, "SQUARE TWO");
    }
    else if (strCompare(album, "SQUARE UP") == 0)
    {
        PrintAlbumLagu(laguAlbum, "SQUARE UP");
    }
    else if (strCompare(album, "Favourite Worst Nightmare") == 0)
    {
        PrintAlbumLagu(laguAlbum, "Favourite Worst Nightmare");
    }
    else if (strCompare(album, "Humbug") == 0)
    {
        PrintAlbumLagu(laguAlbum, "Humbug");
    }
    else if (strCompare(album, "AM") == 0)
    {
        PrintAlbumLagu(laguAlbum, "AM");
    }
    else if (strCompare(album, "New Jeans") == 0)
    {
        PrintAlbumLagu(laguAlbum, "New Jeans");
    }
    else if (strCompare(album, "OMG") == 0)
    {
        PrintAlbumLagu(laguAlbum, "OMG");
    }
    else if (strCompare(album, "Get Up") == 0)
    {
        PrintAlbumLagu(laguAlbum, "Get Up");
    }
    else if (strCompare(album, "CERITERA") == 0)
    {
        PrintAlbumLagu(laguAlbum, "CERITERA");
    }
    else if (strCompare(album, "Kereta Kencan") == 0)
    {
        PrintAlbumLagu(laguAlbum, "Kereta Kencan");
    }
    else if (strCompare(album, "Say Hi To Hivi!") == 0)
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
    (*currentSong).album = album;
    (*currentSong).artist = penyanyi;
    (*currentSong).song = song;
}

void status(Queue *Q, Playlist *playlistLagu, currentSong currentSong, currentPlaylist currentPlaylist)
{
    if(Q->Tab[Q->idxHead].idPlaylist != (-1))
    {
        printf("Current Playlist: ");
        PrintCurrentPlaylist(currentPlaylist);
        printf("\n");
    }
    
    printf("Now Playing: ");
        if(isEmptyCurrentSong(currentSong))
        {
            printf("No songs have been played yet. Please search for a song to begin playback.");
        }
        else 
        {
            PrintCurrentSong(currentSong);
        }
        printf("\n");
    printf("Queue: ");
    displayQueue(*Q);
    printf("\n");
}

void listPlaylist(ListPlaylist listPL)
{
    printf("Daftar Playlist yang kamu miliki:\n");
    printListPlaylist(&listPL);
}

void queuePlaylist (Queue *Q, Playlist *playlistLagu)
{
    printf("Masukkan ID Playlist: ");
    startInputWord();
    Word IDplaylistWord;
    akuisisiCommandWord(&IDplaylistWord, currentWord, 1);
    int IDplaylist = wordToInt(IDplaylistWord);
    infotype playlist = LaguFromPlaylist(playlistLagu, IDplaylistWord);

    ElTypeQueue Pl;
    Pl.playlist = (char *)malloc(strLength(playlist) + 1);
    while (Pl.playlist != NULL)
    {
        strCopy(Pl.playlist, playlist);
        enqueue(Q, Pl);
    }
}

void songNext(Queue *Q, currentSong *currentSong, nextSong *nextSong)
{
    if (IsEmptyQueue(*Q)) {
        PlayCurrentSong(*currentSong);
    }
    else {
        PlayNextSong(nextSong, currentSong, Q);
    }
}

void songPrevious(Queue *Q, Stackchar *History, currentSong currentSong)
{
    if (IsEmptyStackChar(*History)) {
        ReplayCurrentSong(currentSong);
    }
    else {
        PlayPrevSong(*History);
    }
}

void PlaylistCreate(ListPlaylist *listPL, Playlist PL)
{
    //KAMUS
    char CharPL1, CharPL2, CharPL3;
    int countChar = 0;

    //ALGORITMA
    printf("Masukkan nama playlist yang ingin dibuat : ");
    startInputWord();
    Word listPLinput;
    akuisisiCommandWord(&listPLinput, currentWord, 1);
    char* listPL_input = wordToString(listPLinput);
    
    //pengecekan input nama playlist
    START(listPL_input);
    CharPL1 = GetCC();
    if(CharPL1 != BLANK)
    {
        countChar += 1;
    }
    ADV();
    CharPL2 = GetCC();
    if(CharPL2 != BLANK)
    {
        countChar += 1;
    }
    ADV();
    CharPL3 = GetCC();
    if(CharPL3 != BLANK)
    {
        countChar += 1;
    }

    if(countChar != 3)
    {
        printf("Minimal terdapat 3 karakter selain whitespace dalam nama playlist. Silakan coba lagi.");
        exit(EXIT_FAILURE);
    } 
    else if(countChar == 3)
    {
        addElement(listPL, listPL_input);
        PL.namePL = listPL_input;
        printf("Playlist %s berhasil dibuat!", &listPL_input);
        printf("Silakan masukkan lagu - lagu artis terkini kesayangan Anda!");
    }
}

void PlaylistSwap(ListPlaylist *listPL, int idxlagu1, int idxlagu2){
    Playlist *chosenPlaylist;
    int totalsong;
    
    startInputWord();
    Word idPLinput;
    akuisisiCommandWord(&idPLinput, currentWord, 1);
    int idPL_input = wordToInt(idPLinput);
    if(idPL_input > listPL->count){
        printf("Tidak ada playlist dengan playlist ID %d", idPLinput);
        return;
    } else{
        chosenPlaylist->namePL = listPL->playlist[idPL_input];
        totalsong = NbElmtPlaylist(*chosenPlaylist);

        if(idxlagu1 > totalsong){
            printf("Tidak ada lagu dengan urutan %d di playlist “%s”", idxlagu1, chosenPlaylist);
            return;
        } else if(idxlagu2 > totalsong){
            printf("Tidak ada lagu dengan urutan %d di playlist “%s”", idxlagu2, chosenPlaylist);
            return;
        }

        SwapSongsByIndex(chosenPlaylist, idxlagu1, idxlagu2);
    }
}

void PlaylistDelete(ListPlaylist *listPL){
    printListPlaylist(listPL);
    printf("Masukkan ID Playlist yang dipilih :");
    startInputWord();
    Word idplaylist;
    akuisisiCommandWord(&idplaylist, currentWord, 1);
    int id_playlist = wordToInt(idplaylist);

    arraysize idx_idplaylist = 0;
    idx_idplaylist = id_playlist - 1;

    if(idx_idplaylist >= listPL->count){
        printf("Tidak ada playlist dengan ID %d dalam daftar playlist pengguna. Silakan coba lagi.", idplaylist);
    } else {
        deleteAtIndex(listPL, idx_idplaylist);
        printf("Playlist ID %d dengan judul “%s” berhasil dihapus.", idplaylist, listPL->playlist[idx_idplaylist]);
    }
}

void PlaylistRemove(ListPlaylist *listPL, int idxlagu){
    Playlist *chosenPlaylist;
    int totalsong;
    startInputWord();
    Word idPLinput;
    akuisisiCommandWord(&idPLinput, currentWord, 1);
    int id_PLinput = wordToInt(idPLinput);

    chosenPlaylist->namePL = listPL->playlist[id_PLinput];

    if(id_PLinput > listPL->count){
        printf("Tidak ada playlist dengan playlist ID %d", idPLinput);
        return;
    } else{
        chosenPlaylist->namePL = listPL->playlist[id_PLinput];
        totalsong = NbElmtPlaylist(*chosenPlaylist);

        if(idxlagu > totalsong){
            printf("Tidak ada lagu dengan urutan %d di playlist “%s”", idxlagu, chosenPlaylist);
            return;
        }
        DeleteSongByIndex(chosenPlaylist, idxlagu);
    }
}

void PlaylistAddSong(ListPlaylist *listPL, Playlist *chosenPlaylist, Array arrPenyanyi, Penyanyi albumPenyanyi, Album laguAlbum){
    printf("Daftar Penyanyi:\n");
    PrintArrayPenyanyi(arrPenyanyi);

    printf("Masukkan Nama Penyanyi: ");
    startInputWord();
    Word namePenyanyi;
    char* penyanyi = wordToString(namePenyanyi);
    akuisisiCommandWord(&namePenyanyi, currentWord, 2);
    char* penyanyi2 = wordToString(namePenyanyi);
    char* spasi = " ";

    if (strCompare(penyanyi2, "") != 0)
    {
        penyanyi = concat(penyanyi, spasi);
        penyanyi = concat(penyanyi, penyanyi2);
    }

    printf("Daftar Album oleh %s :\n", penyanyi);
    if (strCompare(penyanyi, "BLACKPINK") == 0)
    {
        PrintAlbumPenyanyi(albumPenyanyi, "BLACKPINK");
    }
    else if (strCompare(penyanyi, "Arctic Monkeys") == 0)
    {
        PrintAlbumPenyanyi(albumPenyanyi, "Arctic Monkeys");
    }
    else if (strCompare(penyanyi, "NewJeans") == 0)
    {
        PrintAlbumPenyanyi(albumPenyanyi, "NewJeans");
    }
    else if (strCompare(penyanyi, "Hivi!") == 0)
    {
        PrintAlbumPenyanyi(albumPenyanyi, "Hivi!");
    } else {
        printf("Penyanyi %s tidak ada dalam daftar. Silakan coba lagi.\n", penyanyi);
        return;
    }

    printf("Masukkan Nama Album yang dipilih: ");
    startInputWord();
    Word nameAlbum;
    akuisisiCommandWord(&nameAlbum, currentWord, 1);
    char* album = wordToString(nameAlbum);
    akuisisiCommandWord(&nameAlbum, currentWord, 2);
    char* album2 = wordToString(nameAlbum);
    int i = 2;
    while(strCompare(album2, "") != 0)
    {
        album = concat(album, spasi);
        album = concat(album, album2);
        i +=1;
        akuisisiCommandWord(&nameAlbum, currentWord, i);
        album2 = wordToString(nameAlbum);
    }

    printf("Daftar Lagu di %s:\n", album);
    if (strCompare(album, "BORN PINK") == 0)
    {
        PrintAlbumLagu(laguAlbum, "BORN PINK");
    }
    else if (strCompare(album, "THE ALBUM") == 0)
    {
        PrintAlbumLagu(laguAlbum, "THE ALBUM");
    }
    else if (strCompare(album, "SQUARE ONE") == 0)
    {
        PrintAlbumLagu(laguAlbum, "SQUARE ONE");
    }
    else if (strCompare(album, "SQUARE TWO") == 0)
    {
        PrintAlbumLagu(laguAlbum, "SQUARE TWO");
    }
    else if (strCompare(album, "SQUARE UP") == 0)
    {
        PrintAlbumLagu(laguAlbum, "SQUARE UP");
    }
    else if (strCompare(album, "Favourite Worst Nightmare") == 0)
    {
        PrintAlbumLagu(laguAlbum, "Favourite Worst Nightmare");
    }
    else if (strCompare(album, "Humbug") == 0)
    {
        PrintAlbumLagu(laguAlbum, "Humbug");
    }
    else if (strCompare(album, "AM") == 0)
    {
        PrintAlbumLagu(laguAlbum, "AM");
    }
    else if (strCompare(album, "New Jeans") == 0)
    {
        PrintAlbumLagu(laguAlbum, "New Jeans");
    }
    else if (strCompare(album, "OMG") == 0)
    {
        PrintAlbumLagu(laguAlbum, "OMG");
    }
    else if (strCompare(album, "Get Up") == 0)
    {
        PrintAlbumLagu(laguAlbum, "Get Up");
    }
    else if (strCompare(album, "CERITERA") == 0)
    {
        PrintAlbumLagu(laguAlbum, "CERITERA");
    }
    else if (strCompare(album, "Kereta Kencan") == 0)
    {
        PrintAlbumLagu(laguAlbum, "Kereta Kencan");
    }
    else if (strCompare(album, "Say Hi To Hivi!") == 0)
    {
        PrintAlbumLagu(laguAlbum, "Say Hi To Hivi!");
    } else {
        printf("Album %s tidak ada dalam daftar. Silakan coba lagi.\n", laguAlbum);
    }

    printf("Masukkan ID Lagu yang dipilih: ");
    startInputWord();
    Word IDs;
    akuisisiCommandWord(&IDs, currentWord, 1);
    int IDsong = wordToInt(IDs);
    
    printListPlaylist(listPL);
    printf("Masukkan ID Playlist yang dipilih :");
    startInputWord();
    Word idplaylist;
    akuisisiCommandWord(&idplaylist, currentWord, 1);
    int id_playlist = wordToInt(idplaylist);
    
    Playlist *selectedPlaylist = NULL;
    for (int i = 0; i < listPL->count; i++) {
        if (listPL->playlist[i] != NULL && strCompare(listPL->playlist[i], id_playlist) == 0) {
            selectedPlaylist = &listPL->playlist[i];
            break;
        }
    }

    content newSong;
    newSong.lagu = LaguFromAlbum(laguAlbum, album, IDsong);
    newSong.album = album;
    newSong.penyanyi = penyanyi;

    if (selectedPlaylist != NULL) {
        InsVLast(selectedPlaylist, newSong);
        printf("Lagu dengan judul “%s” pada album %s oleh penyanyi %s berhasil ditambahkan ke dalam playlist %s.\n", newSong.lagu, newSong.penyanyi, newSong.album, selectedPlaylist->namePL);
    } else {
        printf("Playlist dengan ID %d tidak ditemukan.\n", id_playlist);
    }
}