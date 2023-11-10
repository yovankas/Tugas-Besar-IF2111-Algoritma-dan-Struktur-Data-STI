/*
NIM : 18222034
NAMA : CHRISTOPER DANIEL
TANGGAL : 28 SEPTEMBER 2023
TOPIK PRAKTIKUM : Pra-Praktikum 4 - ARRAY DAN ADT LIST
DESKRIPSI : MENGIMPLEMENTASI FILE LIST.H
*/

#include <stdio.h>
#include "list.h"

/* ********** KONSTRUKTOR ********** */
/* Konstruktor: create list kosong */
List MakeList(){
    /* I.S. sembarang */
    /* F.S. Terbentuk list L kosong dengan kapasitas MaxEl */
    List L;
    L.A[MaxEl];
    L.A[0] = Mark;
    return L;
}

/* ********** TEST KOSONG/PENUH ********** */
/* *** Test list kosong *** */
boolean IsEmpty(List L){
    /* Mengirimkan true jika list L kosong, mengirimkan false jika tidak */
    return(L.A[0] == Mark);
}

/* *** Menghasilkan sebuah elemen *** */
ElType Get(List L, IdxType i){
    /* Prekondisi : list tidak kosong, i antara FirstIdx(T)..LastIdx(T) */
    /* Mengirimkan elemen list yang ke-i */
    return(L.A[i]);
}

/* *** Selektor SET : Mengubah nilai list dan elemen list *** */
void Set(List *L, IdxType i, ElType v){
    /* I.S. T terdefinisi, sembarang */
    /* F.S. Elemen T yang ke-i bernilai v */
    if (i > LastIdx(*L)) {
        L->A[Length(*L) + 1] = Mark;
    }
    L->A[i] = v;
}

/* ********** SELEKTOR ********** */
/* *** Banyaknya elemen *** */
int Length(List L){
    /* Mengirimkan banyaknya elemen efektif list */
    /* Mengirimkan nol jika list kosong */
    int i = 0;
    int total = 0;
    while((i < MaxEl-1) && (L.A[i] != Mark)){
        total++;
        i++;
    }
    if(L.A[i] != Mark){
        total++;
    }
    return total;
}

/* *** Selektor INDEKS *** */
IdxType FirstIdx(List L){
    /* Prekondisi : list L tidak kosong */
    /* Mengirimkan indeks elemen pertama */
    return 0;
}

IdxType LastIdx(List L){
    /* Prekondisi : list L tidak kosong */
    /* Mengirimkan indeks elemen terakhir */
    return(Length(L) - 1);
}

/* ********** Test Indeks yang valid ********** */
boolean IsIdxValid (List L, IdxType i){
    /* Prekondisi : i sembarang */
    /* Mengirimkan true jika i adalah indeks yang valid utk ukuran list */
    /* yaitu antara indeks yang terdefinisi untuk container*/
    return(i >= 0 && i <= MaxEl);
}

boolean IsIdxEff (List L, IdxType i){
    /* Prekondisi : i sembarang*/
    /* Mengirimkan true jika i adalah indeks yang terdefinisi utk list */
    /* yaitu antara FirstIdx(L)..LastIdx(L) */
    return(i >= FirstIdx(L) && i <= LastIdx(L));
}

/* ********** Operasi-operasi ********** */
boolean Search(List L, ElType X){
    /* Prekondisi : X sembarang */
    /* Mengirimkan true jika terdapat elemen X di dalam list */
    /* yaitu antara FirstIdx(L)..LastIdx(L) */
    int i = 0;
    boolean found = false;
    // ALGORITMA
    while ((i < Length(L)) && !found) {
        if (L.A[i] == X) {
            found = true;
        }
        i++;
    }
    return found;
}

void InsertFirst(List *L, ElType X){
    /* I.S. L terdefinisi, mungkin kosong. */
    /* F.S. v menjadi elemen pertama L. */
    InsertAt(L, X, 0);
}

void InsertAt(List *L, ElType X, IdxType i){
    /* I.S. L terdefinisi, tidak kosong, i merupakan indeks lojik yang valid di L. */
    /* F.S. v disisipkan dalam L pada indeks ke-i (bukan menimpa elemen di i). */
    int j;
    
    L->A[Length(*L) + 1] = Mark;
    for (j = Length(*L); j > i; j--) {
        L->A[j] = L->A[j - 1];
    }
    L->A[j] = X;
}

void InsertLast(List *L, ElType X){
    /* I.S. L terdefinisi, mungkin kosong. */
    /* F.S. v menjadi elemen terakhir L. */
    InsertAt(L, X, Length(*L));
}

void DeleteFirst(List *L){
    /* I.S. L terdefinisi, tidak kosong. */
    /* F.S. F diset dengan elemen pertama L, elemen pertama L dihapus dari L. */
    DeleteAt(L,0);
}

void DeleteAt(List *L, IdxType i){
    /* I.S. L terdefinisi, tidak kosong, i merupakan indeks lojik yang valid di L. */
    /* F.S. Elemen L pada indeks ke-i dihapus dari L. */
    int j;
    
    for (j = i; j < Length(*L) - 1; j++) {
        L->A[j] = L->A[j + 1];
    }
    L->A[j] = Mark;
}

void DeleteLast(List *L){
    /* I.S. L terdefinisi, tidak kosong. */
    /* F.S. F diset dengan elemen terakhir L, elemen terakhir L dihapus dari L. */
    DeleteAt(L, Length(*L) - 1);
}

List Concat(List L1, List L2){
    /* Prekondisi : L1 dan L2 tidak kosong */
    /* Mengirimkan sebuah List yang merupakan gabungan dari L1 dan L2 */
    /* Urutan elemen terisi dari L1, lalu L2 */
    /* Contoh : L1 : [1, 2]; L2 : [3, 4]; Mengembalikan [1, 2, 3, 4] */
    int i, j;
    List ConcatL;
    
    for (i = 0; i < Length(L1); i++) {
        ConcatL.A[i] = L1.A[i];
    }
    for (j = 0; j < Length(L2); j++) {
        ConcatL.A[i + j] = L2.A[j];
    }
    ConcatL.A[i + j] = Mark;
    return ConcatL;
}