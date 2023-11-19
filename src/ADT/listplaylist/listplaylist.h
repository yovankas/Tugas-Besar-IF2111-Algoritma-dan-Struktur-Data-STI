#ifndef LIST_PLAYLIST_H
#define LIST_PLAYLIST_H

#include <stdlib.h>

#define InitialSizeListPL 100

typedef char* infotypePlaylist;
typedef int arraysize;
typedef struct {
    infotypePlaylist* playlist; // Use infotypePlaylist* for an array
    arraysize count;
    arraysize capacity;
} ListPlaylist;

ListPlaylist initListPlaylist();

void CreateEmptyListPlaylist(ListPlaylist *listPL);

void addElmt(ListPlaylist *listPL, infotypePlaylist value);

void deleteAtIndex(ListPlaylist *listPL, arraysize index);

void printListPlaylist(ListPlaylist *listPL);

void freeListPlaylist(ListPlaylist *listPL);

#endif
