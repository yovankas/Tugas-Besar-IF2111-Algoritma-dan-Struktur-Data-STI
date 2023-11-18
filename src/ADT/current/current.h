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

boolean isEmptyCurrentSong(currentSong currentSong);

#endif