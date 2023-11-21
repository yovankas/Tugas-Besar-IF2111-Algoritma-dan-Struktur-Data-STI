#include <stdio.h>
#include <stdlib.h>
#include "../../ADT/playlist/playlist.h"

// /* PROTOTYPE */
// /****************** TEST LIST KOSONG ******************/
// boolean IsEmptyPlaylist (Playlist PL){
// /* Mengirim true jika list kosong */
//     return(First(PL) == Nil_Playlist);
// }

// /****************** PEMBUATAN LIST KOSONG ******************/
// void CreateEmptyPlaylist (Playlist *PL){
// /* I.S. sembarang             */
// /* F.S. Terbentuk list kosong */
//     First(*PL) = Nil_Playlist;
// }

// /****************** Manajemen Memori ******************/
// addressPlaylist AlokasiPlaylist (content val){
//     /* Mengirimkan address hasil alokasi sebuah elemen */
//     /* Jika alokasi berhasil, maka address tidak nil, dan misalnya */
//     /* menghasilkan P, maka info(P)=val, Next(P)=Nil */
//     /* Jika alokasi gagal, mengirimkan Nil */
//     //KAMUS LOKAL
//     addressPlaylist P;

//     //ALGORITMA
//     P = (Elmtlist*) malloc (sizeof(Elmtlist));

//     if(P != Nil_Playlist) {
//         Info(P) = val;
//         Next(P) = Nil_Playlist;
//         return P;
//     } else {
//         return Nil_Playlist;
//     }
// }

// void DealokasiPlaylist (addressPlaylist *P){
// /* I.S. P terdefinisi */
// /* F.S. P dikembalikan ke sistem */
// /* Melakukan dealokasi/pengembalian address P */
//     free(*P);
// }

// addressPlaylist SearchinPlaylist (Playlist PL, content val){
// /* Mencari apakah ada elemen list dengan info(P)= val */
// /* Jika ada, mengirimkan address elemen tersebut. */
// /* Jika tidak ada, mengirimkan Nil */
//     //KAMUS LOKAL
//     addressPlaylist P;
//     boolean found;

//     //ALGORITMA
//     P = First(PL);
//     while(P != Nil_Playlist && !found){
//         if(strCompare(Info(P).lagu, val.lagu) == 0 && strCompare(Info(P).album, val.album) == 0 && strCompare(Info(P).penyanyi, val.penyanyi) == 0){
//             found = true;
//         } else {
//             P = Next(P);
//         }
//     }

//     if(found){
//         return P;
//     } else {
//         return Nil_Playlist;
//     }
// }

// /****************** PRIMITIF BERDASARKAN NILAI ******************/
// /*** PENAMBAHAN ELEMEN ***/
// void InsVFirst (Playlist *PL, content val){
// /* I.S. PL mungkin kosong */
// /* F.S. Melakukan alokasi sebuah elemen dan */
// /* menambahkan elemen pertama dengan nilai val jika alokasi berhasil */
//     //KAMUS LOKAL
//     addressPlaylist P;

//     //ALGORITMA
//     P = AlokasiPlaylist(val);
//     if(P != Nil_Playlist){
//         Next(P) = First(*PL);
//         First(*PL) = P;
//     }
// }
// void InsVLast (Playlist *PL, content val){
// /* I.S. PL mungkin kosong */
// /* F.S. Melakukan alokasi sebuah elemen dan */
// /* menambahkan elemen list di akhir: elemen terakhir yang baru */
// /* bernilai val jika alokasi berhasil. Jika alokasi gagal: I.S.= F.S. */
//     //KAMUS LOKAL
//     addressPlaylist P;
//     addressPlaylist last;

//     //ALGORITMA
//     if(IsEmptyPlaylist(*PL)){
//         InsVFirst(PL, val);
//     } else {
//         P = AlokasiPlaylist(val);
//         if(P != Nil_Playlist){
//             last = First(*PL);
//             while (Next(last) != Nil_Playlist){
//                 last = Next(last);
//             }
//             Next(last) = P;
//         }
//     }
// }

// /*** PENGHAPUSAN ELEMEN ***/
// void DelVFirst (Playlist *PL, content *val){
// /* I.S. Playlist PL tidak kosong  */
// /* F.S. Elemen pertama list dihapus: nilai info disimpan pada val */
// /*      dan alamat elemen pertama di-dealokasi */
//     //KAMUS LOKAL
//     addressPlaylist P;

