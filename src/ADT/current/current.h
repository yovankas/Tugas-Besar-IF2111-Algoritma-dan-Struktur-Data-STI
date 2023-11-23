#ifndef current_H
#define current_H
#include <stdio.h>
#include "../../boolean.h"
#include "../string/string.h"
#include "../queue/circular_queue.h"
#include "../stack/stackchar.h"
#include "../listplaylist/listplaylist.h"

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

void CreateEmptyCurrentSong (currentSong *currentSong);

void CreateEmptyCurrentPlaylist (currentPlaylist *currentPlaylist);

void PrintCurrentPlaylist(currentPlaylist currentPlaylist);
// Mengembalikan playlist yang sedang diputar

boolean isEmptyCurrentSong(currentSong currentSong);
// Memeriksa apakah ada lagu yang sedang diputar

boolean isEmptyCurrentPlaylist(currentPlaylist currentPlaylist);

void PrintCurrentSong(currentSong currentSong);
// Mengembalikan lagu yang sedang diputar

void PlayCurrentSong(currentSong currentSong);
// Memutar current song

void PlayNextSong(nextSong *nextSong, currentSong *currentSong, Queue *Q, Stackchar *History, currentPlaylist *currentPlaylist);
// Memutar next song

void ReplayCurrentSong(currentSong currentSong);
// Memutar kembali current song

void ReplaceNextSong(nextSong *nextSong, Queue *Q);

void PlayPrevSong(Stackchar *History, currentSong *currentSong, Queue *Q);
    /* Memutar lagu sebelumnya */

#endif