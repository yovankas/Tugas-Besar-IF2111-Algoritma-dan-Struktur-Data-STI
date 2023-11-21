#ifndef playlist_H
#define playlist_H

#include <stdio.h>
#include <stdlib.h>
#include "../../boolean.h"
#include "../../adt/mesin/mesinkata.h"
#include "../../adt/array/array.h"
#include "../../adt/string/string.h"
#include "../word/word.h"

#define MAX_STRING_LENGTH 100
#define MAX_SONGS 100 // Adjust the maximum number of songs in a playlist as needed

typedef struct
{
    char *lagu;
    char *artist;
    char *album;
} Song;

typedef struct
{
    Song songs[MAX_SONGS];
    int numSongs;
} Playlist;

#define MAX_PLAYLISTS 100

typedef struct
{
    Playlist playlists[MAX_PLAYLISTS];
    int numPlaylists;
} PlaylistManager;

Playlist createPlaylist();

void addSong(Playlist *playlist, char *lagu, char *artist, char *album);

void displayOnePlaylist(Playlist *playlist);

void printPlaylistToFile(FILE *f, Playlist playlist);

void clearOnePlaylist(Playlist *playlist);

PlaylistManager createPlaylistManager();

void addPlaylist(PlaylistManager *manager, Playlist *playlist);

// Fungsi untuk menambah lagu ke dalam playlist
void addSongToPlaylist(PlaylistManager *manager, int playlistIndex, char *lagu, char *artist, char *album);

// Fungsi untuk menampilkan seluruh lagu dalam playlist
void displayPlaylist(PlaylistManager *manager, int playlistIndex);

// Fungsi untuk membersihkan seluruh playlist (menghapus semua lagu)
void clearPlaylist(PlaylistManager *manager, int playlistIndex);

// Fungsi untuk membersihkan seluruh manajer playlist (menghapus semua playlist)
void clearAllPlaylists(PlaylistManager *manager);

Song LaguFromPlaylistManager(PlaylistManager *manager, int playlistIndex, int songIndex);

void swapSongsInPlaylist(PlaylistManager *manager, int playlistIndex, int songIndex1, int songIndex2);

void deleteSongInPlaylist(PlaylistManager *manager, int playlistIndex, int songIndex);

Playlist playlistFromPlaylistManager(PlaylistManager *manager, int playlistIndex);

#endif