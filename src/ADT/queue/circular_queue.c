#include <stdio.h>
#include "circular_queue.h"

/* ********* Prototype ********* */
boolean IsEmptyQueue (Queue Q){
/* Mengirim true jika Q kosong */
/* yaitu ketika idxHead=IDX_UNDEF dan idxTail=IDX_UNDEF */

    //ALGORITMA
    return (Q.idxHead == IDX_UNDEF && Q.idxTail == IDX_UNDEF);
}

boolean IsFullQueue (Queue Q){
/* Mengirim true jika tabel penampung elemen Q sudah penuh */
/* yaitu ketika idxHead=0 dan idxTail=IDX_MAX atau idxHead=idxTail+1 ketika idxHead > idxTail */

    //ALGORITMA
    return (Length(Q) == IDX_MAX + 1);
}
int Length (Queue Q){
/* Mengirimkan banyaknya elemen Q, 0 jika kosong */

    //ALGORITMA
    if (IsEmptyQueue(Q)){
        return 0;
    } else if (Q.idxHead <= Q.idxTail){
        return (Q.idxTail - Q.idxHead + 1);
    } else {
        return (Q.idxTail - Q.idxHead + 1 + (IDX_MAX + 1));
    }
}

/* *** Kreator *** */
void CreateQueue (Queue * Q){
/* I.S. sembarang */
/* F.S. mengembalikan Q kosong dengan kondisi sbb: */
/* - idxHead=IDX_UNDEF; */
/* - idxTail=IDX_UNDEF. */

    //ALGORITMA
    Q->idxHead = IDX_UNDEF;
    Q->idxTail = IDX_UNDEF;
}


/* *** Primitif Add/Delete *** */
void enqueue (Queue * Q, ElTypeQueue X){
/* Proses: Menambahkan X pada Q dengan aturan FIFO */
/* I.S. Q mungkin kosong, tabel penampung elemen Q TIDAK penuh */
/* F.S. Tail "maju" dengan mekanisme circular buffer,
        X menjadi idxTail yang baru
        Jika Q kosong, idxHead dimulai dari 0 */
    
    //ALGORITMA
    if (Q->idxHead == IDX_UNDEF && Q->idxTail == IDX_UNDEF) {
        Q->idxHead = 0;
        Q->idxTail = 0;
    } else {
        Q->idxTail = (Q->idxTail + 1) % (IDX_MAX + 1);
    }
    Q->Tab[Q->idxTail].artist = X.artist;
    Q->Tab[Q->idxTail].album = X.album;
    Q->Tab[Q->idxTail].song = X.song;
}

ElTypeQueue dequeue (Queue * Q){
/* Proses: Menghapus idxHead pada Q dengan aturan FIFO, lalu mengembalikan nilainya */
/* I.S. Q tidak mungkin kosong */
/* F.S. mengembalikan nilai Q pada idxHead;
        Head "maju" dengan mekanisme circular buffer;
        Q mungkin kosong */

    //KAMUS LOKAL
    ElTypeQueue X;

    // ALGORITMA
    X.artist = Q->Tab[Q->idxHead].artist;
    X.album = Q->Tab[Q->idxHead].album;
    X.song = Q->Tab[Q->idxHead].song;
    if (Q->idxHead == Q->idxTail) {
        Q->idxHead = IDX_UNDEF;
        Q->idxTail = IDX_UNDEF;
    } else {
        Q->idxHead = (Q->idxHead + 1) % (IDX_MAX + 1);
    }
}

/* *** Display Queue *** */
void displayQueue(Queue Q){
/* Proses : Menuliskan isi Queue dengan traversal dan mekanisme circular buffer; */
/* Queue ditulis di antara kurung siku; antara dua elemen dipisahkan dengan separator "koma" */
/* I.S. Q boleh kosong */
/* F.S. Jika Q tidak kosong: [e1,e2,...,en] */
/* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [1,20,30] */
/* Jika Queue kosong : menulis [] */
/* Note: Output mengandung newline */
    //KAMUS
    int i, idx;

    // ALGORITMA
    if (Q.idxHead == IDX_UNDEF && Q.idxTail == IDX_UNDEF) {
        printf("Your queue is empty.\n");
    } 
    else if (Q.idxHead+1 == IDX_UNDEF){
        printf("Your queue is empty.\n");
    }
    else {
        if (Q.idxHead <= Q.idxTail) 
        {
            for (i = Q.idxHead+1; i <= Q.idxTail; i++) 
            {
                printf("%d. %s - %s - %s\n", i-Q.idxHead+1, Q.Tab[i].artist, Q.Tab[i].song, Q.Tab[i].album);
            }
        } else {
            for (i = Q.idxHead+1; i < (IDX_MAX + 1); i++) {
                printf("%d. %s - %s - %s\n", i-Q.idxHead+1, Q.Tab[i].artist, Q.Tab[i].song, Q.Tab[i].album);
            }
            for (i = 0; i <= Q.idxTail; i++) {
                printf("%d. %s - %s - %s\n", IDX_MAX-Q.idxHead+i+1, Q.Tab[i].artist, Q.Tab[i].song, Q.Tab[i].album);
            }
        }
    }
}