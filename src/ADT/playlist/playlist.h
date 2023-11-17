#ifndef playlist_H
#define playlist_H

#include <stdio.h>
#include "../../boolean.h"
#include "../../adt/mesin/mesinkata.h"
#include "../../adt/array/array.h"
#include "../../ADT/set/set.h"

// #define false 0
// #define true 1
#define NilPlaylist 0
#define MaxElPlaylist 100

typedef int keytype;
typedef Set valuetype;
typedef int addressPlaylist;

typedef struct{
    keytype Key;
    valuetype Value;
} infotypePlaylist;

typedef struct{
    infotypePlaylist Elements[MaxElPlaylist];
    addressPlaylist Count;
} Playlist;

/* Definisi Playlist PL kosong : PL.Count = Nil */
/* PL.Count = jumlah element Playlist */
/* PL.Elements = tempat penyimpanan element Playlist */

/* ********* Prototype ********* */

/* *** Konstruktor/Kreator *** */
void CreateEmpty_Playlist(Playlist *PL);
/* I.S. Sembarang */
/* F.S. Membuat sebuah Playlist PL kosong berkapasitas MaxEl */
/* Ciri Playlist kosong : count bernilai Nil */

/* ********* Predikat Untuk test keadaan KOLEKSI ********* */
boolean IsEmpty_Playlist(Playlist PL);
/* Mengirim true jika Playlist PL kosong*/
/* Ciri Playlist kosong : count bernilai Nil */

boolean IsFull_Playlist(Playlist PL);
/* Mengirim true jika Playlist PL penuh */
/* Ciri Playlist penuh : count bernilai MaxEl */

/* ********** Operator Dasar Playlist ********* */
valuetype Value_Playlist(Playlist PL, keytype k);
/* Mengembalikan nilai value dengan key k dari PL */
/* Jika tidak ada key k pada PL, akan mengembalikan Undefined */

void Insert_Playlist(Playlist *PL, keytype k, valuetype v);
/* Menambahkan Elmt sebagai elemen Playlist PL. */
/* I.S. PL mungkin kosong, PL tidak penuh
        PL mungkin sudah beranggotakan v dengan key k */
/* F.S. v menjadi anggota dari PL dengan key k. Jika k sudah ada, operasi tidak dilakukan */

void Delete_Playlist(Playlist *PL, keytype k);
/* Menghapus Elmt dari Playlist PL. */
/* I.S. PL tidak kosong
        element dengan key k mungkin anggota / bukan anggota dari PL */
/* F.S. element dengan key k bukan anggota dari PL */

boolean IsMember_Playlist(Playlist PL, keytype k);
/* Mengembalikan true jika k adalah member dari PL */

void Copy_Playlist(Playlist *PL1, Playlist PL2);
/* Melakukan copy Elmt dari Playlist PL2 ke PL1. */
/* I.S. PL1 dan PL2 terdefinisi
/* F.S. elemen dari PL2 dicopy ke PL1 */

void PrintPlaylistLagu(Playlist PL, keytype k);\
/* Melakukan print playlist*/

#endif