#ifndef album_H
#define album_H
#include <stdio.h>
#include "../../boolean.h"
#include "../../adt/mesin/mesinkata.h"
#include "../../adt/set/set.h"
#include "../../adt/string/string.h"

// #define false 0
// #define true 1
#define NilAlbum 0
#define MaxElAlbum 100

// typedef int bool;
typedef char *keytype;
typedef Set valuetype;
typedef int addressAlbum;

typedef struct
{
    keytype Key;
    valuetype Value;
} infotypeAlbum;

typedef struct
{
    infotypeAlbum Elements[MaxElAlbum];
    addressAlbum Count;
} Album;

// Definisi Album M kosong : M.Count = Nil
// M.Count = jumlah element Album
// M.Elements = tempat penyimpanan element Album

// I.S. Sembarang
// F.S. Membuat sebuah Album M kosong berkapasitas MaxElAlbum
// Ciri Album kosong : count bernilai Nil
void CreateEmptyAlbum(Album *M);

// Mengirim true jika Album M kosong
// Ciri Album kosong : count bernilai Nil
boolean IsEmptyAlbum(Album M);

// Mengirim true jika Album M penuh
// Ciri Album penuh : count bernilai MaxElAlbum
boolean IsFullAlbum(Album M);

// Mengembalikan nilai value dengan key k dari M
valuetype ValueInAlbum(Album M, keytype k);

// Menambahkan Elmt sebagai elemen Album M.
// I.S. M mungkin kosong, M tidak penuh
// M mungkin sudah beranggotakan v dengan key k
// F.S. v menjadi anggota dari M dengan key k. Jika k sudah ada, operasi tidak dilakukan
void InsertInAlbum(Album *M, keytype k, valuetype v);
// Menghapus Elmt dari Album M.
// I.S. M tidak kosong
// element dengan key k mungkin anggota / bukan anggota dari M
// F.S. element dengan key k bukan anggota dari M
void DeleteInAlbum(Album *M, keytype k);

// Mengembalikan true jika k adalah member dari M
boolean IsMemberInAlbum(Album M, keytype k);

// Mengembalikan true jika m1 == m2
// boolean IsEQAlbum(Album m1, Album m2);

// Melakukan copy Elmt dari Album m2 ke m1.
// I.S. m1 dan m2 terdefinisi
// F.S. elemen dari m2 dicopy ke m1
void CopyAlbum(Album *m1, Album m2);

void PrintAlbumLagu(Album M, keytype k);

infotype LaguFromAlbum(Album M, keytype k, int id);

int IDAlbum(Album M, keytype k);

#endif