#include <stdio.h>
#include "playlist.h"

/* *** Konstruktor/Kreator *** */
void CreateEmpty_Playlist(Playlist *PL){
    PL->Count = NilPlaylist;
}

/* ********* Predikat Untuk test keadaan KOLEKSI ********* */
boolean IsEmpty_Playlist(Playlist PL){
    return (PL.Count == NilPlaylist);
}

boolean IsFull_Playlist(Playlist PL){
    return (PL.Count == MaxElPlaylist);
}

/* ********** Operator Dasar Playlist ********* */
valuetype Value_Playlist(Playlist PL, keytype k){
    //KAMUS LOKAL
    int i = 0;
    boolean found = false;

    //ALGORITMA
    while(i < PL.Count && !found){
        if(PL.Elements[i].Key == k){
            found = true;
        } else {
            i++;
        }
    }

    if(found){
        return(PL.Elements[i].Value);
    }
}

void Insert_Playlist(Playlist *PL, keytype k, valuetype v){
    //KAMUS LOKAL
    int i;
    boolean found;

    //ALGORITMA
    found = false;
    i = 0;
    while(i < PL->Count && !found){
        if(PL->Elements[i].Key == k){
            found = true;
        } else {
            i++;
        }
    }

    if(!found){
        PL->Elements[PL->Count].Key = k;
        PL->Elements[PL->Count].Value = v;
        PL->Count += 1;
    }
}

void Delete_Playlist(Playlist *PL, keytype k){
    //KAMUS LOKAL
    int i, j;
    boolean found;

    //ALGORITMA
    found = false;
    i = 0;
    while(i < PL->Count && !found){
        if(PL->Elements[i].Key == k){
            found = true;
        } else {
            i++;
        }
    }
    if(found){
        for(j = i; j < PL->Count; j++){
            PL->Elements[j] = PL->Elements[j+1];
        }
        PL->Count -= 1;
    }
}

boolean IsMember_Playlist(Playlist PL, keytype k){
    //KAMUS LOKAL
    int i;
    boolean found;

    //ALGORITMA
    found = false;
    i = 0;
    while(i < PL.Count && !found){
        if(PL.Elements[i].Key == k){
            found = true;
        } else {
            i++;
        }
    }
    return found;
}

void Copy_Playlist(Playlist *PL1, Playlist PL2){
    CreateEmpty_Playlist(PL1);
    PL1->Count = PL2.Count;
    for (int i = 1; i <= PL2.Count; i++) {
        PL1->Elements[i] = PL2.Elements[i];
    }
}

void PrintPlaylistLagu(Playlist PL, keytype k){
    valuetype set;
    set = Value_Playlist(PL, k);
    PrintSet(set);
}