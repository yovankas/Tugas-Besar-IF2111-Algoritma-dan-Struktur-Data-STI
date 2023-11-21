#ifndef playlist_H
#define playlist_H

#include <stdio.h>
#include <stdlib.h>
#include "../../boolean.h"
#include "../../adt/mesin/mesinkata.h"
#include "../../adt/array/array.h"
#include "../../adt/string/string.h"
#include "../word/word.h"

// #define Nil_Playlist NULL

// typedef char *name;
// typedef char *infotype;
// typedef struct tElmtlist *addressPlaylist;
// typedef struct content{
//     infotype lagu;
//     infotype album;
//     infotype penyanyi;
// } content;

// typedef struct tElmtlist{
//     content info;
//     addressPlaylist next;
// } Elmtlist;

// typedef struct{
//     name namePL;
//     int countisiPL;
//     addressPlaylist First;
// } Playlist;

// /* Definisi list : */
// /* Playlist kosong : First(PL) = Nil */
// /* Setiap elemen dengan address P dapat diacu Info(P), Next(P) */
// /* Elemen terakhir list : jika addressnya Last, maka Next(Last)=Nil */
// #define Info(P) (P)->info
// #define Next(P) (P)->next
// #define First(PL) ((PL).First)

// /* PROTOTYPE */
// /****************** TEST LIST KOSONG ******************/
// boolean IsEmptyPlaylist (Playlist PL);
// /* Mengirim true jika list kosong */

// /****************** PEMBUATAN LIST KOSONG ******************/
// void CreateEmptyPlaylist (Playlist *PL);
// /* I.S. sembarang             */
// /* F.S. Terbentuk list kosong */

// /****************** Manajemen Memori ******************/
// addressPlaylist AlokasiPlaylist (content val);
// /* Mengirimkan address hasil alokasi sebuah elemen */
// /* Jika alokasi berhasil, maka address tidak nil, dan misalnya */
// /* menghasilkan P, maka info(P)=val, Next(P)=Nil */
// /* Jika alokasi gagal, mengirimkan Nil */
// void DealokasiPlaylist (addressPlaylist *P);
// /* I.S. P terdefinisi */
// /* F.S. P dikembalikan ke sistem */
// /* Melakukan dealokasi/pengembalian address P */

// /****************** PENCARIAN SEBUAH ELEMEN LIST ******************/
// addressPlaylist SearchinPlaylist (Playlist PL, content val);
// /* Mencari apakah ada elemen list dengan info(P)= val */
// /* Jika ada, mengirimkan address elemen tersebut. */
// /* Jika tidak ada, mengirimkan Nil */

// /****************** PRIMITIF BERDASARKAN NILAI ******************/
// /*** PENAMBAHAN ELEMEN ***/
// void InsVFirst (Playlist *PL, content val);
// /* I.S. PL mungkin kosong */
// /* F.S. Melakukan alokasi sebuah elemen dan */
// /* menambahkan elemen pertama dengan nilai val jika alokasi berhasil */
// void InsVLast (Playlist *PL, content val);
// /* I.S. PL mungkin kosong */
// /* F.S. Melakukan alokasi sebuah elemen dan */
// /* menambahkan elemen list di akhir: elemen terakhir yang baru */
// /* bernilai val jika alokasi berhasil. Jika alokasi gagal: I.S.= F.S. */

// /*** PENGHAPUSAN ELEMEN ***/
// void DelVFirst (Playlist *PL, content *val);
// /* I.S. Playlist PL tidak kosong  */
// /* F.S. Elemen pertama list dihapus: nilai info disimpan pada val */
// /*      dan alamat elemen pertama di-dealokasi */
// void DelVLast (Playlist *PL, content *val);
// /* I.S. list tidak kosong */
// /* F.S. Elemen terakhir list dihapus: nilai info disimpan pada val */
// /*      dan alamat elemen terakhir di-dealokasi */

// /****************** PRIMITIF BERDASARKAN ALAMAT ******************/
// /*** PENAMBAHAN ELEMEN BERDASARKAN ALAMAT ***/
// void InsertFirst (Playlist *PL, addressPlaylist P);
// /* I.S. Sembarang, P sudah dialokasi  */
// /* F.S. Menambahkan elemen ber-address P sebagai elemen pertama */
// void InsertAfter (Playlist *PL, addressPlaylist P, addressPlaylist Prec);
// /* I.S. Prec pastilah elemen list dan bukan elemen terakhir, */
// /*      P sudah dialokasi  */
// /* F.S. Insert P sebagai elemen sesudah elemen beralamat Prec */
// void InsertLast (Playlist *PL, addressPlaylist P);
// /* I.S. Sembarang, P sudah dialokasi  */
// /* F.S. P ditambahkan sebagai elemen terakhir yang baru */