//     //ALGORITMA
//     P = First(*PL);
//     *val = Info(P);
//     First(*PL) = Next(P);
//     DealokasiPlaylist(&P);
// }

// void DelVLast (Playlist *PL, content *val){
// /* I.S. list tidak kosong */
// /* F.S. Elemen terakhir list dihapus: nilai info disimpan pada val */
// /*      dan alamat elemen terakhir di-dealokasi */
//     //KAMUS LOKAL
//     addressPlaylist p;
//     addressPlaylist prev;

//     //ALGORITMA
//     p = First(*PL);
//     while(Next(p) != Nil_Playlist){
//         prev = p;
//         p = Next(p);
//     }
//     *val = Info(p);

//     if(NbElmtPlaylist(*PL) == 1){
//         First(*PL) = Nil_Playlist;
//     } else {
//         Next(prev) = Nil_Playlist;
//     }
//     DealokasiPlaylist(&p);
// }

// /****************** PRIMITIF BERDASARKAN ALAMAT ******************/
// /*** PENAMBAHAN ELEMEN BERDASARKAN ALAMAT ***/
// void InsertFirst (Playlist *PL, addressPlaylist P){
// /* I.S. Sembarang, P sudah dialokasi  */
// /* F.S. Menambahkan elemen ber-address P sebagai elemen pertama */
//     //ALGORITMA
//     if(P != Nil_Playlist){
//         Next(P) = First(*PL);
//         First(*PL) = P;
//     }
// }

// void InsertAfter (Playlist *PL, addressPlaylist P, addressPlaylist Prec){
// /* I.S. Prec pastilah elemen list dan bukan elemen terakhir, */
// /*      P sudah dialokasi  */
// /* F.S. Insert P sebagai elemen sesudah elemen beralamat Prec */
//     //ALGORITMA
//     if(P != Nil_Playlist){
//         Next(P) = Next(Prec);
//         Next(Prec) = P;
//     }
// }

// void InsertLast (Playlist *PL, addressPlaylist P){
// /* I.S. Sembarang, P sudah dialokasi  */
// /* F.S. P ditambahkan sebagai elemen terakhir yang baru */
//     // KAMUS LOKAL
//     addressPlaylist last;

//     // ALGORITMA
//     if (IsEmptyPlaylist(*PL)){
//         InsertFirst(PL, P);
//     } else {
//         if (last != Nil_Playlist) {
//             last = First(*PL);
//             while (Next(last) != Nil_Playlist) {
//                 last = Next(last);
//             }
//             Next(last) = P;
//         }
//     }
// }

// /*** PENGHAPUSAN SEBUAH ELEMEN ***/
// void DelFirst (Playlist *PL, addressPlaylist *P){
// /* I.S. Playlist tidak kosong */
// /* F.S. P adalah alamat elemen pertama list sebelum penghapusan */
// /*      Elemen list berkurang satu (mungkin menjadi kosong) */
// /* First element yg baru adalah suksesor elemen pertama yang lama */
//     *P = First(*PL);
//     First(*PL) = Next(*P);
// }

// void DelP (Playlist *PL, content val){
// /* I.S. Sembarang */
// /* F.S. Jika ada elemen list beraddress P, dengan info(P)=val  */
// /* Maka P dihapus dari list dan di-dealokasi */
// /* Jika tidak ada elemen list dengan info(P)=val, maka list tetap */
// /* Playlist mungkin menjadi kosong karena penghapusan */
//     // KAMUS LOKAL
//     addressPlaylist prev;
//     addressPlaylist last;

//     // ALGORITMA
//     last = First(*PL);
//     prev = Nil_Playlist;
//     while (!strCompare(Info(last).lagu, val.lagu) || !strCompare(Info(last).album, val.album) || !strCompare(Info(last).penyanyi, val.penyanyi)) {
//         prev = last;
//         last = Next(last);
//     }

//     if (last == First(*PL)){
//         First(*PL) = Next(last);
//     }
//     else{
//         Next(prev) = Next(last);
//     }
//     DealokasiPlaylist(&last);
// }

// void DelLast (Playlist *PL, addressPlaylist *P){
// /* I.S. Playlist tidak kosong */
// /* F.S. P adalah alamat elemen terakhir list sebelum penghapusan  */
// /*      Elemen list berkurang satu (mungkin menjadi kosong) */
// /* Last element baru adalah predesesor elemen terakhir yg lama, */
// /* jika ada */
//     // KAMUS LOKAL
//     addressPlaylist last;
//     addressPlaylist prev;

