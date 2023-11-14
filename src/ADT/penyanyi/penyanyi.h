#ifndef penyanyi_H
#define penyanyi_H
#include <stdio.h>
#include "../../boolean.h"
#include "../../adt/mesin/mesinkata.h"
#include "../../adt/album/album.h"
#include "../../adt/array/array.h"

// #define false 0
// #define true 1
#define NilPenyanyi 0
#define MaxElPenyanyi 100

// typedef int bool;
typedef char *keytype;
typedef Array valuetypePenyanyi;
typedef int addressPenyanyi;

typedef struct
{
    keytype Key;
    valuetypePenyanyi Value;
} infotypePenyanyi;

typedef struct
{
    infotypePenyanyi Elements[MaxElPenyanyi];
    addressPenyanyi Count;
} Penyanyi;

/* Definisi Penyanyi M kosong : M.Count = Nil */
/* M.Count = jumlah element Penyanyi */
/* M.Elements = tempat penyimpanan element Penyanyi */

/* I.S. Sembarang */
/* F.S. Membuat sebuah Penyanyi M kosong berkapasitas MaxElPenyanyi */
/* Ciri Penyanyi kosong : count bernilai Nil */
Penyanyi CreateEmptyPenyanyi();

/* Mengirim true jika Penyanyi M kosong*/
/* Ciri Penyanyi kosong : count bernilai Nil */
boolean IsEmptyPenyanyi(Penyanyi M);

/* Mengirim true jika Penyanyi M penuh */
/* Ciri Penyanyi penuh : count bernilai MaxElPenyanyi */
boolean IsFullPenyanyi(Penyanyi M);

/* Mengembalikan nilai value dengan key k dari M */
valuetypePenyanyi ValueInPenyanyi(Penyanyi M, keytype k);

/* Menambahkan Elmt sebagai elemen Penyanyi M. */
/* I.S. M mungkin kosong, M tidak penuh
        M mungkin sudah beranggotakan v dengan key k */
/* F.S. v menjadi anggota dari M dengan key k. Jika k sudah ada, operasi tidak dilakukan */
void InsertInPenyanyi(Penyanyi *M, keytype k, valuetypePenyanyi v);

/* Menghapus Elmt dari Penyanyi M. */
/* I.S. M tidak kosong
        element dengan key k mungkin anggota / bukan anggota dari M */
/* F.S. element dengan key k bukan anggota dari M */
void DeleteInPenyanyi(Penyanyi *M, keytype k);

/* Mengembalikan true jika k adalah member dari M */
boolean IsMemberInPenyanyi(Penyanyi M, keytype k);

/* Melakukan copy Elmt dari Album m2 ke m1. */
/* I.S. m1 dan m2 terdefinisi
/* F.S. elemen dari m2 dicopy ke m1 */
void CopyPenyanyi(Penyanyi *m1, Penyanyi m2);

void PrintAlbumPenyanyi(Penyanyi M, keytype k);

#endif
