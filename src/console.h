#ifndef __CONSOLE_H__
#define __CONSOLE_H__

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "load.h"
#include "./boolean.h"
#include "./ADT/array/array.h"
#include "./ADT/word/word.h"
#include "./ADT/mesin/mesinkata.h"
#include "./ADT/mesin/mesinkarakter.h"
#include "./ADT/set/set.h"
#include "./ADT/album/album.h"
#include "./ADT/penyanyi/penyanyi.h"
#include "./ADT/string/string.h"
#include "./ADT/queue/circular_queue.h"
#include "./ADT/stack/stackchar.h"
#include "./ADT/playlist/playlist.h"
#include "./ADT/current/current.h"
#include "./ADT/listplaylist/listplaylist.h"

void Delay (unsigned int Sec);

void start(Array *arrPenyanyi, Array *arrAlbum, Penyanyi *albumPenyanyi, Album *laguAlbum, Set *lagu);

void quit();
/*
 * Konstruktor
 * I.S. Program berjalan
 * F.S. Keluar dari program dengan atau tanpa menyimpan data di sesi tersebut
 */

void help(boolean startcheck);
/**
 * Konstruktor
 * I.S. Program berjalan
 * F.S. Menampilkan daftar command yang mungkin untuk dieksekusi dengan deskripsinya
 */ 

void listDefault(Array arrPenyanyi, Penyanyi albumPenyanyi, Album laguAlbum);
/**
 * Konstruktor
 * I.S. Program berjalan
 * F.S. Menampilkan list penyanyi, list album dari seorang penyanyi, serta list lagu dari suatu album
 */ 

void queueSong (Queue *Q, Array arrPenyanyi, Penyanyi albumPenyanyi, Album laguAlbum);
/**
 * Konstruktor
 * I.S. Program berjalan
 * F.S. Menambahkan sebuah lagu ke dalam queue
 */ 

void playSong (Queue *Q, Stackchar *History, Array arrPenyanyi, Penyanyi albumPenyanyi, Album laguAlbum, currentSong currentSong);
/**
 * Konstruktor
 * I.S. Program berjalan, Queue dan History bisa saja memiliki isi ataupun kosong
 * F.S. Memainkan lagu berdasarkan nama penyanyi, nama album, dan ID lagu
 *      Queue dan History kosong
 */

void status(Queue *Q, Playlist *playlistLagu, currentSong currentSong, currentPlaylist currentPlaylist);
 /**
 * Konstruktor
 * I.S. Program berjalan, Queue dan Playlist mungkin kosong
 * F.S. Menampilkan current playlist, dan queue
 */

void listPlaylist(ListPlaylist listPL);
/**
 * Konstruktor
 * I.S. Program berjalan
 * F.S. Menampilkan list playlist
 */

void queuePlaylist(Queue *Q, Playlist *playlistLagu);
/**
 * Konstruktor
 * I.S. Program berjalan
 * F.S. Menambahkan playlist ke dalam queue
 */


void songNext(Queue *Q, currentSong currentSong, nextSong nextSong);
 /**
 * Konstruktor
 * I.S. Program berjalan, queue mungkin kosong
 * F.S. Memutar lagu selanjutnya 
        Jika queue kosong maka diputar current song
*/

void songPrevious(Queue *Q, Stackchar *History, currentSong currentSong);
/**
 * Konstruktor
 * I.S. Program berjalan, history mungkin kosong
 * F.S. Memutar lagu sebelumnya  
        Jika history kosong maka diputar current song
*/

void CreatePlaylist(ListPlaylist listPL, Playlist PL);
/**
 * I.S. Listplaylist masih seperti sebelum
 * F.S. Membuat playlist baru dan menambahkannya ke list playlist
*/
#endif