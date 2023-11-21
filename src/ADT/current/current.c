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

boolean isEmptyCurrentPlaylist(currentPlaylist currentPlaylist)
{
    return (strCompare(currentPlaylist.playlist, "") == 0);
}

void PrintCurrentSong(currentSong currentSong)
{
    printf("%s - %s - %s\n", currentSong.artist, currentSong.song, currentSong.album);
}

void PlayCurrentSong(currentSong currentSong)
{
    printf("Queue kosong, memutar kembali lagu ");
    printf("%s oleh %s\n", currentSong.song, currentSong.artist);
}

void PlayNextSong(nextSong *nextSong, currentSong *currentSong, Queue *Q, Stackchar *History, currentPlaylist *currentPlaylist, ListPlaylist *ListLP)
{
    printf("Memutar lagu selanjutnya ");
    ElTypeQueue next;
    next = dequeue(Q);
    nextSong->song = next.song;
    nextSong->artist = next.artist;   
    nextSong->album = next.album; 
    // char* nextid; 
    // intToString(next.idPlaylist, nextid);
    // if (nextid != '\0')
    // {
    //     currentPlaylist->playlist = namePlaylistFromIndex(*ListLP, next.idPlaylist);
    // }
    // printf("ha gak jalan\n");
    // printf("%s oleh %s\n", nextSong->song, nextSong->artist);
    infotypeStackchar historysong;
    historysong.album = currentSong->album;
    historysong.artist = currentSong->artist;
    historysong.song = currentSong->song;
    PushStackChar(History, historysong);
    currentSong->album = nextSong->album;
    currentSong->artist = nextSong->artist;
    currentSong->song = nextSong->song;
    printf("%s oleh %s\n", currentSong->song, currentSong->artist);
    ReplaceNextSong(nextSong, Q);
}

void ReplayCurrentSong(currentSong currentSong)
{
    printf("Riwayat lagu kosong, memutar kembali lagu ");
    printf("%s oleh %s\n", currentSong.song, currentSong.artist);
}

void ReplaceNextSong(nextSong *nextSong, Queue *Q)
{
    ElTypeQueue next = (*Q).Tab[(*Q).idxHead];
    nextSong->album = next.album;
    nextSong->artist = next.artist;
    nextSong->song = next.song;
}

void PlayPrevSong(Stackchar *History, currentSong *currentSong, Queue *Q)
{
    ElTypeQueue queueCS;
    queueCS.album = currentSong->album;
    queueCS.artist = currentSong->artist;
    queueCS.song = currentSong->song;
    insertHead(Q, queueCS);
    printf("Memutar lagu sebelumnya ");
    infotypeStackchar X;
    PopStackChar(History, &X);
    printf("%s oleh %s", X.song, X.artist);
    currentSong->album = X.album;
    currentSong->artist = X.artist;
    currentSong->song = X.song;
}