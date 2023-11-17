#include <stdio.h>
#include "circular_queue.h"

int main ()
{
    Queue Q;
    CreateQueue(&Q);
    ElTypeQueue q1;
    q1.artist = "BLACKPINK";
    q1.album = "BORN PINK";
    q1.song = "Pink Venom";
    enqueue(&Q, q1);
    displayQueue(Q);
    dequeue(&Q);
    displayQueue(Q);
    return 0;
}