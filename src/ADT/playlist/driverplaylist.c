// main.c
#include "playlist.h"
#include <stdio.h>

int main() {
    // Example usage
    PlaylistManager myManager = createPlaylistManager();
    Playlist playlit = createPlaylist();
    addPlaylist(&myManager, &playlit);

    addSongToPlaylist(&myManager, 0, "tes1", "tes2", "tesbabi");
    addSongToPlaylist(&myManager, 0, "tes3", "tes4", "tesbabi");
    displayPlaylist(&myManager, 0);
    // Initialize songs in the playlist
    // myManager.playlists[0].songs[0].lagu = "Song1";
    // myManager.playlists[0].songs[0].artist = "Artist1";
    // myManager.playlists[0].songs[0].album = "Album1";

    // addSongToPlaylist(&myManager, 0, "song2", "artis2", "album2");

    // // Retrieve and print a song
    // Song retrievedSong = LaguFromPlaylistManager(&myManager, 0, 0);
    // printf("Retrieved Song: %s - %s - %s\n", retrievedSong.lagu, retrievedSong.artist, retrievedSong.album);

    // // Swap songs and print the updated playlist
    swapSongsInPlaylist(&myManager, 0, 0, 1);
    displayPlaylist(&myManager, 0);
    // printf("Updated Playlist after Swap:\n");
    // printf("Song 1: %s - %s - %s\n", myManager.playlists[0].songs[0].lagu, myManager.playlists[0].songs[0].artist, myManager.playlists[0].songs[0].album);
    // printf("Song 2: %s - %s - %s\n", myManager.playlists[0].songs[1].lagu, myManager.playlists[0].songs[1].artist, myManager.playlists[0].songs[1].album);

    // // Delete a song and print the updated playlist
    // deleteSongInPlaylist(&myManager, 0, 1);
    // printf("Updated Playlist after Deletion:\n");
    // printf("Song 1: %s - %s - %s\n", myManager.playlists[0].songs[0].lagu, myManager.playlists[0].songs[0].artist, myManager.playlists[0].songs[0].album);
    // printf("Song 2: %s - %s - %s\n", myManager.playlists[0].songs[1].lagu, myManager.playlists[0].songs[1].artist, myManager.playlists[0].songs[1].album);

    return 0;
}