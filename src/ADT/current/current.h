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
        char* playlist;
} currentPlaylist;

void PrintCurrentPlaylist(currentPlaylist currentPlaylist);

boolean isEmptyCurrentSong(currentSong currentSong);

void PrintCurrentSong(currentSong currentSong);

void PlayCurrentSong(currentSong currentSong);

#endif