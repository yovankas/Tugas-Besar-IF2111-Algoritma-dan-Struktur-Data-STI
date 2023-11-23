#ifndef SAVE_H
#define SAVE_H

#include <stdio.h>
#include <stdlib.h>
#include "../boolean.h"
#include "../adt/array/array.h"
#include "../adt/word/word.h"
#include "../adt/mesin/mesinkata.h"
#include "../adt/mesin/mesinkarakter.h"
#include "../adt/set/set.h"
#include "../adt/album/album.h"
#include "../adt/penyanyi/penyanyi.h"
#include "../adt/string/string.h"
#include "../adt/queue/circular_queue.h"
#include "../adt/current/current.h"
#include "../adt/stack/stackchar.h"
#include "../ADT/playlist/playlist.h"
#include "console.h"

void save(char *namafile, Array *arrPenyanyi, Penyanyi *albumPenyanyi, Album *laguAlbum, currentSong *currentSong, Queue *Q, Stackchar *History, PlaylistManager *manager, ListPlaylist *listPL);

#endif