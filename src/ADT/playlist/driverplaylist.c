#include <stdio.h>
#include "playlist.h"

int main() {
    PlaylistManager manager = createPlaylistManager();

    // Create playlist
    Playlist playlist1 = createPlaylist();
    Playlist playlist2 = createPlaylist();

    // Add songs to playlist
    addSong(&playlist1, "Song1", "Artist1", "Album1");
    addSong(&playlist1, "Song2", "Artist2", "Album2");
    addSong(&playlist2, "Song3", "Artist3", "Album3");

    // Add playlists to the manager
    addPlaylist(&manager, &playlist1);
    addPlaylist(&manager, &playlist2);

    // Display playlist
    printf("Playlist 1:\n");
    displayPlaylist(&manager, 0);

    printf("\nPlaylist 2:\n");
    displayPlaylist(&manager, 1);

    // Nambahin lagu ke playlist dengan ID
    addSongToPlaylist(&manager, 0, "Song4", "Artist4", "Album4");

    // Display Playlist 1
    printf("\nUpdated Playlist 1:\n");
    displayPlaylist(&manager, 0);

    // Swap songs 
    swapSongsInPlaylist(&manager, 0, 0, 1);

    // Display Playlist 1 
    printf("\nPlaylist 1:\n");
    displayPlaylist(&manager, 0);

    // Song from playlist manager
    printf("\nSong from Playlist Manager:\n");
    Song next = LaguFromPlaylistManager(&manager, 0, 0);
    printf("%s\n", next.lagu);

    // Menghapus lagu
    deleteSongInPlaylist(&manager, 0, 1);

    // Display Playlist 
    printf("\nPlaylist 1 :\n");
    displayPlaylist(&manager, 0);

    // Clear Playlist 2
    clearPlaylist(&manager, 1);

    // Display Playlist 2 
    printf("\nPlaylist 2 :\n");
    displayPlaylist(&manager, 1);

    // Clear semua playlist
    clearAllPlaylists(&manager);

    // Display playlist
    printf("\nPlaylists :\n");
    displayPlaylist(&manager, 0);


    return 0;
}