//     // ALGORITMA
//     last = First(*PL);
//     while (Next(last) != Nil_Playlist) {
//         prev = last;
//         last = Next(last);
//     }
//     *P = last;

//     if (NbElmtPlaylist(*PL) == 1){
//         First(*PL) = Nil_Playlist;
//     } else {
//         Next(prev) = Nil_Playlist;
//     }
// }

// void DelAfter (Playlist *PL, addressPlaylist *Pdel, addressPlaylist Prec){
// /* I.S. Playlist tidak kosong. Prec adalah anggota list  */
// /* F.S. Menghapus Next(Prec): */
// /*      Pdel adalah alamat elemen list yang dihapus  */
//     *Pdel = Next(Prec);
//     Next(Prec) = Next(*Pdel);
// }

// /****************** PROSES SEMUA ELEMEN LIST ******************/
// void PrintInfo (Playlist PL){
// /* I.S. Playlist mungkin kosong */
// /* F.S. Jika list tidak kosong, isi list dicetak ke kanan: [e1,e2,...,en] */
// /* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [1,20,30] */
// /* Jika list kosong : menulis [] */
// /* Tidak ada tambahan karakter apa pun di awal, akhir, atau di tengah terkecuali untuk newline di akhir output */
//     // KAMUS LOKAL
//     addressPlaylist p;

//     // ALGORITMA
//     if (IsEmptyPlaylist(PL)){
//         printf("[]\n");
//     } else {
//         p = First(PL);
//         printf("[");
//         while (p != Nil_Playlist) {
//             if (Next(p) != Nil_Playlist){
//                 printf("%d,", Info(p));
//             }
//             else{
//                 printf("%d]\n", Info(p));
//             }
//             p = Next(p);
//         }
//     }
// }
// int NbElmtPlaylist (Playlist PL){
// /* Mengirimkan banyaknya elemen list; mengirimkan 0 jika list kosong */
//     // KAMUS LOKAL
//     int cnt = 0;
//     addressPlaylist p;
    
//     // ALGORITMA
//     p = First(PL);
//     while (p != Nil_Playlist) {
//         p = Next(p);
//         cnt++;
//     }
//     PL.countisiPL = cnt;
//     return PL.countisiPL;
// }

// /****************** PROSES TERHADAP LIST ******************/

// void InversList (Playlist *PL){
// /* I.S. sembarang. */
// /* F.S. elemen list dibalik : */
// /* Elemen terakhir menjadi elemen pertama, dan seterusnya. */
// /* Membalik elemen list, tanpa melakukan alokasi/dealokasi. */
//     // KAMUS LOKAL
//     addressPlaylist p, prev, last;

//     // ALGORITMA
//     p = First(*PL);
//     prev = Nil_Playlist;
//     while (p != Nil_Playlist) {
//         last = p;
//         p = Next(p);
//         Next(last) = prev;
//         prev = last;
//     }

//     First(*PL) = last;
// }

// void Konkat1 (Playlist *PL1, Playlist *PL2, Playlist *PL3){
// /* I.S. PL1 dan PL2 sembarang */
// /* F.S. PL1 dan PL2 kosong, PL3 adalah hasil konkatenasi PL1 & PL2 */
// /* Konkatenasi dua buah list : PL1 dan PL2    */
// /* menghasilkan PL3 yang baru (dengan elemen list PL1 dan PL2) */
// /* dan PL1 serta PL2 menjadi list kosong.*/
// /* Tidak ada alokasi/dealokasi pada prosedur ini */
//     // KAMUS LOKAL
//     addressPlaylist last;

//     // ALGORITMA
//     if (IsEmptyPlaylist(*PL1)){
//         First(*PL3) = First(*PL2);
//     } else {
//         First(*PL3) = First(*PL1);
//         last = First(*PL1);
//         while (Next(last) != Nil_Playlist) {
//             last = Next(last);
//         }
//         Next(last) = First(*PL2);
//     }

//     First(*PL1) = Nil_Playlist;
//     First(*PL2) = Nil_Playlist;
// }

// void SwapSongsinPlaylist(Playlist *PL, addressPlaylist P1, addressPlaylist P2){
//     if (P1 == P2 || P1 == Nil_Playlist || P2 == Nil_Playlist) {
//         return;
//     }

