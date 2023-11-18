#ifndef __CONSOLE_H__
#define __CONSOLE_H__

#include <stdio.h>
#include <stdlib.h>
// #include <string.h>
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

void status(Queue *Q, Playlist *PL, currentSong currentSong, currentPlaylist currentPlaylist);
 /**
 * Konstruktor
 * I.S. Program berjalan, Queue dan Playlist mungkin kosong
 * F.S. Menampilkan current playlist, dan queue
 */
#endif