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

#define MAX_SONGS 100

typedef struct {
    char* lagu;
    char* artist;
    char* album;
} Song;

typedef struct SongNode {
    Song data;
    struct SongNode* next;
} SongNode;

typedef struct {
    SongNode* head;
    int numSongs;
} Playlist;

#define MAX_PLAYLISTS 100

typedef struct {
    Playlist playlists[MAX_PLAYLISTS];
    int numPlaylists;
} PlaylistManager;

Playlist createPlaylist();
void addSong(Playlist* playlist, char* lagu, char* artist, char* album);
void displayOnePlaylist(Playlist* playlist);
void clearOnePlaylist(Playlist* playlist);
PlaylistManager createPlaylistManager();
void addPlaylist(PlaylistManager* manager, Playlist* playlist);
void addSongToPlaylist(PlaylistManager* manager, int playlistIndex, char* lagu, char* artist, char* album);
void displayPlaylist(PlaylistManager* manager, int playlistIndex);
void clearPlaylist(PlaylistManager* manager, int playlistIndex);
void clearAllPlaylists(PlaylistManager* manager);
Song LaguFromPlaylistManager(PlaylistManager* manager, int playlistIndex, int songIndex);
void swapSongsInPlaylist(PlaylistManager* manager, int playlistIndex, int songIndex1, int songIndex2);
void deleteSongInPlaylist(PlaylistManager* manager, int playlistIndex, int songIndex);
Playlist playlistFromPlaylistManager(PlaylistManager* manager, int playlistIndex);
void printPlaylistToFile(FILE *f, Playlist playlist);
boolean isEmptyPlaylist(Playlist playlist);
#endif