//     addressPlaylist PrecP1 = Nil_Playlist;
//     addressPlaylist PrecP2 = Nil_Playlist;
//     addressPlaylist Current = First(*PL);

//     // Cari elemen sebelum P1 dan P2
//     while (Current != Nil_Playlist && (Current != P1 && Current != P2)) {
//         PrecP1 = Current;
//         Current = Next(Current);
//     }

//     if (Current == Nil_Playlist) {
//         // satu atau keduanya tidak ditemukan
//         return;
//     }

//     PrecP2 = PrecP1;
//     PrecP1 = Nil_Playlist;
//     Current = First(*PL);

//     while (Current != Nil_Playlist && (Current != P1 && Current != P2)) {
//         PrecP2 = PrecP1;
//         PrecP1 = Current;
//         Current = Next(Current);
//     }

//     if (PrecP1 != Nil_Playlist) {
//         Next(PrecP1) = P2;
//     } else {
//         First(*PL) = P2;
//     }

//     if (PrecP2 != Nil_Playlist) {
//         Next(PrecP2) = P1;
//     } else {
//         First(*PL) = P1;
//     }

//     addressPlaylist Temp = Next(P1);
//     Next(P1) = Next(P2);
//     Next(P2) = Temp;
// }

// void SwapSongsByIndex(Playlist *PL, int index1, int index2) {
//     int count = 0; // Variable untuk track current idx
//     addressPlaylist P1 = First(*PL); // Pointer ke elemen pertama
//     addressPlaylist P2 = NULL; // Pointer ke elemen kedua
//     addressPlaylist PrevP1 = NULL; // Pointer ke elemen sebelum P1

//     // cari elemen pertama untuk swap (P1) dan PrevP1
//     while (P1 != Nil_Playlist && count < index1) {
//         PrevP1 = P1;
//         P1 = Next(P1);
//         count++;
//     }

//     // kalau first index di luar batas, tidak usah lakukan apa2
//     if (P1 == Nil_Playlist) {
//         printf("Index %d di luar batas.\n", index1);
//         return;
//     }

//     count = 0; // Reset count
//     P2 = P1; // Set P2 ke P1

//     // cari elemen kedua untuk swap (P2)
//     while (P2 != Nil_Playlist && count < index2 - index1) {
//         P2 = Next(P2);
//         count++;
//     }

//     // kalau index kedua di luar batas, tidak usah lakukan apa2
//     if (P2 == Nil_Playlist) {
//         printf("Index %d di luar batas.\n", index2);
//         return;
//     }

//     if (PrevP1 != NULL) {
//         Next(PrevP1) = P2;
//     } else {
//         First(*PL) = P2;
//     }

//     Next(P1) = Next(P2);
//     Next(P2) = P1;
// }

// void DeleteSongByIndex(Playlist *PL, int index) {
//     int count = 0; // variabel untuk track
//     addressPlaylist P = First(*PL); // Pointer ke elemen pertama
//     addressPlaylist PrevP = NULL; // Pointer ke elemen sebelum P

//     // cari element untuk delete (P) dan (PrevP)
//     while (P != Nil_Playlist && count < index) {
//         PrevP = P;
//         P = Next(P);
//         count++;
//     }

//     // kalau indeks di luar batas, tidak usah lakukan apa2
//     if (P == Nil_Playlist) {
//         printf("Index %d di luar batas.\n", index);
//         return;
//     }

//     if (PrevP != NULL) {
//         Next(PrevP) = Next(P);
//     } else {
//         First(*PL) = Next(P);
//     }

//     // dealokasi memory untuk elemen yang dihapus
//     DealokasiPlaylist(&P);
// }

// content LaguFromPlaylist(Playlist PL, char* namePlaylist, int songKe)
// {
//     addressPlaylist P = First(PL);
//     content emptyContent; // Placeholder for an empty content

//     while (P != NULL && strCompare(PL.namePL, namePlaylist) != 0)
//     {
//         P = Next(P);
//     }

//     if (P != NULL)
//     {
//         int count = 0;
//         while (P != NULL && count < songKe)
//         {
//             P = Next(P);
//             count++;
//         }

//         if (P != NULL)
//         {
//             // Assuming Info(P) is of type content
//             return Info(P);
//         }
//     }

//     // Return an empty content if playlist or song is not found
//     emptyContent.lagu = NULL;
//     emptyContent.album = NULL;
//     emptyContent.penyanyi = NULL;

//     return emptyContent;
// }


