#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "array.h"

/* ********** KONSTRUKTOR ********** */
/* Konstruktor : create tabel kosong */
#define BUFFER(arr) (arr).TI
#define NEFF(arr) (arr).Neff

/* I.S. sembarang */
/* F.S. Terbentuk tabel T kosong dengan kapasitas IdxMax-IdxMin+1 */
Array CreateArray()
{
    Array T;
    NEFF(T) = 0;
    return T;
}

/* ********** SELEKTOR ********** */
/* *** Banyaknya elemen *** */
/* Mengirimkan banyaknya elemen efektif tabel */
/* Mengirimkan nol jika tabel kosong */
/* *** Daya tampung container *** */
int NbElmt(Array T)
{
    return NEFF(T);
}

/* Mengirimkan maksimum elemen yang dapat ditampung oleh tabel */
int MaxNbEl(Array T)
{
    return IdxMax - IdxMin + 1;
}

/* *** Selektor INDEKS *** */
/* Prekondisi : Tabel T tidak kosong */
/* Mengirimkan indeks elemen pertama */
IdxType GetFirstIdx(Array T)
{
    return IdxMin;
}

/* Prekondisi : Tabel T tidak kosong */
/* Mengirimkan indeks elemen terakhir */
IdxType GetLastIdx(Array T)
{
    return NEFF(T);
}

/* *** Menghasilkan sebuah elemen *** */
/* Prekondisi : Tabel tidak kosong, i antara FirstIdx(T)..LastIdx(T) */
/* Mengirimkan elemen tabel yang ke-i */
ElType GetElmt(Array T, IdxType i)
{
    return BUFFER(T)[i];
}

/* *** Selektor SET : Mengubah nilai TABEL dan elemen tabel *** */
/* Untuk type private/limited private pada bahasa tertentu */
/* I.S. Tin terdefinisi, sembarang */
/* F.S. Tout berisi salinan Tin */
/* Assignment THsl -> Tin */
void SetTab(Array Tin, Array *Tout)
{
    CreateArray(Tout);
    for (int i = IdxMin; i <= GetLastIdx(Tin); i++)
    {
        strcpy(BUFFER(*Tout)[i], BUFFER(Tin)[i]);
    }
    NEFF(*Tout) = NEFF(Tin);
}

/* I.S. T terdefinisi, sembarang */
/* F.S. Elemen T yang ke-i bernilai v */
/* Mengeset nilai elemen tabel yang ke-i sehingga bernilai v */
void SetEl(Array *T, IdxType i, ElType v)
{
    BUFFER(*T)[i] = (char *)malloc((strlen(v) + 1) * sizeof(char));
    strcpy(BUFFER(*T)[i], v);
    if (i > GetLastIdx(*T))
    {
        NEFF(*T)
        ++;
    }
}

/* I.S. T terdefinisi, sembarang */
/* F.S. Nilai indeks efektif T bernilai N */
/* Mengeset nilai indeks elemen efektif sehingga bernilai N */
void SetNeff(Array *T, IdxType N)
{
    NEFF(*T) = N;
}

/* ********** Test Indeks yang valid ********** */
/* Prekondisi : i sembarang */
/* Mengirimkan true jika i adalah indeks yang valid utk ukuran tabel */
/* yaitu antara indeks yang terdefinisi utk container*/
boolean IsIdxValid(Array T, IdxType i)
{
    return IdxMax >= i && IdxMin <= i;
}

/* Prekondisi : i sembarang*/
/* Mengirimkan true jika i adalah indeks yang terdefinisi utk tabel */
/* yaitu antara FirstIdx(T)..LastIdx(T) */
boolean IsIdxEff(Array T, IdxType i)
{
    return NEFF(T) >= i && IdxMin <= i;
}

/* ********** TEST KOSONG/PENUH ********** */
/* *** Test tabel kosong *** */
/* Mengirimkan true jika tabel T kosong, mengirimkan false jika tidak */
boolean IsEmpty(Array T)
{
    return NEFF(T) == 0;
}

/* *** Test tabel penuh *** */
/* Mengirimkan true jika tabel T penuh, mengirimkan false jika tidak */
boolean IsFull(Array T)
{
    return NEFF(T) == IdxMax;
}

void copyArray(Array *destination, Array source)
{
    // Copy the elements one by one.
    for (int i = 0; i <= source.Neff; ++i)
    {
        destination->TI[i] = source.TI[i];
    }

    // Copy the count.
    destination->Neff = source.Neff;
}

/* ********** BACA dan TULIS dengan INPUT/OUTPUT device ********** */
void PrintArrayPenyanyi (Array T) {
/* Proses : Menuliskan isi tabel dengan traversal */
/* I.S. T boleh kosong */
/* F.S. Jika T tidak kosong : indeks dan elemen tabel ditulis berderet ke bawah */
/* Jika isi tabel [1,2,3] maka akan diprint
1. 1
2. 2
3. 3
*/
/* Jika T kosong : Hanya menulis "Tabel kosong" */
    if (IsEmpty(T)) {
        printf("Tidak ada Penyanyi\n");
    }
    else {
        // printf("Daftar Penyanyi:\n");
        IdxType i;
        for (i = 0; i <= NbElmt(T) ; i++) {
            printf("%d. %s\n", i+1, BUFFER(T)[i]);
        }
    }
}