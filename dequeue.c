#include <stdio.h>
#include <stdlib.h>
#define max 50

typedef struct Queue
{
    int *arr;
    int front;
    int rear;
} Queue;

int isEmpty(Queue *q)
{
    return (q->rear == -1);
}
int isFull(Queue *q)
{
    return ((q->rear + 1) % max == q->front);
}

void EnqueueR(Queue *q, int element)
{
    if (isFull(q))
    {
        printf("Queue is FUll");
    }
    if (isEmpty(q))
    {
        q->arr[0] = element;
    }
    else
    {
        q->rear = (q->rear + 1) % max;
        q->arr[q->rear] = element;
        printf("\t\t%d %d", q->front, q->rear);
    }
}

void EnqueueF(Queue *q, int element)
{
    if (isFull(q))
    {
        printf("Queue is Full");
    }
    if (isEmpty(q))
    {
        q->arr[0] = element;
        printf("\t\t%d %d", q->front, q->rear);
    }
    else
    {
        q->front = (q->front - 1 + max) % max;
        q->arr[q->front] = element;
        printf("\t\t%d %d", q->front, q->rear);
    }
}

int DequeueF(Queue *q)
{
    int x;
    if (isEmpty(q))
    {
        printf("Queue is Empty");
    }
    else
    {
        x = q->arr[q->front];
        q->front = (q->front + 1) % max;
        printf("\t\t%d %d", q->front, q->rear);
        return x;
    }
}

int DequeueR(Queue *q)
{
    int x;
    if (isEmpty(q))
    {
        printf("Queue is Empty");
    }
    else
    {
        x = q->arr[q->rear];
        q->rear = (q->rear - 1 + max) % max;
        printf("\t\t%d %d", q->front, q->rear);
        return x;
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
    Queue *q, q1;
    q = &q1;
    q->arr = (int *)malloc(max * sizeof(int));
    q->front = 0;
    q->rear = 0;
    int choice, ele;
    while (1)
    {
        printf("\nEnter your choice");
        printf("\n1. Insert at the front");
        printf("\n2. Insert at the rear");
        printf("\n3. Delete from front");
        printf("\n4. Delete from rear");
        printf("\n5. Display");
        printf("\n6. Exit\n");
        scanf("\n%d", &choice);
        switch (choice)
        {
        case 1:
            printf("\nEnter value:\n");
            scanf("%d", &ele);
            EnqueueF(q, ele);
            break;
        case 2:
            printf("\nEnter value:\n");
            scanf("%d", &ele);
            EnqueueR(q, ele);
            break;
        case 3:
            printf("\n%d was deleted from the queue\n", DequeueF(q));
            break;
        case 4:
            printf("\n%d was deleted from the queue\n", DequeueR(q));
            break;
        case 5:
            display(q);
            break;
        case 6:
            exit(0);
        }
    }
}