#include <stdio.h>
#include <stdlib.h>
#include "../../ADT/playlist/playlist.h"

/* PROTOTYPE */
/****************** TEST LIST KOSONG ******************/
boolean IsEmptyPlaylist (Playlist PL){
/* Mengirim true jika list kosong */
    return(First(PL) == Nil_Playlist);
}

/****************** PEMBUATAN LIST KOSONG ******************/
void CreateEmptyPlaylist (Playlist *PL){
/* I.S. sembarang             */
/* F.S. Terbentuk list kosong */
    First(*PL) = Nil_Playlist;
}

/****************** Manajemen Memori ******************/
addressPlaylist AlokasiPlaylist (content val){
    /* Mengirimkan address hasil alokasi sebuah elemen */
    /* Jika alokasi berhasil, maka address tidak nil, dan misalnya */
    /* menghasilkan P, maka info(P)=val, Next(P)=Nil */
    /* Jika alokasi gagal, mengirimkan Nil */
    //KAMUS LOKAL
    addressPlaylist P;

    //ALGORITMA
    P = (Elmtlist*) malloc (sizeof(Elmtlist));

    if(P != Nil_Playlist) {
        Info(P) = val;
        Next(P) = Nil_Playlist;
        return P;
    } else {
        return Nil_Playlist;
    }
}

void DealokasiPlaylist (addressPlaylist *P){
/* I.S. P terdefinisi */
/* F.S. P dikembalikan ke sistem */
/* Melakukan dealokasi/pengembalian address P */
    free(*P);
}

addressPlaylist SearchinPlaylist (Playlist PL, content val){
/* Mencari apakah ada elemen list dengan info(P)= val */
/* Jika ada, mengirimkan address elemen tersebut. */
/* Jika tidak ada, mengirimkan Nil */
    //KAMUS LOKAL
    addressPlaylist P;
    boolean found;

    //ALGORITMA
    P = First(PL);
    while(P != Nil_Playlist && !found){
        if(strCompare(Info(P).lagu, val.lagu) && strCompare(Info(P).album, val.album) && strCompare(Info(P).penyanyi, val.penyanyi)){
            found = true;
        } else {
            P = Next(P);
        }
    }

    if(found){
        return P;
    } else {
        return Nil_Playlist;
    }
}

/****************** PRIMITIF BERDASARKAN NILAI ******************/
/*** PENAMBAHAN ELEMEN ***/
void InsVFirst (Playlist *PL, content val){
/* I.S. PL mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen pertama dengan nilai val jika alokasi berhasil */
    //KAMUS LOKAL
    addressPlaylist P;

    //ALGORITMA
    P = AlokasiPlaylist(val);
    if(P != Nil_Playlist){
        Next(P) = First(*PL);
        First(*PL) = P;
    }
}
void InsVLast (Playlist *PL, content val){
/* I.S. PL mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen list di akhir: elemen terakhir yang baru */
/* bernilai val jika alokasi berhasil. Jika alokasi gagal: I.S.= F.S. */
    //KAMUS LOKAL
    addressPlaylist P;
    addressPlaylist last;

    //ALGORITMA
    if(IsEmptyPlaylist(*PL)){
        InsVFirst(PL, val);
    } else {
        P = AlokasiPlaylist(val);
        if(P != Nil_Playlist){
            last = First(*PL);
            while (Next(last) != Nil_Playlist){
                last = Next(last);
            }
            Next(last) = P;
        }
    }
}

/*** PENGHAPUSAN ELEMEN ***/
void DelVFirst (Playlist *PL, content *val){
/* I.S. Playlist PL tidak kosong  */
/* F.S. Elemen pertama list dihapus: nilai info disimpan pada val */
/*      dan alamat elemen pertama di-dealokasi */
    //KAMUS LOKAL
    addressPlaylist P;

    //ALGORITMA
    P = First(*PL);
    *val = Info(P);
    First(*PL) = Next(P);
    DealokasiPlaylist(&P);
}

