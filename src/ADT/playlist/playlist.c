#include "playlist.h"

// Fungsi untuk mengalokasi songNode
static SongNode* createSongNode(char* lagu, char* artist, char* album) {
    SongNode* newSong = (SongNode*)malloc(sizeof(SongNode));
    if (!newSong) {
        // Handle allocation failure
        exit(EXIT_FAILURE);
    }

    newSong->data.lagu = malloc(MAX_STRING_LENGTH);
    newSong->data.artist = malloc(MAX_STRING_LENGTH);
    newSong->data.album = malloc(MAX_STRING_LENGTH);

    if (!newSong->data.lagu || !newSong->data.artist || !newSong->data.album) {
        // Kalo gagal
        free(newSong->data.lagu);
        free(newSong->data.artist);
        free(newSong->data.album);
        free(newSong);
        exit(EXIT_FAILURE);
    }

    strCopy(newSong->data.lagu, lagu);
    strCopy(newSong->data.artist, artist);
    strCopy(newSong->data.album, album);

    newSong->next = NULL;
    return newSong;
}

Playlist createPlaylist() {
    Playlist playlist;
    playlist.head = NULL;
    playlist.numSongs = 0;
    return playlist;
}

boolean isEmptyPlaylist(Playlist playlist)
{
    return playlist.head == NULL && playlist.numSongs == 0;
}

void addSong(Playlist* playlist, char* lagu, char* artist, char* album) {
    SongNode* newSong = createSongNode(lagu, artist, album);
    SongNode* P = playlist->head;
    if (isEmptyPlaylist(*playlist))
    {
        newSong->next = NULL;
        playlist->head = newSong;
    }
    else
    {
        while (P->next != NULL)
        {
            P = P->next;
        }
        newSong->next = P->next;
        P->next = newSong;
    }
    playlist->numSongs++;
}

void displayOnePlaylist(Playlist* playlist) {
    if (playlist->numSongs == 0) {
        printf("Playlist kosong.\n");
    } else {
        SongNode* current = playlist->head;
        int i = 1;
        while (current != NULL) {
            if (strCompare(current->data.album, "") != 0) {
                printf("%d. %s - %s - %s\n", i, current->data.lagu, current->data.artist, current->data.album);
                i++;
            }
            current = current->next;
        }
    }
}

void clearOnePlaylist(Playlist* playlist) {
    SongNode* current = playlist->head;
    SongNode* next;

    while (current != NULL) {
        next = current->next;
        free(current->data.lagu);
        free(current->data.artist);
        free(current->data.album);
        free(current);
        current = next;
    }

    playlist->head = NULL;
    playlist->numSongs = 0;
}

PlaylistManager createPlaylistManager() {
    PlaylistManager manager;
    manager.numPlaylists = 0;
    return manager;
}

void addPlaylist(PlaylistManager* manager, Playlist* playlist) {
    if (manager->numPlaylists < MAX_PLAYLISTS) {
        manager->playlists[manager->numPlaylists] = *playlist;
        manager->numPlaylists++;
    } else {
        printf("Maximum number of playlists reached.\n");
    }
}

void addSongToPlaylist(PlaylistManager* manager, int playlistIndex, char* lagu, char* artist, char* album) {
    if (playlistIndex >= 0 && playlistIndex < manager->numPlaylists) {
        // Use the playlist directly
        addSong(&manager->playlists[playlistIndex], lagu, artist, album);
    } else {
        printf("Invalid playlist index.\n");
    }
}

void displayPlaylist(PlaylistManager* manager, int playlistIndex) {
    if (playlistIndex >= 0 && playlistIndex < manager->numPlaylists) {
        displayOnePlaylist(&manager->playlists[playlistIndex]);
    } else {
        printf("Invalid playlist index.\n");
    }
}

