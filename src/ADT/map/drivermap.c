#include "map.h"
#include <stdio.h>

int main() {
    //buat map baru
    Map newMap;
    CreateEmptyMap(&newMap);

    // masukkan key-value ke map
    InsertInMap(&newMap, stringToWord("Alice"), 25);
    InsertInMap(&newMap, stringToWord("Bob"), 30);
    InsertInMap(&newMap, stringToWord("Charlie"), 20);

    // Print map
    printf("Initial Map:\n");
    PrintMap(newMap);

    // Tes IsMemberInMap
    Word searchKey = stringToWord("Bob");
    if (IsMemberInMap(newMap, searchKey)) {
        printf("%s adalah member dari map.\n", WordToString(searchKey));
    } else {
        printf("%s bukan member dari map.\n", WordToString(searchKey));
    }

    // Test ValueInMap
    printf("Value %s: %d\n", WordToString(searchKey), ValueInMap(newMap, searchKey));

    // Tes DeleteInMap
    DeleteInMap(&newMap, searchKey);
    printf("Map setelah penghapusan %s:\n", WordToString(searchKey));
    PrintMap(newMap);

    // Tes IsEQMap
    Map anotherMap;
    CreateEmptyMap(&anotherMap);
    InsertInMap(&anotherMap, stringToWord("Alice"), 25);
    InsertInMap(&anotherMap, stringToWord("Charlie"), 20);

    if (IsEQMap(newMap, anotherMap)) {
        printf("Map nya equal.\n");
    } else {
        printf("Map nya tidak equal.\n");
    }

    return 0;
}