Playlist* createPlaylist() {
    Playlist* playlist = (Playlist*)malloc(sizeof(Playlist));
    playlist->head = NULL;
    return playlist;
}

// Fungsi untuk menambah lagu ke dalam playlist
void addSong(Playlist* playlist, char* lagu, char* artist, char* album) {
    if (!playlist || !lagu || !artist || !album) {
        printf("Invalid input parameters.\n");
        return;
    }

    Node* newNode = (Node*)malloc(sizeof(Node));
    if (!newNode) {
        printf("Memory allocation failed.\n");
        return;
    }

    // Assuming strCopy is your custom string copy function
    newNode->data.lagu = (char*)malloc(strLength(lagu) + 1);
    newNode->data.artist = (char*)malloc(strLength(artist) + 1);
    newNode->data.album = (char*)malloc(strLength(album) + 1);

    if (!newNode->data.lagu || !newNode->data.artist || !newNode->data.album) {
        printf("Memory allocation failed.\n");
        free(newNode->data.lagu);
        free(newNode->data.artist);
        free(newNode->data.album);
        free(newNode);
        return;
    }

    strCopy(newNode->data.lagu, lagu);
    strCopy(newNode->data.artist, artist);
    strCopy(newNode->data.album, album);

    newNode->next = NULL;  // Using NULL as the end marker

    // Menambahkan lagu ke akhir playlist
    if (playlist->head == NULL) {
        playlist->head = newNode;
    } else {
        Node* current = playlist->head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newNode;
    }
}


// Fungsi untuk menampilkan seluruh lagu dalam playlist
void displayOnePlaylist(Playlist* playlist) {
    Node* current = playlist->head;
    int i = 1;
    while (current != NULL) {
        printf("%d. %s - %s - %s\n", i, current->data.lagu, current->data.artist, current->data.album);
        current = current->next;
        i +=1;
    }
}

// Fungsi untuk membersihkan seluruh playlist (menghapus semua lagu)
void clearOnePlaylist(Playlist* playlist) {
    Node* current = playlist->head;
    while (current != NULL) {
        Node* next = current->next;
        free(current);
        current = next;
    }
    playlist->head = NULL;
}

// Fungsi untuk membuat manajer playlist baru
PlaylistManager* createPlaylistManager() {
    PlaylistManager* manager = (PlaylistManager*)malloc(sizeof(PlaylistManager));
    manager->playlists = NULL;
    manager->numPlaylists = 0;
    return manager;
}

// Fungsi untuk menambah playlist baru
void addPlaylist(PlaylistManager* manager) {
    manager->numPlaylists++;
    manager->playlists = (Playlist**)realloc(manager->playlists, manager->numPlaylists * sizeof(Playlist*));
    manager->playlists[manager->numPlaylists - 1] = createPlaylist();
}

// Fungsi untuk menambah lagu ke dalam playlist
void addSongToPlaylist(PlaylistManager* manager, int playlistIndex, char* lagu, char* artist, char* album) {
    if (playlistIndex >= 0 && playlistIndex < manager->numPlaylists) {
        addSong(manager->playlists[playlistIndex], lagu, artist, album);
    } else {
        printf("Invalid playlist index.\n");
    }
}

// Fungsi untuk menampilkan seluruh lagu dalam playlist
void displayPlaylist(PlaylistManager* manager, int playlistIndex) {
    if (playlistIndex >= 0 && playlistIndex < manager->numPlaylists) {
        printf("Playlist %d:\n", playlistIndex + 1);
        displayOnePlaylist(manager->playlists[playlistIndex]);
    } else {
        printf("Invalid playlist index.\n");
    }
}

// Fungsi untuk membersihkan seluruh playlist (menghapus semua lagu)
void clearPlaylist(PlaylistManager* manager, int playlistIndex) {
    if (playlistIndex >= 0 && playlistIndex < manager->numPlaylists) {
        clearOnePlaylist(manager->playlists[playlistIndex]);
    } else {
        printf("Invalid playlist index.\n");
    }
}

// Fungsi untuk membersihkan seluruh manajer playlist (menghapus semua playlist)
void clearAllPlaylists(PlaylistManager* manager) {
    for (int i = 0; i < manager->numPlaylists; i++) {
        clearOnePlaylist(manager->playlists[i]);
    }
    free(manager->playlists);
    manager->playlists = NULL;
    manager->numPlaylists = 0;
}

