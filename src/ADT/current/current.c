#include "current.h"

void PrintCurrentPlaylist(currentPlaylist currentPlaylist)
{
    printf("%s\n", currentPlaylist.playlist);
}

boolean isEmptyCurrentSong(currentSong currentSong)
{
    return (strCompare(currentSong.album, "") == 0 && strCompare(currentSong.artist, "") == 0 && strCompare(currentSong.song, "") == 0);
}

void PrintCurrentSong(currentSong currentSong)
{
    printf("%s - %s - %s\n", currentSong.artist, currentSong.song, currentSong.album);
}

void PlayCurrentSong(currentSong currentSong)
{
    printf("Queue kosong, memutar kembali lagu");
    printf("%s oleh %s\n", currentSong.song, currentSong.artist);
}

void PlayNextSong(nextSong nextSong)
{
    printf("Memutar lagu selanjutnya");
    printf("%s oleh %s\n", nextSong.song, nextSong.artist);
}

void ReplayCurrentSong(currentSong currentSong)
{
    printf("Riwayat lagu kosong, memutar kembali lagu");
    printf("%s oleh %s\n", currentSong.song, currentSong.artist);
}