void DelVLast (Playlist *PL, content *val){
/* I.S. list tidak kosong */
/* F.S. Elemen terakhir list dihapus: nilai info disimpan pada val */
/*      dan alamat elemen terakhir di-dealokasi */
    //KAMUS LOKAL
    addressPlaylist p;
    addressPlaylist prev;

    //ALGORITMA
    p = First(*PL);
    while(Next(p) != Nil_Playlist){
        prev = p;
        p = Next(p);
    }
    *val = Info(p);

    if(NbElmtPlaylist(*PL) == 1){
        First(*PL) = Nil_Playlist;
    } else {
        Next(prev) = Nil_Playlist;
    }
    DealokasiPlaylist(&p);
}

/****************** PRIMITIF BERDASARKAN ALAMAT ******************/
/*** PENAMBAHAN ELEMEN BERDASARKAN ALAMAT ***/
void InsertFirst (Playlist *PL, addressPlaylist P){
/* I.S. Sembarang, P sudah dialokasi  */
/* F.S. Menambahkan elemen ber-address P sebagai elemen pertama */
    //ALGORITMA
    if(P != Nil_Playlist){
        Next(P) = First(*PL);
        First(*PL) = P;
    }
}

void InsertAfter (Playlist *PL, addressPlaylist P, addressPlaylist Prec){
/* I.S. Prec pastilah elemen list dan bukan elemen terakhir, */
/*      P sudah dialokasi  */
/* F.S. Insert P sebagai elemen sesudah elemen beralamat Prec */
    //ALGORITMA
    if(P != Nil_Playlist){
        Next(P) = Next(Prec);
        Next(Prec) = P;
    }
}

void InsertLast (Playlist *PL, addressPlaylist P){
/* I.S. Sembarang, P sudah dialokasi  */
/* F.S. P ditambahkan sebagai elemen terakhir yang baru */
    // KAMUS LOKAL
    addressPlaylist last;

    // ALGORITMA
    if (IsEmptyPlaylist(*PL)){
        InsertFirst(PL, P);
    } else {
        if (last != Nil_Playlist) {
            last = First(*PL);
            while (Next(last) != Nil_Playlist) {
                last = Next(last);
            }
            Next(last) = P;
        }
    }
}

/*** PENGHAPUSAN SEBUAH ELEMEN ***/
void DelFirst (Playlist *PL, addressPlaylist *P){
/* I.S. Playlist tidak kosong */
/* F.S. P adalah alamat elemen pertama list sebelum penghapusan */
/*      Elemen list berkurang satu (mungkin menjadi kosong) */
/* First element yg baru adalah suksesor elemen pertama yang lama */
    *P = First(*PL);
    First(*PL) = Next(*P);
}

void DelP (Playlist *PL, content val){
/* I.S. Sembarang */
/* F.S. Jika ada elemen list beraddress P, dengan info(P)=val  */
/* Maka P dihapus dari list dan di-dealokasi */
/* Jika tidak ada elemen list dengan info(P)=val, maka list tetap */
/* Playlist mungkin menjadi kosong karena penghapusan */
    // KAMUS LOKAL
    addressPlaylist prev;
    addressPlaylist last;

    // ALGORITMA
    last = First(*PL);
    prev = Nil_Playlist;
    while (!strCompare(Info(last).lagu, val.lagu) || !strCompare(Info(last).album, val.album) || !strCompare(Info(last).penyanyi, val.penyanyi)) {
        prev = last;
        last = Next(last);
    }

    if (last == First(*PL)){
        First(*PL) = Next(last);
    }
    else{
        Next(prev) = Next(last);
    }
    DealokasiPlaylist(&last);
}

