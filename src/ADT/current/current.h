#ifndef current_H
#define current_H
#include <stdio.h>
#include "../../boolean.h"
#include "../string/string.h"

typedef struct 
{
        char* artist;
        char* album;
        char* song;
} currentSong;

typedef struct 
{
        char* artist;
        char* album;
        char* song;
} nextSong;

typedef struct
{
        char* playlist;
} currentPlaylist;

void PrintCurrentPlaylist(currentPlaylist currentPlaylist);
// Mengembalikan playlist yang sedang diputar

boolean isEmptyCurrentSong(currentSong currentSong);
// Memeriksa apakah ada lagu yang sedang diputar

void PrintCurrentSong(currentSong currentSong);
// Mengembalikan lagu yang sedang diputar

void PlayCurrentSong(currentSong currentSong);
// Memutar current song

void PlayNextSong(nextSong nextSong);
// Memutar next song

void ReplayCurrentSong(currentSong currentSong);
// Memutar kembali current song

#endif