// Function to retrieve a song from a playlist
// Function to retrieve a song from a specific playlist in the manager
Song LaguFromPlaylistManager(PlaylistManager* manager, int playlistIndex, int songIndex) {
    Song emptySong; // A default empty song in case of errors
    emptySong.lagu = NULL;
    emptySong.artist = NULL;
    emptySong.album = NULL;

    if (!manager || playlistIndex < 0 || playlistIndex >= manager->numPlaylists || songIndex < 0) {
        printf("Invalid input parameters.\n");
        return emptySong;
    }

    // Get the playlist from the manager
    Playlist* playlist = manager->playlists[playlistIndex];

    Node* current = playlist->head;
    int currentIndex = 0;

    while (current != NULL && currentIndex < songIndex) {
        current = current->next;
        currentIndex++;
    }

    if (current == NULL) {
        printf("Song not found in the playlist.\n");
        return emptySong;
    }

    // Assuming you have a custom function to copy a Song
    Song selectedSong;
    selectedSong.lagu = (char*)malloc(strLength(current->data.lagu) + 1);
    selectedSong.artist = (char*)malloc(strLength(current->data.artist) + 1);
    selectedSong.album = (char*)malloc(strLength(current->data.album) + 1);

    if (!selectedSong.lagu || !selectedSong.artist || !selectedSong.album) {
        printf("Memory allocation failed.\n");
        free(selectedSong.lagu);
        free(selectedSong.artist);
        free(selectedSong.album);
        return emptySong;
    }

    // Copy the data from the selected node to the Song structure
    strCopy(selectedSong.lagu, current->data.lagu);
    strCopy(selectedSong.artist, current->data.artist);
    strCopy(selectedSong.album, current->data.album);

    return selectedSong;
}


// Function to swap songs by index in a specific playlist
void swapSongsInPlaylist(PlaylistManager* manager, int playlistIndex, int songIndex1, int songIndex2) {
    if (!manager || playlistIndex < 0 || playlistIndex >= manager->numPlaylists) {
        printf("Invalid input parameters.\n");
        return;
    }

    Playlist* playlist = manager->playlists[playlistIndex];

    if (!playlist || songIndex1 < 0 || songIndex2 < 0) {
        printf("Invalid input parameters.\n");
        return;
    }

    // Initialize pointers to track nodes
    Node* prevSong1 = NULL;
    Node* song1 = playlist->head;
    Node* prevSong2 = NULL;
    Node* song2 = playlist->head;

    // Find the nodes corresponding to the specified indices
    for (int i = 0; i < songIndex1 && song1 != NULL; i++) {
        prevSong1 = song1;
        song1 = song1->next;
    }

    for (int i = 0; i < songIndex2 && song2 != NULL; i++) {
        prevSong2 = song2;
        song2 = song2->next;
    }

    // Check if nodes were found for the specified indices
    if (!song1 || !song2) {
        printf("Invalid song indices or songs not found.\n");
        return;
    }

    // Perform the swap by updating the next pointers
    if (prevSong1) {
        prevSong1->next = song2;
    } else {
        playlist->head = song2;
    }

    if (prevSong2) {
        prevSong2->next = song1;
    } else {
        playlist->head = song1;
    }

    Node* temp = song1->next;
    song1->next = song2->next;
    song2->next = temp;
}

// Function to delete a song by index in a specific playlist
void deleteSongInPlaylist(PlaylistManager* manager, int playlistIndex, int songIndex) {
    if (!manager || playlistIndex < 0 || playlistIndex >= manager->numPlaylists) {
        printf("Invalid input parameters.\n");
        return;
    }

    Playlist* playlist = manager->playlists[playlistIndex];

    if (!playlist || songIndex < 0) {
        printf("Invalid input parameters.\n");
        return;
    }

    Node* current = playlist->head;
    Node* prevSong = NULL;

    int currentIndex = 0;

    // Find the node corresponding to the specified index
    while (current != NULL && currentIndex < songIndex) {
        prevSong = current;
        current = current->next;
        currentIndex++;
    }

    // Check if the node was found for the specified index
    if (!current) {
        printf("Invalid song index or song not found.\n");
        return;
    }

    // Update the next pointer of the previous node or the playlist head
    if (prevSong) {
        prevSong->next = current->next;
    } else {
        playlist->head = current->next;
    }

    // Free the memory of the deleted node
    free(current->data.lagu);
    free(current->data.artist);
    free(current->data.album);
    free(current);
}
