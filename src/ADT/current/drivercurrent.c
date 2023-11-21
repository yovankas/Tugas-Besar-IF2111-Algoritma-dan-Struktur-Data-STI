#include <stdio.h>
#include "current.h"

int main() {
    currentSong current;
    nextSong next;
    currentPlaylist playlist;
    Stackchar History;

    // Initialize current song
    CreateEmptyCurrentSong(&current);

    // Initialize current playlist
    CreateEmptyCurrentPlaylist(&playlist);

    // Initialize history stack
    CreateEmptyStackChar(&History);

    // Print current playlist
    printf("Current Playlist:\n");
    PrintCurrentPlaylist(playlist);

    // Check if current song is empty
    if (isEmptyCurrentSong(current)) {
        printf("No song is currently playing.\n");
    }

    // Print current song
    printf("Current Song:\n");
    PrintCurrentSong(current);

    // Play the current song
    PlayCurrentSong(current);

    // Create a circular queue
    Queue Q;
    CreateEmptyQueue(&Q, 5);

    // Enqueue songs to the queue
    enqueue(&Q, "Artist1", "Album1", "Song1");
    enqueue(&Q, "Artist2", "Album2", "Song2");
    enqueue(&Q, "Artist3", "Album3", "Song3");

    // Print the current playlist
    printf("\nUpdated Playlist:\n");
    PrintCurrentPlaylist(playlist);

    // Play the next song
    PlayNextSong(&next, &current, &Q, &History);

    // Print the updated current song
    printf("\nUpdated Current Song:\n");
    PrintCurrentSong(current);

    // Print the history stack
    printf("\nHistory Stack after playing the next song:\n");
    printStackchar(History);

    // Replace the next song
    ReplaceNextSong(&next, &Q);

    // Print the updated playlist
    printf("\nUpdated Playlist after replacing next song:\n");
    PrintCurrentPlaylist(playlist);

    // Play the previous song
    PlayPrevSong(&History, &current);

    // Print the updated current song after playing the previous song
    printf("\nUpdated Current Song after playing the previous song:\n");
    PrintCurrentSong(current);

    return 0;
}