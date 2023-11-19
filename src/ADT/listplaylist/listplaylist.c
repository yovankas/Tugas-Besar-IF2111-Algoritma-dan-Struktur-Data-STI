#include <stdlib.h>
#include <stdio.h>
#include "listplaylist.h"

ListPlaylist initListPlaylist() {
    ListPlaylist listPL;
    listPL.playlist = (infotypePlaylist*)malloc(InitialSizeListPL * sizeof(infotypePlaylist));
    if (listPL.playlist == NULL) {
        fprintf(stderr, "Memory allocation error for playlist\n");
        exit(EXIT_FAILURE);
    }
    listPL.capacity = InitialSizeListPL;
    listPL.count = 0;
    return listPL;
}

void addElement(ListPlaylist *listPL, infotypePlaylist value) {
    if (listPL->count == listPL->capacity) {
        listPL->capacity *= 2;
        listPL->playlist = (infotypePlaylist*)realloc(listPL->playlist, listPL->capacity * sizeof(infotypePlaylist));
        if (listPL->playlist == NULL) {
            fprintf(stderr, "Memory reallocation error for playlist\n");
            exit(EXIT_FAILURE);
        }
    }
    listPL->playlist[listPL->count] = value;
    listPL->count++;
}

// Rest of the functions remain the same with updated names.

void deleteAtIndex(ListPlaylist *listPL, arraysize index) {
    if (index >= listPL->count) {
        fprintf(stderr, "Index out of bounds\n");
        exit(EXIT_FAILURE);
    }

    // Pergeseran elemen untuk menghapus elemen pada indeks yang diinginkan
    for (arraysize i = index; i < listPL->count - 1; i++) {
        listPL->playlist[i] = listPL->playlist[i + 1];
    }

    listPL->count--;

    // Periksa apakah playlist kurang dari setengahnya, dan dikecilkan
    if (listPL->count > 0 && listPL->count <= listPL->capacity / 2) {
        listPL->capacity /= 2;
        listPL->playlist = (infotypePlaylist*)realloc(listPL->playlist, listPL->capacity * sizeof(infotypePlaylist));
        if (listPL->playlist == NULL) {
            fprintf(stderr, "Memory reallocation error\n");
            exit(EXIT_FAILURE);
        }
    }
}

void printListPlaylist(ListPlaylist *listPL) {
    if (listPL->count == 0){
        printf("Kamu tidak memiliki playlist.");
    }
    else {
        for (arraysize i = 0; i < listPL->count; i++) {
            int nomor = i + 1;
            printf("%d. %s\n", nomor, listPL->playlist[i]);
        }
    }
}

void freePlaylist(ListPlaylist *listPL) {
    free(listPL->playlist);
    listPL->count = 0;
    listPL->capacity = 0;
}
