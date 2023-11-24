#include <stdio.h>
#include "current.h"

int main() {
    currentSong current;
    nextSong next;
    currentPlaylist playlist;
    Stackchar History;

    // Inisialisasi current song
    CreateEmptyCurrentSong(&current);

    // Inisialisasi current playlist
    CreateEmptyCurrentPlaylist(&playlist);

    // Inisialisasi stack history
    CreateEmptyStackChar(&History);

    // Print current playlist
    printf("Current Playlist:\n");
    PrintCurrentPlaylist(playlist);

    // Mengecek apakah current song kosong
    if (isEmptyCurrentSong(current)) {
        printf("Kamu belum memutar lagu.\n");
    }

    // Print current song
    printf("Current Song:\n");
    PrintCurrentSong(current);

    // Play current song
    PlayCurrentSong(current);

    // Membuat circular queue
    Queue Q;
    CreateEmptyQueue(&Q, 5);

    // Enqueue lagu ke queue
    enqueue(&Q, "Artist1", "Album1", "Song1");
    enqueue(&Q, "Artist2", "Album2", "Song2");
    enqueue(&Q, "Artist3", "Album3", "Song3");

    // Print current playlist
    printf("\nUpdated Playlist:\n");
    PrintCurrentPlaylist(playlist);

    // Play next song
    PlayNextSong(&next, &current, &Q, &History);

    // Print current song
    printf("\nUpdated Current Song:\n");
    PrintCurrentSong(current);

    // Print history
    printf("\nHistory setelah play next song:\n");
    printStackchar(History);

    // Menghapus next song
    ReplaceNextSong(&next, &Q);

    // Print playlist
    printf("\nUpdated Playlist :\n");
    PrintCurrentPlaylist(playlist);

    // Play previous song
    PlayPrevSong(&History, &current);

    // Print current song
    printf("\nUpdated Current Song :\n");
    PrintCurrentSong(current);

    return 0;
}