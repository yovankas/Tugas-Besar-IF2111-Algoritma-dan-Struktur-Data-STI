#ifndef playlist_H
#define playlist_H

#include <stdio.h>
#include "../../boolean.h"
#include "../../adt/mesin/mesinkata.h"
#include "../../adt/album/album.h"
#include "../../adt/array/array.h"
#include "../../ADT/playlist/listlinier.h"


void CREATEPlaylist();
/* I.S. Sembarang*/
/* F.S. Membuat playlist baru kosong*/

void ADDSongPlaylist();
/* I.S. Playlist mungkin kosong, Playlist tidak penuh*/
/* F.S. Melakukan alokasi sebuah song dan ditambahkan sebagai elemen list di akhir*/

void ADDAlbumPlaylist();
/* I.S. Playlist mungkin kosong, Playlist tidak penuh*/
/* F.S. Melakukan alokasi sebuah album dan ditambahkan sebagai elemen list di akhir*/

void SWAPSongPlaylist();
/* I.S. Playlist tidak boleh kosong*/
/* Menukar posisi lagu urutan x dan urutan y di playlist urutan id*/
/* F.S. Lagu di urutan x dan y di playlist id sudah ditukar*/

void REMOVESongPlaylist();
/* I.S. Playlist tidak boleh kosong*/
/* Menghapus lagu dengan urutan n pada playlist dengan index id.*/
/* F.S. elemen lagu urutan n pada playlist id sudah dihapus dan di-dealokasi*/

void DELETEPlaylist();
/* I.S. Daftar Playlist tidak boleh kosong*/
/* Menghapus playlist pada daftar playlist dengan index id.*/
/* F.S. Playlist yang ada di daftar playlist pengguna dihapus dan di-dealokasi*/

#endif