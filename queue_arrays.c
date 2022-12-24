#include <stdio.h>
#include <stdlib.h>
#define max_size 50

typedef struct Queue
{
    int front;
    int rear;
    int *arr;
} Queue;

int isFull(Queue *q)
{
    return q->rear == max_size - 1;
}

int isEmpty(Queue *q)
{
    return q->rear == q->front;
}

void enqueue(Queue *q, int element)
{
    if (isFull(q))
    {
        printf("\nArray is Full\n");
    }
    q->arr[++q->rear] = element;
}

int dequeue(Queue *q)
{
    if (isEmpty(q))
    {
        printf("Queue is empty");
    }
    else
    {
        return q->arr[++q->front];
    }
}

void display(Queue *q)
{
    int i;
    for (i = q->front + 1; i <= q->rear; i++)
    {
        printf("%d\t", q->arr[i]);
    }
}

void main()
{
    Queue q1, *q;
    q = &q1;
    q->front = -1;
    q->rear = -1;
    q->arr = (int *)malloc(max_size * sizeof(int));

    enqueue(q, 35);
    enqueue(q, 36);
    display(q);
    printf("\n%d", dequeue(q));
    enqueue(q, 37);
    printf("\n%d", dequeue(q));
    enqueue(q, 38);
    display(q);
    printf("\n%d", dequeue(q));
}
