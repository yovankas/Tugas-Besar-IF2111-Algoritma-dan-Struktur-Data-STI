#include <stdio.h>
#include "album.h"

int main ()
{
    Album bum;
    CreateEmptyAlbum(&bum);
    Set isi;
    CreateEmptySet(&isi);
    char *c = "lalala";
    char *d = "xixixi";
    char *f = "babii";
    InsertSet(&isi, c);
    InsertSet(&isi, d);
    InsertSet(&isi, f);
    printf("isi set isi :\n");
    PrintSet(isi);

    InsertInAlbum(&bum, "AM", isi);
    PrintAlbumLagu(bum, "AM");

    infotype song = LaguFromAlbum(bum, "AM", 0);


    return 0;
}