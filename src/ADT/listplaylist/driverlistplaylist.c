#include <stdio.h>
#include "listplaylist.h"

int main() {
    ListPlaylist listPlaylist = initListPlaylist();

    // Menambahkan elemen ke listPlaylist
    addElement(&listPlaylist, "Playlist 1");
    addElement(&listPlaylist, "Playlist 2");
    addElement(&listPlaylist, "Playlist 3");

    // Print listPlaylist
    printf("Playlist after adding elements:\n");
    printListPlaylist(listPlaylist);


    // Delete elemen di index 1
    deleteAtIndex(&listPlaylist, 1);

    // Print setelah dihapus
    printf("\nPlaylist after deleting element at index 1:\n");
    printListPlaylist(listPlaylist);

    // Akses dengan index
    int playlistIndex = 0;
    printf("\nPlaylist at index %d:\n", playlistIndex);
    printf("Name: %s\n", namePlaylistFromIndex(listPlaylist, playlistIndex));
    printf("Number of songs: %d\n", jumlahSongPlaylistFromIndex(listPlaylist, playlistIndex));


    freeListPlaylist(&listPlaylist);

    return 0;
}