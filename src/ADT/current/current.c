#include "current.h"

void PrintCurrentPlaylist(currentPlaylist currentPlaylist)
{
    printf("%s\n", currentPlaylist.playlist);
}

boolean isEmptyCurrentSong(currentSong currentSong)
{
    return (strcmp(currentSong.album, "") == 0 && strcmp(currentSong.artist, "") == 0 && strcmp(currentSong.song, "") == 0);
}

void PrintCurrentSong(currentSong currentSong)
{
    printf("%s - %s - %s\n", currentSong.artist, currentSong.song, currentSong.album);
}