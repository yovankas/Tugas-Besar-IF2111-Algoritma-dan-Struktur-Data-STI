#include <stdio.h>
#include "stackchar.h"

int main() {
    Stackchar stack1, stack2, mergedStack;

    // Initialize stacks
    CreateEmptyStackChar(&stack1);
    CreateEmptyStackChar(&stack2);

    // Push elements to stack1
    ElTypeStackchar element1 = {"Artist1", "Album1", "Song1"};
    ElTypeStackchar element2 = {"Artist2", "Album2", "Song2"};
    ElTypeStackchar element3 = {"Artist3", "Album3", "Song3"};

    PushStackChar(&stack1, element1);
    PushStackChar(&stack1, element2);
    PushStackChar(&stack1, element3);

    // Print stack1
    printf("Stack 1:\n");
    printStackchar(stack1);

    // Copy stack1 to stack2
    CopyStackChar(stack1, &stack2);

    // Push more elements to stack2
    ElTypeStackchar element4 = {"Artist4", "Album4", "Song4"};
    PushStackChar(&stack2, element4);

    // Print stack2
    printf("\nStack 2:\n");
    printStackchar(stack2);

    // Merge stack1 and stack2
    mergedStack = MergeStackChar(stack1, stack2);

    // Print the merged stack
    printf("\nMerged Stack:\n");
    printStackchar(mergedStack);

    return 0;
}