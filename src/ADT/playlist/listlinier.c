#include <stdio.h>
#include "listlinier.h"

/* PROTOTYPE */
/****************** TEST LIST KOSONG ******************/
boolean IsEmpty (List L){
    return(First(L) == Nil); 
}

/****************** PEMBUATAN LIST KOSONG ******************/
void CreateEmpty (List *L){
    First(*L) = Nil;
}

/****************** Manajemen Memori ******************/
address Alokasi (infotype X){
    //KAMUS LOKAL
    address p;

    //ALGORITMA
    p = (ElmtList*) malloc (sizeof(ElmtList));

    if(p != Nil) {
        Info(p) = X;
        Next(p) = Nil;
        return p;
    } else {
        return Nil;
    }
}

void Dealokasi (address *P){
    free(*P);
}

/****************** PENCARIAN SEBUAH ELEMEN LIST ******************/
address Search (List L, infotype X){
    //KAMUS LOKAL
    address p;
    boolean found;

    //ALGORITMA
    p = First(L);
    while(p != Nil && !found){
        if(Info(p) == X){
            found = true;
        } else {
            p = Next(p);
        }
    }

    if(found){
        return p;
    } else {
        return Nil;
    }
}

/****************** PRIMITIF BERDASARKAN NILAI ******************/
/*** PENAMBAHAN ELEMEN ***/
void InsVFirst (List *L, infotype X){
    //KAMUS LOKAL
    address p;

    //ALGORITMA
    p = Alokasi(X);
    if(p != Nil){
        Next(p) = First(*L);
        First(*L) = p;
    }
}

void InsVLast (List *L, infotype X){
    //KAMUS LOKAL
    address p;
    address last;

    //ALGORITMA
    if(IsEmpty(*L)){
        InsVFirst(L, X);
    } else {
        p = Alokasi(X);
        if(p != Nil){
            last = First(*L);
            while (Next(last) != Nil){
                last = Next(last);
            }
            Next(last) = p;
        }
    }
}

/*** PENGHAPUSAN ELEMEN ***/
void DelVFirst (List *L, infotype *X){
    //KAMUS LOKAL
    address p;

    //ALGORITMA
    p = First(*L);
    *X = Info(p);
    First(*L) = Next(p);
    Dealokasi(&p);
}

void DelVLast (List *L, infotype *X){
    //KAMUS LOKAL
    address p;
    address prev;

    //ALGORITMA
    p = First(*L);
    while(Next(p) != Nil){
        prev = p;
        p = Next(p);
    }
    *X = Info(p);

    if(NbElmt(*L) == 1){
        First(*L) = Nil;
    } else {
        Next(prev) = Nil;
    }
    Dealokasi(&p);
}

/****************** PRIMITIF BERDASARKAN ALAMAT ******************/
/*** PENAMBAHAN ELEMEN BERDASARKAN ALAMAT ***/
void InsertFirst (List *L, address P){
    //ALGORITMA
    if(P != Nil){
        Next(P) = First(*L);
        First(*L) = P;
    }
}
void InsertAfter (List *L, address P, address Prec){
    //ALGORITMA
    if(P != Nil){
        Next(P) = Next(Prec);
        Next(Prec) = P;
    }
}
void InsertLast (List *L, address P){
    // KAMUS LOKAL
    address last;

    // ALGORITMA
    if (IsEmpty(*L)){
        InsertFirst(L, P);
    } else {
        if (last != Nil) {
            last = First(*L);
            while (Next(last) != Nil) {
                last = Next(last);
            }
            Next(last) = P;
        }
    }
}

/*** PENGHAPUSAN SEBUAH ELEMEN ***/
void DelFirst (List *L, address *P){
    *P = First(*L);
    First(*L) = Next(*P);
}
void DelP (List *L, infotype X){
    // KAMUS LOKAL
    address prev;
    address last;

    // ALGORITMA
    last = First(*L);
    prev = Nil;
    while (Info(last) != X) {
        prev = last;
        last = Next(last);
    }

    if (last == First(*L)){
        First(*L) = Next(last);
    }
    else{
        Next(prev) = Next(last);
    }
    Dealokasi(&last);
}
void DelLast (List *L, address *P){
    // KAMUS LOKAL
    address last;
    address prev;

    // ALGORITMA
    last = First(*L);
    while (Next(last) != Nil) {
        prev = last;
        last = Next(last);
    }
    *P = last;

    if (NbElmt(*L) == 1){
        First(*L) = Nil;
    } else {
        Next(prev) = Nil;
    }
}
void DelAfter (List *L, address *Pdel, address Prec){
    *Pdel = Next(Prec);
    Next(Prec) = Next(*Pdel);
}

/****************** PROSES SEMUA ELEMEN LIST ******************/
void PrintInfo (List L){
    // KAMUS LOKAL
    address p;

    // ALGORITMA
    if (IsEmpty(L)){
        printf("[]\n");
    } else {
        p = First(L);
        printf("[");
        while (p != Nil) {
            if (Next(p) != Nil){
                printf("%d,", Info(p));
            }
            else{
                printf("%d]\n", Info(p));
            }
            p = Next(p);
        }
    }
}
int NbElmt (List L){
    // KAMUS LOKAL
    int cnt = 0;
    address p;
    
    // ALGORITMA
    p = First(L);
    while (p != Nil) {
        p = Next(p);
        cnt++;
    }
    return cnt;
}

/*** Prekondisi untuk Max/Min/rata-rata : List tidak kosong ***/
infotype Max (List L){
    // KAMUS LOKAL
    int max;
    address p;

    // ALGORITMA
    p = First(L);
    max = Info(p);
    while (p != Nil) {
        if (Info(p) > max){
            max = Info(p);
        }
        p = Next(p);
    }
    return max;
}
address AdrMax (List L){
    // KAMUS LOKAL
    address p;
    infotype max = Max(L);

    // ALGORITMA
    p = First(L);
    while (Info(p) != max) {
        p = Next(p);
    }
    return p;
}
infotype Min (List L){
    //KAMUS LOKAL
    int min;
    address p;

    // ALGORITMA
    p = First(L);
    min = Info(p);
    while (p != Nil) {
        if (Info(p) < min){
            min = Info(p);
        }
        p = Next(p);
    }
    return min;
}
address AdrMin (List L){
    // KAMUS LOKAL
    address p;
    infotype min = Min(L);

    // ALGORITMA
    p = First(L);
    while (Info(p) != min) {
        p = Next(p);
    }
    return p;
}
float Average (List L){
    // KAMUS LOKAL
    float sum = 0, cnt = 0;
    address p;

    // ALGORITMA
    p = First(L);
    while (p != Nil) {
        sum += Info(p);
        p = Next(p);
        cnt++;
    }
    return sum/cnt;
}

/****************** PROSES TERHADAP LIST ******************/

void InversList (List *L){
    // KAMUS LOKAL
    address p, prev, last;

    // ALGORITMA
    p = First(*L);
    prev = Nil;
    while (p != Nil) {
        last = p;
        p = Next(p);
        Next(last) = prev;
        prev = last;
    }

    First(*L) = last;
}

void Konkat1 (List *L1, List *L2, List *L3){
    // KAMUS LOKAL
    address last;

    // ALGORITMA
    if (IsEmpty(*L1)){
        First(*L3) = First(*L2);
    } else {
        First(*L3) = First(*L1);
        last = First(*L1);
        while (Next(last) != Nil) {
            last = Next(last);
        }
        Next(last) = First(*L2);
    }

    First(*L1) = Nil;
    First(*L2) = Nil;
}