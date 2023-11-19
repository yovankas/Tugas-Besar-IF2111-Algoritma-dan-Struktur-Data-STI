#ifndef load_H
#define load_H

#include <stdio.h>
#include <stdlib.h>
#include "boolean.h"
#include "./adt/array/array.h"
#include "./adt/word/word.h"
#include "./adt/mesin/mesinkata.h"
#include "./adt/mesin/mesinkarakter.h"
#include "./adt/set/set.h"
#include "./adt/album/album.h"
#include "./adt/penyanyi/penyanyi.h"
#include "./adt/string/string.h"
#include "./adt/queue/circular_queue.h"
#include "./ADT/stack/stackchar.h"
#include "console.h"
#include "./ADT/listplaylist/listplaylist.h"

void load(char* namafile,Array *arrPenyanyi, Array *arrAlbum, Penyanyi *albumPenyanyi, Album *laguAlbum, Set *lagu);

#endif