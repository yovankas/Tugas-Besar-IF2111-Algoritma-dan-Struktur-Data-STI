#include "current.h"

void CreateEmptyCurrentSong (currentSong *currentSong)
{
    (*currentSong).album = "";
    (*currentSong).artist = "";
    (*currentSong).song = "";
}

void CreateEmptyCurrentPlaylist (currentPlaylist *currentPlaylist)
{
    (*currentPlaylist).playlist = "";
}

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
    printf("“%s” oleh “%s”\n", currentSong.song, currentSong.artist);
}

void PlayNextSong(nextSong *nextSong, currentSong *currentSong, Queue *Q)
{
<<<<<<< Updated upstream
    printf("Memutar lagu selanjutnya");
    printf("“%s” oleh “%s”\n", nextSong.song, nextSong.artist);
    currentSong.album = nextSong.album;
    currentSong.artist = nextSong.artist;
    currentSong.song = nextSong.song;
=======
    printf("Memutar lagu selanjutnya ");
    nextSong->song = Q->Tab[Q->idxHead].song;
    nextSong->artist = Q->Tab[Q->idxHead].artist;
    nextSong->album = Q->Tab[Q->idxHead].album;
    // printf("%s oleh %s\n", nextSong->song, nextSong->artist);
    currentSong->album = nextSong->album;
    currentSong->artist = nextSong->artist;
    currentSong->song = nextSong->song;
    printf("%s oleh %s\n", currentSong->song, currentSong->artist);
    ReplaceNextSong(nextSong, Q);
>>>>>>> Stashed changes
}

void ReplayCurrentSong(currentSong currentSong)
{
    printf("Riwayat lagu kosong, memutar kembali lagu");
    printf("“%s” oleh “%s”\n", currentSong.song, currentSong.artist);
}

void ReplaceNextSong(nextSong *nextSong, Queue *Q)
{
    ElTypeQueue next = dequeue(Q);
    nextSong->album = next.album;
    nextSong->artist = next.artist;
    nextSong->song = next.song;
}