// /*** PENGHAPUSAN SEBUAH ELEMEN ***/
// void DelFirst (Playlist *PL, addressPlaylist *P);
// /* I.S. Playlist tidak kosong */
// /* F.S. P adalah alamat elemen pertama list sebelum penghapusan */
// /*      Elemen list berkurang satu (mungkin menjadi kosong) */
// /* First element yg baru adalah suksesor elemen pertama yang lama */
// void DelP (Playlist *PL, content val);
// /* I.S. Sembarang */
// /* F.S. Jika ada elemen list beraddress P, dengan info(P)=val  */
// /* Maka P dihapus dari list dan di-dealokasi */
// /* Jika tidak ada elemen list dengan info(P)=val, maka list tetap */
// /* Playlist mungkin menjadi kosong karena penghapusan */
// void DelLast (Playlist *PL, addressPlaylist *P);
// /* I.S. Playlist tidak kosong */
// /* F.S. P adalah alamat elemen terakhir list sebelum penghapusan  */
// /*      Elemen list berkurang satu (mungkin menjadi kosong) */
// /* Last element baru adalah predesesor elemen terakhir yg lama, */
// /* jika ada */
// void DelAfter (Playlist *PL, addressPlaylist *Pdel, addressPlaylist Prec);
// /* I.S. Playlist tidak kosong. Prec adalah anggota list  */
// /* F.S. Menghapus Next(Prec): */
// /*      Pdel adalah alamat elemen list yang dihapus  */

// /****************** PROSES SEMUA ELEMEN LIST ******************/
// void PrintInfoPlaylist (Playlist PL);
// /* I.S. Playlist mungkin kosong */
// /* F.S. Jika list tidak kosong, isi list dicetak ke kanan: [e1,e2,...,en] */
// /* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [1,20,30] */
// /* Jika list kosong : menulis [] */
// /* Tidak ada tambahan karakter apa pun di awal, akhir, atau di tengah terkecuali untuk newline di akhir output */
// int NbElmtPlaylist (Playlist PL);
// /* Mengirimkan banyaknya elemen list; mengirimkan 0 jika list kosong */

// /****************** PROSES TERHADAP LIST ******************/

// void InversList (Playlist *PL);
// /* I.S. sembarang. */
// /* F.S. elemen list dibalik : */
// /* Elemen terakhir menjadi elemen pertama, dan seterusnya. */
// /* Membalik elemen list, tanpa melakukan alokasi/dealokasi. */

// void Konkat1 (Playlist *PL1, Playlist *PL2, Playlist *PL3);
// /* I.S. PL1 dan PL2 sembarang */
// /* F.S. PL1 dan PL2 kosong, PL3 adalah hasil konkatenasi PL1 & PL2 */
// /* Konkatenasi dua buah list : PL1 dan PL2    */
// /* menghasilkan PL3 yang baru (dengan elemen list PL1 dan PL2) */
// /* dan PL1 serta PL2 menjadi list kosong.*/
// /* Tidak ada alokasi/dealokasi pada prosedur ini */

// void SwapSongsinPlaylist(Playlist *PL, addressPlaylist P1, addressPlaylist P2);
// /* I.S. P1 dan P2 berada di posisi awal masing-masing */
// /* F.S. P1 dan P2 bertukar posisi, P1 di posisi P2 dan viceversa */

// void SwapSongsByIndex(Playlist *PL, int index1, int index2);

// void DeleteSongByIndex(Playlist *PL, int index);

// content LaguFromPlaylist(Playlist PL, char* namePlaylist, int songKe);

typedef struct{
    char* lagu;
    char* artist;
    char* album;  
} Song;

typedef struct Node {
    Song data;
    struct Node* next;
} Node;

typedef struct{
    Node* head;
} Playlist ;

typedef struct {
    Playlist** playlists;
    int numPlaylists;
} PlaylistManager;

Playlist* createPlaylist() ;

void addSong(Playlist* playlist, char* lagu, char* artist, char* album);

void displayOnePlaylist(Playlist* playlist);

void clearOnePlaylist(Playlist* playlist);

PlaylistManager* createPlaylistManager();

void addPlaylist(PlaylistManager* manager);

// Fungsi untuk menambah lagu ke dalam playlist
void addSongToPlaylist(PlaylistManager* manager, int playlistIndex, char* lagu, char* artist, char* album);

// Fungsi untuk menampilkan seluruh lagu dalam playlist
void displayPlaylist(PlaylistManager* manager, int playlistIndex);

// Fungsi untuk membersihkan seluruh playlist (menghapus semua lagu)
void clearPlaylist(PlaylistManager* manager, int playlistIndex);

// Fungsi untuk membersihkan seluruh manajer playlist (menghapus semua playlist)
void clearAllPlaylists(PlaylistManager* manager);

Song LaguFromPlaylistManager(PlaylistManager* manager, int playlistIndex, int songIndex);

void swapSongsInPlaylist(PlaylistManager* manager, int playlistIndex, int songIndex1, int songIndex2);

void deleteSongInPlaylist(PlaylistManager* manager, int playlistIndex, int songIndex);

#endif