/*
NIM: 18222034
NAMA: CHRISTOPER DANIEL
TANGGAL: 25 OKTOBER 2023
TOPIK: PRA-PRAKTIKUM 7 - STACK
DESKRIPSI: IMPLEMENTASI STACK.H
*/

#include <stdio.h>
#include "stack.h"

/* ************ Prototype ************ */
/* *** Konstruktor/Kreator *** */
void CreateEmpty(Stack *S){
/* I.S. sembarang; */
/* F.S. Membuat sebuah stack S yang kosong berkapasitas MaxEl */
/* jadi indeksnya antara 0..MaxEl-1 (inklusif) */
/* Ciri stack kosong : TOP bernilai Nil */

    //ALGORITMA
    S->TOP = Nil;
}

/* ************ Predikat Untuk test keadaan KOLEKSI ************ */
boolean IsEmpty(Stack S){
/* Mengirim true jika Stack kosong: lihat definisi di atas */

    //ALGORITMA
    return(S.TOP == Nil);
}

boolean IsFull(Stack S){
/* Mengirim true jika tabel penampung nilai elemen stack penuh */

    //ALGORITMA
    return(S.TOP == MaxEl - 1);
}

/* ************ Menambahkan sebuah elemen ke Stack ************ */
void Push(Stack * S, infotype X){
/* Menambahkan X sebagai elemen Stack S. */
/* I.S. S mungkin kosong, tabel penampung elemen stack TIDAK penuh */
/* F.S. TOP bertambah 1, X menjadi TOP yang baru, */

    //ALGORITMA
    S->TOP += 1;
    
    S->T[S->TOP] = X;
}

/* ************ Menghapus sebuah elemen Stack ************ */
void Pop(Stack * S, infotype* X){
/* Menghapus X dari Stack S. */
/* I.S. S  tidak mungkin kosong */
/* F.S. X adalah nilai elemen TOP yang lama, TOP berkurang 1 */

    //ALGORITMA
    *X = S->T[S->TOP];
    S->TOP -= 1;
}