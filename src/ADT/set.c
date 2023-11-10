/*
NIM: 18222034
NAMA: CHRISTOPER DANIEL
TANGGAL: 1 NOVEMBER 2023
TOPIK: PRA-PRAKTIKUM 8 - SET, MAP, HASHMAP
DESKRIPSI: IMPLEMENTASI SET.H
*/

#include <stdio.h>
#include "set.h"

/* *** Konstruktor/Kreator *** */
void CreateEmpty(Set *S){
/* I.S. Sembarang */
/* F.S. Membuat sebuah Set S kosong berkapasitas MaxEl */
/* Ciri Set kosong : count bernilai Nil */

    //ALGORITMA
    S->Count = Nil;
}

/* ********* Predikat Untuk test keadaan KOLEKSI ********* */
boolean IsEmpty(Set S){
/* Mengirim true jika Set S kosong*/
/* Ciri Set kosong : count bernilai Nil */

    //ALGORITMA
    return(S.Count == Nil);
}

boolean IsFull(Set S){
/* Mengirim true jika Set S penuh */
/* Ciri Set penuh : count bernilai MaxEl */

    //ALGORITMA
    return(S.Count == MaxEl);
}


/* ********** Operator Dasar Set ********* */
void Insert(Set *S, infotype Elmt){
/* Menambahkan Elmt sebagai elemen Set S. */
/* I.S. S mungkin kosong, S tidak penuh
        S mungkin sudah beranggotakan Elmt */
/* F.S. Elmt menjadi anggota dari S. Jika Elmt sudah merupakan anggota, operasi tidak dilakukan */

    //KAMUS LOKAL
    int i;
    boolean same;

    //ALGORITMA
    i = 0;
    same = false;
    while(i < S->Count && !same){
        if(S->Elements[i] == Elmt){
            same = true;
        }
        i++;
    }

    if(!same){
        S->Elements[S->Count] = Elmt;
        S->Count += 1;
    }
}

void Delete(Set *S, infotype Elmt){
/* Menghapus Elmt dari Set S. */
/* I.S. S tidak kosong
        Elmt mungkin anggota / bukan anggota dari S */
/* F.S. Elmt bukan anggota dari S */

    //KAMUS LOKAL
    int i, j;
    boolean exist;

    //ALGORITMA
    exist = false;
    i = 0;
    while(i < S->Count && !exist){
        if(S->Elements[i] == Elmt){
            exist = true;
        } else {
            i++;
        }
    }

    for(j = i; j < S->Count; j++){
        S->Elements[i] = S->Elements[i+1];
    }
    S->Count -= 1;

}


boolean IsMember(Set S, infotype Elmt){
/* Mengembalikan true jika Elmt adalah member dari S */

    //KAMUS LOKAL
    int i;
    boolean exist;

    //ALGORITMA
    exist = false;
    i = 0;
    while(i < S.Count && !exist){
        if(S.Elements[i] == Elmt){
            exist = true;
        }
        i++;
        
    }
    return exist;
}