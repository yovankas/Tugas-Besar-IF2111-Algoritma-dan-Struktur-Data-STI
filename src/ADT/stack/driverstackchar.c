#include <stdio.h>
#include "stackchar.h"

int main() {
    Stackchar stack1, stack2, mergedStack;

    // Inisialisasi stack
    CreateEmptyStackChar(&stack1);
    CreateEmptyStackChar(&stack2);

    // Push element
    ElTypeStackchar element1 = {"Artist1", "Album1", "Song1"};
    ElTypeStackchar element2 = {"Artist2", "Album2", "Song2"};
    ElTypeStackchar element3 = {"Artist3", "Album3", "Song3"};

    PushStackChar(&stack1, element1);
    PushStackChar(&stack1, element2);
    PushStackChar(&stack1, element3);

    // Print stack1
    printf("Stack 1:\n");
    printStackchar(stack1);

    // Copy stack1 ke stack2
    CopyStackChar(stack1, &stack2);

    // Push elements stack2
    ElTypeStackchar element4 = {"Artist4", "Album4", "Song4"};
    PushStackChar(&stack2, element4);

    // Print stack2
    printf("\nStack 2:\n");
    printStackchar(stack2);

    // Merge stack1 dan stack2
    mergedStack = MergeStackChar(stack1, stack2);

    // Print merged stack
    printf("\nMerged Stack:\n");
    printStackchar(mergedStack);

    return 0;
}