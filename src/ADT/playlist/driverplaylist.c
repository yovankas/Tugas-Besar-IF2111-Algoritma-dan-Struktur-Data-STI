#include <stdio.h>
#include "playlist.h"

int main() {
    PlaylistManager manager = createPlaylistManager();

    // Create playlists
    Playlist playlist1 = createPlaylist();
    Playlist playlist2 = createPlaylist();

    // Add songs to playlists
    addSong(&playlist1, "Song1", "Artist1", "Album1");
    addSong(&playlist1, "Song2", "Artist2", "Album2");
    addSong(&playlist2, "Song3", "Artist3", "Album3");

    // Add playlists to the manager
    addPlaylist(&manager, &playlist1);
    addPlaylist(&manager, &playlist2);

    // Display playlists
    printf("Displaying Playlist 1:\n");
    displayPlaylist(&manager, 0);

    printf("\nDisplaying Playlist 2:\n");
    displayPlaylist(&manager, 1);

    // Add songs to specific playlists
    addSongToPlaylist(&manager, 0, "Song4", "Artist4", "Album4");

    // Display updated Playlist 1
    printf("\nDisplaying Updated Playlist 1:\n");
    displayPlaylist(&manager, 0);

    // Swap songs in Playlist 1
    swapSongsInPlaylist(&manager, 0, 0, 1);

    // Display Playlist 1 after swapping songs
    printf("\nDisplaying Playlist 1 after swapping songs:\n");
    displayPlaylist(&manager, 0);

    // Song from playlist manager
    printf("\nSong from Playlist Manager:\n");
    Song next = LaguFromPlaylistManager(&manager, 0, 0);
    printf("%s\n", next.lagu);

    // Delete a song from Playlist 1
    deleteSongInPlaylist(&manager, 0, 1);

    // Display Playlist 1 after deleting a song
    printf("\nDisplaying Playlist 1 after deleting a song:\n");
    displayPlaylist(&manager, 0);

    // Clear Playlist 2
    clearPlaylist(&manager, 1);

    // Display Playlist 2 after clearing
    printf("\nDisplaying Playlist 2 after clearing:\n");
    displayPlaylist(&manager, 1);

    // Clear all playlists
    clearAllPlaylists(&manager);

    // Display all playlists after clearing
    printf("\nDisplaying all playlists after clearing:\n");
    displayPlaylist(&manager, 0);


    return 0;
}
