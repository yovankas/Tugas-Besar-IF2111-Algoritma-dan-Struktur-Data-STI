#include <stdlib.h>
#include <stdio.h>
#include "../../ADT/listplaylist/listplaylist.h"

void initListPlaylist(ListPlaylist *listPL, arraysize initialCapacity) {
    listPL->playlist = (char* *)malloc(initialCapacity * sizeof(char*));
    if (listPL->playlist == NULL) {
        printf("Memory allocation error\n");
        exit(EXIT_FAILURE);
    }
    listPL->count = 0;
    listPL->capacity = initialCapacity;
}

void addElmt(ListPlaylist *listPL, char* value) {
    if (listPL->count == listPL->capacity) {
        listPL->capacity *= 2;
        listPL->playlist = (char* *)realloc(listPL->playlist, listPL->capacity * sizeof(char*));
        if (listPL->playlist == NULL) {
            fprintf(stderr, "Memory reallocation error\n");
            exit(EXIT_FAILURE);
        }
    }
    listPL->playlist[listPL->count] = value;
    listPL->count++;
}

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
        listPL->playlist = (char* *)realloc(listPL->playlist, listPL->capacity * sizeof(char*));
        if (listPL->playlist == NULL) {
            fprintf(stderr, "Memory reallocation error\n");
            exit(EXIT_FAILURE);
        }
    }
}

void printListPlaylist(const ListPlaylist *listPL) {
    if (listPL->count == 0){
        printf("Kamu tidak memiliki playlist.")
    }
    else{
        for (arraysize i = 0; i < listPL->count; i++) {
        int nomor;
        nomor = i+1;
        printf("%d. %s\n", nomor, listPL->playlist[i]);
    }
    }
}

void freePlaylist(ListPlaylist *listPL) {
    free(listPL->playlist);
    listPL->count = 0;
    listPL->capacity = 0;
}
