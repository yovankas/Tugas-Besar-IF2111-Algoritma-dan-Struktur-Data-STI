#include <stdlib.h>
#include <stdio.h>
#include "listplaylist.h"

ListPlaylist initListPlaylist() {
    ListPlaylist listPL;
    listPL.playlist = malloc(InitialSizeListPL * sizeof(infotypePlaylist));
    if (listPL.playlist == NULL) {
        fprintf(stderr, "Memory allocation error for playlist\n");
        exit(EXIT_FAILURE);
    }
    listPL.capacity = InitialSizeListPL;
    listPL.count = 0;
    return listPL;
}

void addElement(ListPlaylist *listPL, char* value) {
    if (listPL->count == listPL->capacity) {
        listPL->capacity *= 2;
        listPL->playlist = (infotypePlaylist*)realloc(listPL->playlist, listPL->capacity * sizeof(infotypePlaylist));
        listPL->playlist->countsongPL = 0;
        if (listPL->playlist == NULL) {
            fprintf(stderr, "Memory reallocation error for playlist\n");
            exit(EXIT_FAILURE);
        }
    }
    listPL->playlist[listPL->count].namePL = value;
    listPL->count ++;
}

void deleteAtIndex(ListPlaylist *listPL, arraysize index) {
    if (index >= listPL->count) {
        fprintf(stderr, "Index out of bounds\n");
        exit(EXIT_FAILURE);
    }

    for (arraysize i = index; i < listPL->count - 1; i++) {
        listPL->playlist[i] = listPL->playlist[i + 1];
    }

    listPL->count--;

    if (listPL->count > 0 && listPL->count <= listPL->capacity / 2) {
        listPL->capacity /= 2;
        listPL->playlist = (infotypePlaylist*)realloc(listPL->playlist, listPL->capacity * sizeof(infotypePlaylist));
        if (listPL->playlist == NULL) {
            fprintf(stderr, "Memory reallocation error for playlist\n");
            exit(EXIT_FAILURE);
        }
    }
}

void printListPlaylist(ListPlaylist listPL) {
    if (listPL.count == 0){
        printf("Kamu tidak memiliki playlist.\n");
    }
    else {
        for (arraysize idxPLlist = 1; idxPLlist <= listPL.count; idxPLlist++) {
            printf("%d. %s\n", idxPLlist, listPL.playlist[idxPLlist-1].namePL);
        }
    }
}

void freeListPlaylist(ListPlaylist *listPL) {
    free(listPL->playlist);
    listPL->count = 0;
    listPL->capacity = 0;
}

char* namePlaylistFromIndex(ListPlaylist listPL, int ID)
{
    return (listPL.playlist[ID].namePL);
}

int jumlahSongPlaylistFromIndex(ListPlaylist listPL, int ID)
{
    return (listPL.playlist[ID].countsongPL);
}