#ifndef LISTPLAYLIST_H
#define LISTPLAYLIST_H

#include <stdlib.h>

#define InitialSizeListPL 100

typedef char* infotypePlaylist;
typedef int arraysize;

typedef struct {
    infotypePlaylist* playlist;
    arraysize count;
    arraysize capacity;
} ListPlaylist;

ListPlaylist initListPlaylist();

void addElement(ListPlaylist *listPL, infotypePlaylist value);

void deleteAtIndex(ListPlaylist *listPL, arraysize index);

void printListPlaylist(ListPlaylist *listPL);

void freeListPlaylist(ListPlaylist *listPL);

infotypePlaylist namePlaylistFromIndex(ListPlaylist listPL, int ID);

#endif
