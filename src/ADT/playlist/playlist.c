// #include <stdio.h>
// #include <stdlib.h>
// #include "../../ADT/playlist/playlist.h"

// Playlist createPlaylist()
// {
//     Playlist playlist;
//     playlist.numSongs = 0;

//     // Inside createPlaylist function
//     for (int i = 0; i < MAX_SONGS; i++)
//     {
//         playlist.songs[i].lagu = malloc(MAX_STRING_LENGTH); // Adjust MAX_STRING_LENGTH as needed
//         playlist.songs[i].artist = malloc(MAX_STRING_LENGTH);
//         playlist.songs[i].album = malloc(MAX_STRING_LENGTH);
//         // Make sure to check if malloc succeeded
//         if (!playlist.songs[i].lagu || !playlist.songs[i].artist || !playlist.songs[i].album)
//         {
//             // Handle allocation failure
//             exit(EXIT_FAILURE);
//         }
//     }

//     return playlist;
// }

// // Fungsi untuk menambah lagu ke dalam playlist
// void addSong(Playlist *playlist, char *lagu, char *artist, char *album)
// {
//     if (playlist->numSongs < MAX_SONGS)
//     {
//         // Assuming strCopy is your custom string copy function
//         strCopy(playlist->songs[playlist->numSongs].lagu, lagu);
//         strCopy(playlist->songs[playlist->numSongs].artist, artist);
//         strCopy(playlist->songs[playlist->numSongs].album, album);
//         playlist->numSongs += 1;
//     }
//     else
//     {
//         printf("Maximum number of songs in playlist reached.\n");
//     }
// }

// // Fungsi untuk menampilkan seluruh lagu dalam playlist
// void displayOnePlaylist(Playlist *playlist)
// {
//     if (playlist->numSongs == 0)
//     {
//         printf("Playlist kosong.\n");
//     }
//     else
//     {
//         for (int i = 0; i < playlist->numSongs; i++)
//         {
//             if (strCompare(playlist->songs[i].album, "") != 0)
//             {
//                 printf("%d. %s - %s - %s\n", i + 1, playlist->songs[i].lagu, playlist->songs[i].artist, playlist->songs[i].album);
//             }
//         }
//     }
// }

// void printPlaylistToFile(FILE *f, Playlist playlist)
// {
//     for (int i = 0; i < playlist.numSongs; i++)
//     {
//         if (strCompare(playlist.songs[i].album, "") != 0)
//         {
//             Song song = playlist.songs[i];
//             fprintf(f, "%s;%s;%s\n", song.artist, song.album, song.lagu);
//         }
//     }
// }

// // Fungsi untuk membersihkan seluruh playlist (menghapus semua lagu)
// void clearOnePlaylist(Playlist *playlist)
// {
//     for (int i = 0; i < playlist->numSongs; i++)
//     {
//         free(playlist->songs[i].lagu);
//         free(playlist->songs[i].artist);
//         free(playlist->songs[i].album);
//     }
//     playlist->numSongs = 0;
// }

// // Fungsi untuk membuat manajer playlist baru
// PlaylistManager createPlaylistManager()
// {
//     PlaylistManager manager;
//     manager.numPlaylists = 0;
//     return manager;
// }

// // Fungsi untuk menambah playlist baru
// void addPlaylist(PlaylistManager *manager, Playlist *playlist)
// {
//     if (manager->numPlaylists < MAX_PLAYLISTS)
//     {
//         manager->playlists[manager->numPlaylists] = *playlist;
//         manager->numPlaylists++;
//     }
//     else
//     {
//         printf("Maximum number of playlists reached.\n");
//     }
// }

// // Fungsi untuk menambah lagu ke dalam playlist
// void addSongToPlaylist(PlaylistManager *manager, int playlistIndex, char *lagu, char *artist, char *album)
// {
//     if (playlistIndex >= 0 && playlistIndex < manager->numPlaylists)
//     {
//         // Use the playlist directly
//         addSong(&manager->playlists[playlistIndex], lagu, artist, album);
//     }
//     else
//     {
//         printf("Invalid playlist index.\n");
//     }
// }

// // Fungsi untuk menampilkan seluruh lagu dalam playlist
// void displayPlaylist(PlaylistManager *manager, int playlistIndex)
// {
//     if (playlistIndex >= 0 && playlistIndex < manager->numPlaylists)
//     {
//         displayOnePlaylist(&manager->playlists[playlistIndex]);
//     }
//     else
//     {
//         printf("Invalid playlist index.\n");
//     }
// }

// // Fungsi untuk membersihkan seluruh playlist (menghapus semua lagu)
// void clearPlaylist(PlaylistManager *manager, int playlistIndex)
// {
//     if (playlistIndex >= 0 && playlistIndex < manager->numPlaylists)
//     {
//         clearOnePlaylist(&manager->playlists[playlistIndex]);
//     }
//     else
//     {
//         printf("Invalid playlist index.\n");
//     }
// }

// // Fungsi untuk membersihkan seluruh manajer playlist (menghapus semua playlist)
// void clearAllPlaylists(PlaylistManager *manager)
// {
//     for (int i = 0; i < manager->numPlaylists; i++)
//     {
//         clearOnePlaylist(&manager->playlists[i]);
//     }
//     manager->numPlaylists = 0;
// }

