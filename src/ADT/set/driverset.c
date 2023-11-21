#include <stdio.h>
#include "set.h"

int main() {
    Set set1, set2, unionSet, intersectionSet, symmetricDiffSet, subtractSet;

    // inisialisasi
    CreateEmptySet(&set1);
    CreateEmptySet(&set2);

    // Masukkan elemen ke set1
    InsertSet(&set1, "apple");
    InsertSet(&set1, "banana");
    InsertSet(&set1, "orange");

    // Masukkan elemen ke set2
    InsertSet(&set2, "banana");
    InsertSet(&set2, "grape");
    InsertSet(&set2, "kiwi");

    // Tes operation basic
    printf("Set 1:\n");
    PrintSet(set1);

    printf("\nSet 2:\n");
    PrintSet(set2);

    //Tes apakah banana adalah elemen dari set2
    if(!IsMemberSet(set2, "banana")){
        printf("Banana ga ada di set2");
    } else {
        printf("Banana ada :D");
    }

    unionSet = SetUnion(set1, set2);
    printf("\nUnion of Set 1 and Set 2:\n");
    PrintSet(unionSet);

    intersectionSet = SetIntersection(set1, set2);
    printf("\nIntersection of Set 1 and Set 2:\n");
    PrintSet(intersectionSet);

    symmetricDiffSet = SetSymmetricDifference(set1, set2);
    printf("\nSymmetric Difference of Set 1 and Set 2:\n");
    PrintSet(symmetricDiffSet);

    subtractSet = SetSubtract(set1, set2);
    printf("\nSet 1 - Set 2:\n");
    PrintSet(subtractSet);


    //Hapus elemen
    DeleteSetElement(&set2, "banana");
    PrintSet(set2);

    return 0;
}