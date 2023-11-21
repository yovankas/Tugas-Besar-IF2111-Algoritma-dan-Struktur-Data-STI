#include <stdio.h>
#include "penyanyi.h"

int main() {
    Penyanyi penyanyi1 = CreateEmptyPenyanyi();
    Penyanyi penyanyi2 = CreateEmptyPenyanyi();

    // Insert bbrp data
    valuetypePenyanyi albums1;
    InitArray(&albums1, 5);
    albums1.TI[0] = "Album 1";
    albums1.TI[1] = "Album 2";
    albums1.TI[2] = "Album 3";
    albums1.TI[3] = "Album 4";
    albums1.TI[4] = "Album 5";

    InsertInPenyanyi(&penyanyi1, "Singer1", albums1);

    // menunjukkan album dari penyanyi1;
    printf("Albums Singer1:\n");
    PrintAlbumPenyanyi(penyanyi1, "Singer1");
    printf("\n");

    // Insert data
    valuetypePenyanyi albums2;
    InitArray(&albums2, 3);
    albums2.TI[0] = "Album A";
    albums2.TI[1] = "Album B";
    albums2.TI[2] = "Album C";

    InsertInPenyanyi(&penyanyi1, "Singer2", albums2);

    // menunjukkan album dari penyanyi2
    printf("Albums Singer2:\n");
    PrintAlbumPenyanyi(penyanyi1, "Singer2");
    printf("\n");

    // Copy penyanyi1 ke penyanyi2
    CopyPenyanyi(&penyanyi2, penyanyi1);

    // Menunjukkan album yg sudah dicopy ke penyanyi2
    printf("Albums Singer1 di penyanyi2:\n");
    PrintAlbumPenyanyi(penyanyi2, "Singer1");
    printf("\n");

    // Delete Singer1 dari penyanyi2
    DeleteInPenyanyi(&penyanyi2, "Singer1");

    // Display album Singer1 di penyanyi2 setelah penghapusan
    printf("Albums Singer1 dlm penyanyi2 setelah penghapusan:\n");
    PrintAlbumPenyanyi(penyanyi2, "Singer1");
    printf("\n");

    return 0;
}
