#ifndef __CONSOLE_H__
#define __CONSOLE_H__

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "./boolean.h"
#include "./ADT/array/array.h"
#include "./ADT/word/word.h"
#include "./ADT/mesin/mesinkata.h"
#include "./ADT/mesin/mesinkarakter.h"
#include "./ADT/set/set.h"
#include "./ADT/album/album.h"
#include "./ADT/penyanyi/penyanyi.h"
#include "./ADT/string/string.h"

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

#endif