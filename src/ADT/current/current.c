#include "current.h"

boolean isEmptyCurrentSong(currentSong currentSong)
{
    return (strcmp(currentSong.album, "") == 0 && strcmp(currentSong.artist, "") == 0 && strcmp(currentSong.song, "") == 0);
}