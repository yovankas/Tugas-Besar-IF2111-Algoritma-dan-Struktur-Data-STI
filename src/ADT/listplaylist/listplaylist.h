#ifndef LISTPLAYLIST_H
#define LISTPLAYLIST_H

#include <stdlib.h>

#define InitialSizeListPL 100

typedef char* namaPlaylist;
typedef int countsongPlaylist;
typedef int arraysize;

typedef struct{
    namaPlaylist namePL;
    countsongPlaylist countsongPL;
} infotypePlaylist;

typedef struct {
    infotypePlaylist* playlist;
    arraysize count;
    arraysize capacity;
} ListPlaylist;

ListPlaylist initListPlaylist();

void addElement(ListPlaylist *listPL, char* value);

void deleteAtIndex(ListPlaylist *listPL, arraysize index);

void printListPlaylist(ListPlaylist *listPL);

void freeListPlaylist(ListPlaylist *listPL);

char* namePlaylistFromIndex(ListPlaylist listPL, int ID);

#endif
