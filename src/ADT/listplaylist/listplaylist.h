#ifndef LIST_PLAYLIST_H
#define LIST_PLAYLIST_H

#include <stdlib.h>
#include "../../ADT/string/string.h"

typedef int arraysize;
typedef struct {
    char* *playlist;
    arraysize count;
    arraysize capacity;
} ListPlaylist;

typedef struct{
    arraysize idxElmt[count];
} ListPlaylist;

void initListPlaylist(ListPlaylist *listPL, arraysize initialCapacity);
// Untuk Menginisialisasi array dinamis list playlist

void addElmt(ListPlaylist *listPL, char* value);
// Untuk menambahkan elemen baru ke dynamic array list playlist di belakang element terakhir dalam array

void deleteAtIndex(ListPlaylist *listPL, arraysize index);
// Untuk menghapus elemen di index tertentu

void printListPlaylist(const ListPlaylist *listPL);
// Menampilkan elemen yang ada dalam array

void freeListPlaylist(ListPlaylist *listPL);
// Mengosongkan memori yang dialokasikan untuk array dinamis

#endif