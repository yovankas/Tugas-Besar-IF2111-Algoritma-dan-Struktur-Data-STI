#include <stdio.h>
#include <stdlib.h>
#include "../../ADT/playlist/playlist.h"

Playlist createPlaylist() {
    Playlist playlist;
    playlist.numSongs = 0;

    // Inside createPlaylist function
    for (int i = 0; i < MAX_SONGS; i++) {
        playlist.songs[i].lagu = malloc(MAX_STRING_LENGTH);  // Adjust MAX_STRING_LENGTH as needed
        playlist.songs[i].artist = malloc(MAX_STRING_LENGTH);
        playlist.songs[i].album = malloc(MAX_STRING_LENGTH);
        // Make sure to check if malloc succeeded
        if (!playlist.songs[i].lagu || !playlist.songs[i].artist || !playlist.songs[i].album) {
            // Handle allocation failure
            exit(EXIT_FAILURE);
        }
    }

    return playlist;
}

// Fungsi untuk menambah lagu ke dalam playlist
void addSong(Playlist* playlist, char* lagu, char* artist, char* album) {
    if (playlist->numSongs < MAX_SONGS) {
        // Assuming strCopy is your custom string copy function
        strCopy(playlist->songs[playlist->numSongs].lagu, lagu);
        strCopy(playlist->songs[playlist->numSongs].artist, artist);
        strCopy(playlist->songs[playlist->numSongs].album, album);
        playlist->numSongs +=1;
    } else {
        printf("Maximum number of songs in playlist reached.\n");
    }
}

// Fungsi untuk menampilkan seluruh lagu dalam playlist
void displayOnePlaylist(Playlist* playlist) {
    for (int i = 0; i < playlist->numSongs; i++) {
        printf("%d. %s - %s - %s\n", i + 1, playlist->songs[i].lagu, playlist->songs[i].artist, playlist->songs[i].album);
    }
}

// Fungsi untuk membersihkan seluruh playlist (menghapus semua lagu)
void clearOnePlaylist(Playlist* playlist) {
    for (int i = 0; i < playlist->numSongs; i++) {
        free(playlist->songs[i].lagu);
        free(playlist->songs[i].artist);
        free(playlist->songs[i].album);
    }
    playlist->numSongs = 0;
}

// Fungsi untuk membuat manajer playlist baru
PlaylistManager createPlaylistManager() {
    PlaylistManager manager;
    manager.numPlaylists = 0;
    return manager;
}

// Fungsi untuk menambah playlist baru
void addPlaylist(PlaylistManager* manager, Playlist* playlist) {
    if (manager->numPlaylists < MAX_PLAYLISTS) {
        manager->playlists[manager->numPlaylists] = *playlist;
        manager->numPlaylists++;
    } else {
        printf("Maximum number of playlists reached.\n");
    }
}

// Fungsi untuk menambah lagu ke dalam playlist
void addSongToPlaylist(PlaylistManager* manager, int playlistIndex, char* lagu, char* artist, char* album) {
    if (playlistIndex >= 0 && playlistIndex < manager->numPlaylists) {
        // Use the playlist directly
        addSong(&manager->playlists[playlistIndex], lagu, artist, album);
    } else {
        printf("Invalid playlist index.\n");
    }
}

// Fungsi untuk menampilkan seluruh lagu dalam playlist
void displayPlaylist(PlaylistManager* manager, int playlistIndex) {
    if (playlistIndex >= 0 && playlistIndex < manager->numPlaylists) {
        displayOnePlaylist(&manager->playlists[playlistIndex]);
    } else {
        printf("Invalid playlist index.\n");
    }
}


// Fungsi untuk membersihkan seluruh playlist (menghapus semua lagu)
void clearPlaylist(PlaylistManager* manager, int playlistIndex) {
    if (playlistIndex >= 0 && playlistIndex < manager->numPlaylists) {
        clearOnePlaylist(&manager->playlists[playlistIndex]);
    } else {
        printf("Invalid playlist index.\n");
    }
}

// Fungsi untuk membersihkan seluruh manajer playlist (menghapus semua playlist)
void clearAllPlaylists(PlaylistManager* manager) {
    for (int i = 0; i < manager->numPlaylists; i++) {
        clearOnePlaylist(&manager->playlists[i]);
    }
    manager->numPlaylists = 0;
}

// Function to retrieve a song from a playlist
// Function to retrieve a song from a specific playlist in the manager
Song LaguFromPlaylistManager(PlaylistManager* manager, int playlistIndex, int songIndex) {
    Song emptySong = { NULL, NULL, NULL };

    if (!manager || playlistIndex < 0 || playlistIndex >= manager->numPlaylists || songIndex < 0 || songIndex >= MAX_SONGS) {
        printf("Invalid input parameters.\n");
        return emptySong;
    }

    // Get the song from the specified playlist and index
    return manager->playlists[playlistIndex].songs[songIndex];
}


// Function to swap songs by index in a specific playlist
void swapSongsInPlaylist(PlaylistManager* manager, int playlistIndex, int songIndex1, int songIndex2) {
    if (!manager || playlistIndex < 0 || playlistIndex >= manager->numPlaylists ||
        songIndex1 < 0 || songIndex1 >= MAX_SONGS || songIndex2 < 0 || songIndex2 >= MAX_SONGS) {
        printf("Invalid input parameters.\n");
        return;
    }

    // Swap songs in the specified playlist and indices
    Song temp = manager->playlists[playlistIndex].songs[songIndex1];
    manager->playlists[playlistIndex].songs[songIndex1] = manager->playlists[playlistIndex].songs[songIndex2];
    manager->playlists[playlistIndex].songs[songIndex2] = temp;
}

// Function to delete a song by index in a specific playlist
void deleteSongInPlaylist(PlaylistManager* manager, int playlistIndex, int songIndex) {
    if (!manager || playlistIndex < 0 || playlistIndex >= manager->numPlaylists || songIndex < 0 || songIndex >= MAX_SONGS) {
        printf("Invalid input parameters.\n");
        return;
    }

    // Delete the song at the specified index in the specified playlist
    manager->playlists[playlistIndex].songs[songIndex] = (Song){ NULL, NULL, NULL };
}