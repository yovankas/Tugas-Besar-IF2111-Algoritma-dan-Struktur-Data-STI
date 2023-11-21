// main.c
#include "playlist.h"
#include <stdio.h>

int main() {
    // Create a playlist manager
    PlaylistManager* myManager = createPlaylistManager();

    // Add playlists
    addPlaylist(myManager);
    addPlaylist(myManager);

    // Add songs to playlists
    addSongToPlaylist(myManager, 0, "Song1", "Artist1", "Album1");
    addSongToPlaylist(myManager, 0, "Song2", "Artist2", "Album2");
    addSongToPlaylist(myManager, 1, "Song3", "Artist3", "Album3");

    // Display playlists
    displayPlaylist(myManager, 0);
    displayPlaylist(myManager, 1);

    swapSongsInPlaylist(myManager, 0, 0, 1);
    displayPlaylist(myManager, 0);
    deleteSongInPlaylist(myManager, 0, 1);
    displayPlaylist(myManager, 0);
    // // Clear all playlists
    // clearAllPlaylists(myManager);

    // Display playlists after clearing
    // printf("Playlist 1 after clearing:\n");
    // displayPlaylist(myManager, 0);
    // printf("Playlist 2 after clearing:\n");
    // displayPlaylist(myManager, 1);

    // // Free memory
    // free(myManager);

    return 0;
}