void clearPlaylist(PlaylistManager* manager, int playlistIndex) {
    if (playlistIndex >= 0 && playlistIndex < manager->numPlaylists) {
        clearOnePlaylist(&manager->playlists[playlistIndex]);
    } else {
        printf("Invalid playlist index.\n");
    }
}

void clearAllPlaylists(PlaylistManager* manager) {
    for (int i = 0; i < manager->numPlaylists; i++) {
        clearOnePlaylist(&manager->playlists[i]);
    }
    manager->numPlaylists = 0;
}

Song LaguFromPlaylistManager(PlaylistManager* manager, int playlistIndex, int songIndex) {
    Song emptySong = {NULL, NULL, NULL};

    if (!manager || playlistIndex < 0 || playlistIndex >= manager->numPlaylists || songIndex < 0 || songIndex >= MAX_SONGS) {
        printf("Invalid input parameters.\n");
        return emptySong;
    }

    Playlist* playlist = &(manager->playlists[playlistIndex]);
    SongNode* current = playlist->head;
    int currentIndex = 0;

    while (current != NULL && currentIndex < songIndex) {
        current = current->next;
        currentIndex++;
    }

    if (current == NULL) {
        // printf("Invalid song index.\n");
        return emptySong;
    }

    return current->data;
}

void swapSongsInPlaylist(PlaylistManager* manager, int playlistIndex, int songIndex1, int songIndex2) {
    if (!manager || playlistIndex < 0 || playlistIndex >= manager->numPlaylists || songIndex1 < 0 || songIndex1 >= MAX_SONGS || songIndex2 < 0 || songIndex2 >= MAX_SONGS) {
        printf("Invalid input parameters.\n");
        return;
    }

    Playlist* playlist = &(manager->playlists[playlistIndex]);
    SongNode* current = playlist->head;
    SongNode* node1 = NULL;
    SongNode* node2 = NULL;

    // Mencari node
    for (int i = 0; i <= songIndex2; i++) {
        if (i == songIndex1) {
            node1 = current;
        }
        if (i == songIndex2) {
            node2 = current;
        }
        if (current == NULL) {
            // printf("Invalid song index.\n");
            return;
        }
        current = current->next;
    }

    // Menukar data song antarnode
    Song temp = node1->data;
    node1->data = node2->data;
    node2->data = temp;
}

void deleteSongInPlaylist(PlaylistManager* manager, int playlistIndex, int songIndex) 
{
    if (!manager || playlistIndex < 0 || playlistIndex >= manager->numPlaylists || songIndex < 0 || songIndex >= MAX_SONGS) 
    {
        // printf("Invalid input parameters.\n");
        return;
    }

    Playlist* playlist = &(manager->playlists[playlistIndex]);
    SongNode* current = playlist->head;
    SongNode* previous = NULL;

    int i = 0;
    while (i != songIndex)
    {
        previous = current;
        current = current->next;
        i += 1;
    }

    if (current == playlist->head)
    {
        playlist->head = current->next;
    }
    else
    {
        previous->next = current->next;
    }

    free(current->data.lagu);
    free(current->data.artist);
    free(current->data.album);
    free(current);

    playlist->numSongs--;
    return;
    //     }

    if (current == NULL) 
    {
        printf("Invalid song index.\n");
        return;
    }
}


Playlist playlistFromPlaylistManager(PlaylistManager* manager, int playlistIndex) {
    Playlist emptyPlaylist;
    emptyPlaylist.head = NULL;
    emptyPlaylist.numSongs = 0;

    if (!manager || playlistIndex < 0 || playlistIndex >= manager->numPlaylists) {
        // printf("Invalid input parameters.\n");
        return emptyPlaylist;
    }

    return manager->playlists[playlistIndex];
}

void printPlaylistToFile(FILE *f, Playlist playlist) {
    SongNode *current = playlist.head;

    while (current != NULL) {
        Song song = current->data;
        fprintf(f, "%s;%s;%s\n", song.artist, song.album, song.lagu);
        current = current->next;
    }
}