// // Function to retrieve a song from a playlist
// // Function to retrieve a song from a specific playlist in the manager
// Song LaguFromPlaylistManager(PlaylistManager *manager, int playlistIndex, int songIndex)
// {
//     Song emptySong = {NULL, NULL, NULL};

//     if (!manager || playlistIndex < 0 || playlistIndex >= manager->numPlaylists || songIndex < 0 || songIndex >= MAX_SONGS)
//     {
//         printf("Invalid input parameters.\n");
//         return emptySong;
//     }

//     // Get the song from the specified playlist and index
//     return manager->playlists[playlistIndex].songs[songIndex];
// }

// // Function to swap songs by index in a specific playlist
// void swapSongsInPlaylist(PlaylistManager *manager, int playlistIndex, int songIndex1, int songIndex2)
// {
//     if (!manager || playlistIndex < 0 || playlistIndex >= manager->numPlaylists ||
//         songIndex1 < 0 || songIndex1 >= MAX_SONGS || songIndex2 < 0 || songIndex2 >= MAX_SONGS)
//     {
//         printf("Invalid input parameters.\n");
//         return;
//     }

//     // Swap songs in the specified playlist and indices
//     Song temp = manager->playlists[playlistIndex].songs[songIndex1];
//     manager->playlists[playlistIndex].songs[songIndex1] = manager->playlists[playlistIndex].songs[songIndex2];
//     manager->playlists[playlistIndex].songs[songIndex2] = temp;
// }

// // Function to delete a song by index in a specific playlist
// void deleteSongInPlaylist(PlaylistManager *manager, int playlistIndex, int songIndex)
// {
//     if (!manager || playlistIndex < 0 || playlistIndex >= manager->numPlaylists || songIndex < 0 || songIndex >= manager->playlists[playlistIndex].numSongs)
//     {
//         printf("Invalid input parameters.\n");
//         return;
//     }

//     // Get the playlist and the number of songs in the specified playlist
//     Playlist *playlist = &(manager->playlists[playlistIndex]);
//     int numSongs = playlist->numSongs;

//     // Deallocate the memory for the song at the specified index
//     free(playlist->songs[songIndex].lagu);
//     free(playlist->songs[songIndex].artist);
//     free(playlist->songs[songIndex].album);

//     // Shift the remaining songs to fill the gap
//     for (int i = songIndex; i <= numSongs - 1; i++)
//     {
//         playlist->songs[i] = playlist->songs[i + 1];
//     }

//     // Decrement the number of songs in the playlist
//     playlist->numSongs -= 1;
// }

#include "playlist.h"

// Helper function to allocate memory for a new SongNode
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
        // Handle allocation failure
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

void addSong(Playlist* playlist, char* lagu, char* artist, char* album) {
    SongNode* newSong = createSongNode(lagu, artist, album);

    newSong->next = playlist->head;
    playlist->head = newSong;
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

    // Traverse the linked list to the specified songIndex
    while (current != NULL && currentIndex < songIndex) {
        current = current->next;
        currentIndex++;
    }

    // Check if the songIndex is valid
    if (current == NULL) {
        printf("Invalid song index.\n");
        return emptySong;
    }

    // Return the song data at the specified songIndex
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

    // Find the nodes to swap
    for (int i = 0; i <= songIndex2; i++) {
        if (i == songIndex1) {
            node1 = current;
        }
        if (i == songIndex2) {
            node2 = current;
        }
        if (current == NULL) {
            printf("Invalid song index.\n");
            return;
        }
        current = current->next;
    }

    // Swap the songs by swapping the data within the nodes
    Song temp = node1->data;
    node1->data = node2->data;
    node2->data = temp;
}

void deleteSongInPlaylist(PlaylistManager* manager, int playlistIndex, int songIndex) {
    if (!manager || playlistIndex < 0 || playlistIndex >= manager->numPlaylists || songIndex < 0 || songIndex >= MAX_SONGS) {
        printf("Invalid input parameters.\n");
        return;
    }

    Playlist* playlist = &(manager->playlists[playlistIndex]);
    SongNode* current = playlist->head;
    SongNode* previous = NULL;

    // Traverse the linked list to the specified songIndex
    for (int i = 0; i <= songIndex; i++) {
        if (i == songIndex) {
            // Found the node to delete
            if (previous == NULL) {
                // Deleting the head node
                playlist->head = current->next;
            } else {
                // Deleting a non-head node
                previous->next = current->next;
            }

            // Free the memory for the deleted node
            free(current->data.lagu);
            free(current->data.artist);
            free(current->data.album);
            free(current);

            playlist->numSongs--;
            return;
        }

        if (current == NULL) {
            printf("Invalid song index.\n");
            return;
        }

        previous = current;
        current = current->next;
    }
}


Playlist playlistFromPlaylistManager(PlaylistManager* manager, int playlistIndex) {
    Playlist emptyPlaylist;
    emptyPlaylist.head = NULL;
    emptyPlaylist.numSongs = 0;

    if (!manager || playlistIndex < 0 || playlistIndex >= manager->numPlaylists) {
        printf("Invalid input parameters.\n");
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


