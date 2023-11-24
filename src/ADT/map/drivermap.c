#include <stdio.h>
#include "map.h"

int main() {
    // Membuat map
    Map penyanyi;
    CreateEmptyMap(&penyanyi);

    // Memasukkan elemen ke map
    InsertInMap(&penyanyi, StringToWord("Penyanyi1"), 20);
    InsertInMap(&penyanyi, StringToWord("Penyanyi2"), 4);
    InsertInMap(&penyanyi, StringToWord("Penyanyi3"), 15);

    // Mengecek apakah terdapat elemen
    Word penyanyiToCheck = StringToWord("Penyanyi2");
    if (IsMemberInMap(penyanyi, penyanyiToCheck)) {
        printf("%s terdapat dalam list.\n", WordToString(penyanyiToCheck));
    } else {
        printf("%s tidak terdapat dalam list.\n", WordToString(penyanyiToCheck));
    }

    return 0;
}
