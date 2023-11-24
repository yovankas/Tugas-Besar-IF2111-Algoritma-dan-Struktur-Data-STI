#include <stdio.h>
#include "circular_queue.h"

/* ********* Prototype ********* */
boolean IsEmptyQueue(Queue Q)
{
    return (Q.idxHead == IDX_UNDEF && Q.idxTail == IDX_UNDEF);
}

boolean IsFullQueue(Queue Q)
{
    return (Length(Q) == IDX_MAX);
}

int Length (Queue Q) {
    int length;
    if (IsEmptyQueue(Q)) {
        length = 0;
    }
    else if (IDX_HEAD(Q) <= IDX_TAIL(Q)) {
        length = IDX_TAIL(Q) - IDX_HEAD(Q) + 1;
    }
    else if (IDX_HEAD(Q) > IDX_TAIL(Q)) {
        length = ((IDX_MAX+1) - IDX_HEAD(Q)) + (IDX_TAIL(Q) + 1);
    }
    return length;
}

void CreateQueue(Queue *Q)
{
    Q->idxHead = IDX_UNDEF;
    Q->idxTail = IDX_UNDEF;
}

void enqueue(Queue *Q, ElTypeQueue X)
{
    if (IsEmptyQueue(*Q))
    {
        Q->idxHead = 0;
        Q->idxTail = 0;
    }
    else
    {
        Q->idxTail = (Q->idxTail + 1) % (IDX_MAX + 1);
    }
    Q->Tab[Q->idxTail] = X;
}

void insertHead(Queue *Q, ElTypeQueue X)
{
    int numElements = (Q->idxTail - Q->idxHead + IDX_MAX) % IDX_MAX + 1;
    ElTypeQueue *tempElements = malloc(numElements * sizeof(ElTypeQueue));

    for (int i = 0; i < numElements; i++)
    {
        tempElements[i] = dequeue(Q);
    }

    enqueue(Q, X);

    for (int i = 0; i < numElements; i++)
    {
        if(tempElements[i].song != NULL)
        {
            enqueue(Q, tempElements[i]);
        }
    }

    free(tempElements);
}

ElTypeQueue dequeue(Queue *Q)
{
    ElTypeQueue X;

    X = Q->Tab[Q->idxHead];
    if (Q->idxHead == Q->idxTail)
    {
        Q->idxHead = IDX_UNDEF;
        Q->idxTail = IDX_UNDEF;
    }
    else
    {
        Q->idxHead = (Q->idxHead + 1) % (IDX_MAX + 1);
    }

    return X;
}

void displayQueue(Queue Q)
{
    int i;

    if (IsEmptyQueue(Q))
    {
        printf("Your queue is empty.\n");
    }
    else
    {
        for (i = Q.idxHead; i != Q.idxTail; i = (i + 1) % (IDX_MAX + 1))
        {
            if (strCompare(Q.Tab[i].album, "") != 0)
            {
                printf("%d. %s - %s - %s\n", (i - Q.idxHead + 1 + IDX_MAX + 1) % (IDX_MAX + 1), Q.Tab[i].artist, Q.Tab[i].song, Q.Tab[i].album);
            }
        }
        printf("%d. %s - %s - %s\n", (i - Q.idxHead + 1 + IDX_MAX + 1) % (IDX_MAX + 1), Q.Tab[i].artist, Q.Tab[i].song, Q.Tab[i].album);
    }
}

void printQueueToFile(FILE *f, Queue Q)
{

    if (IsEmptyQueue(Q))
    {
        printf("Your queue is empty.\n");
    }
    else
    {
        int i;
        for (i = Q.idxHead; i != Q.idxTail; i = (i + 1) % (IDX_MAX + 1))
        {
            if (strCompare(Q.Tab[i].album, "") != 0)
            {
                fprintf(f, "%s;%s;%s\n", Q.Tab[i].artist, Q.Tab[i].album, Q.Tab[i].song);
            }
        }
        fprintf(f, "%s;%s;%s\n", Q.Tab[i].artist, Q.Tab[i].album, Q.Tab[i].song);
    }
}

void swapQueueElmt(Queue *Q, int x, int y)
{
    ElTypeQueue temp = Q->Tab[x];
    Q->Tab[x] = Q->Tab[y];
    Q->Tab[y] = temp;
}

ElTypeQueue removeQueueElmtByIdx(Queue *Q, int idx)
{
    int CAPACITY = IDX_MAX + 1;
    int actualIdx = (Q->idxHead + idx - 1) % CAPACITY;

    ElTypeQueue element = Q->Tab[actualIdx];

    int i;
    for (i = idx - 1; i < (Q->idxTail - Q->idxHead + 1 + CAPACITY) % CAPACITY; i = (i + 1) % CAPACITY)
    {
        Q->Tab[(Q->idxHead + i) % CAPACITY] = Q->Tab[(Q->idxHead + i + 1) % CAPACITY];
    }

    Q->idxTail = (Q->idxTail - 1 + CAPACITY) % CAPACITY;

    return element;
}