void DelLast (Playlist *PL, addressPlaylist *P){
/* I.S. Playlist tidak kosong */
/* F.S. P adalah alamat elemen terakhir list sebelum penghapusan  */
/*      Elemen list berkurang satu (mungkin menjadi kosong) */
/* Last element baru adalah predesesor elemen terakhir yg lama, */
/* jika ada */
    // KAMUS LOKAL
    addressPlaylist last;
    addressPlaylist prev;

    // ALGORITMA
    last = First(*PL);
    while (Next(last) != Nil_Playlist) {
        prev = last;
        last = Next(last);
    }
    *P = last;

    if (NbElmtPlaylist(*PL) == 1){
        First(*PL) = Nil_Playlist;
    } else {
        Next(prev) = Nil_Playlist;
    }
}

void DelAfter (Playlist *PL, addressPlaylist *Pdel, addressPlaylist Prec){
/* I.S. Playlist tidak kosong. Prec adalah anggota list  */
/* F.S. Menghapus Next(Prec): */
/*      Pdel adalah alamat elemen list yang dihapus  */
    *Pdel = Next(Prec);
    Next(Prec) = Next(*Pdel);
}

/****************** PROSES SEMUA ELEMEN LIST ******************/
void PrintInfo (Playlist PL){
/* I.S. Playlist mungkin kosong */
/* F.S. Jika list tidak kosong, isi list dicetak ke kanan: [e1,e2,...,en] */
/* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [1,20,30] */
/* Jika list kosong : menulis [] */
/* Tidak ada tambahan karakter apa pun di awal, akhir, atau di tengah terkecuali untuk newline di akhir output */
    // KAMUS LOKAL
    addressPlaylist p;

    // ALGORITMA
    if (IsEmptyPlaylist(PL)){
        printf("[]\n");
    } else {
        p = First(PL);
        printf("[");
        while (p != Nil_Playlist) {
            if (Next(p) != Nil_Playlist){
                printf("%d,", Info(p));
            }
            else{
                printf("%d]\n", Info(p));
            }
            p = Next(p);
        }
    }
}
int NbElmtPlaylist (Playlist PL){
/* Mengirimkan banyaknya elemen list; mengirimkan 0 jika list kosong */
    // KAMUS LOKAL
    int cnt = 0;
    addressPlaylist p;
    
    // ALGORITMA
    p = First(PL);
    while (p != Nil_Playlist) {
        p = Next(p);
        cnt++;
    }
    return cnt;
}

/****************** PROSES TERHADAP LIST ******************/

void InversList (Playlist *PL){
/* I.S. sembarang. */
/* F.S. elemen list dibalik : */
/* Elemen terakhir menjadi elemen pertama, dan seterusnya. */
/* Membalik elemen list, tanpa melakukan alokasi/dealokasi. */
    // KAMUS LOKAL
    addressPlaylist p, prev, last;

    // ALGORITMA
    p = First(*PL);
    prev = Nil_Playlist;
    while (p != Nil_Playlist) {
        last = p;
        p = Next(p);
        Next(last) = prev;
        prev = last;
    }

    First(*PL) = last;
}

void Konkat1 (Playlist *PL1, Playlist *PL2, Playlist *PL3){
/* I.S. PL1 dan PL2 sembarang */
/* F.S. PL1 dan PL2 kosong, PL3 adalah hasil konkatenasi PL1 & PL2 */
/* Konkatenasi dua buah list : PL1 dan PL2    */
/* menghasilkan PL3 yang baru (dengan elemen list PL1 dan PL2) */
/* dan PL1 serta PL2 menjadi list kosong.*/
/* Tidak ada alokasi/dealokasi pada prosedur ini */
    // KAMUS LOKAL
    addressPlaylist last;

    // ALGORITMA
    if (IsEmptyPlaylist(*PL1)){
        First(*PL3) = First(*PL2);
    } else {
        First(*PL3) = First(*PL1);
        last = First(*PL1);
        while (Next(last) != Nil_Playlist) {
            last = Next(last);
        }
        Next(last) = First(*PL2);
    }

    First(*PL1) = Nil_Playlist;
    First(*PL2) = Nil_Playlist;
}