#include <stdio.h>
#include <stdlib.h>

typedef struct Node *Nodeptr;

typedef struct Node
{
    int data;
    Nodeptr next;
} Node;

Nodeptr getNode()
{
    Nodeptr node = (Node *)malloc(sizeof(Node));
    return node;
}

void enqueue(Nodeptr *front, Nodeptr *rear, int data)
{
    Nodeptr temp = getNode();
    temp->data = data;
    if ((*front)->next == NULL)
    {
        temp->next = (*front)->next;
        (*front)->next = temp;
        (*rear) = temp;
    }
    else
    {
        temp->next = (*front)->next;
        (*front)->next = temp;
    }
}

int dequeue(Nodeptr *front, Nodeptr *rear)
{
    Nodeptr p = *front;
    while (p->next != NULL)
    {
        p = p->next;
    }
    int item = (*rear)->data;
    (*rear) = p;
    free(p->next);
    return item;
}

void main()
{
    Nodeptr front = getNode();
    Nodeptr rear = getNode();
    front->next = NULL;
    enqueue(&front, &rear, 3);
    enqueue(&front, &rear, 2);
    enqueue(&front, &rear, 1);
    printf(" %d", dequeue(&front, &rear));
}