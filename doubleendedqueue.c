#include <stdio.h>
#include <stdlib.h>
#define MAX 10

typedef struct Queue
{
    int front;
    int rear;
    int queue[MAX];
} Queue;

int isEmpty(Queue *q)
{
    return q->front == q->rear;
}

int isFull(Queue *q)
{
    return q->rear == MAX - 1;
}

void EnqueueF(Queue *q, int item)
{
    if (isFull)
    {
        printf("\nQueue is Full");
        return;
    }
    q->queue[++q->front] = item;
}