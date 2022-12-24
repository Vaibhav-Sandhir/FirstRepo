#include <stdio.h>
#include <stdlib.h>

// Basically insertion at front and deletion at front where top is head and it is itslef empty

typedef struct Node *Nodeptr;

typedef struct Node
{
    Nodeptr next;
    int data;
} Node;

Nodeptr getNode()
{
    Nodeptr node = (Node *)malloc(sizeof(Node));
    return node;
}

void push(Nodeptr *top, int data)
{
    Nodeptr temp = getNode();
    temp->data = data;
    if ((*top)->next == NULL)
    {
        (*top)->next = temp;
        temp->next = *top;
    }
    else
    {
        temp->next = (*top)->next;
        (*top)->next = temp;
    }
}

int pop(Nodeptr *top)
{
    Nodeptr p = (*top)->next;
    (*top)->next = p->next;
    int item = p->data;
    free(p);
    return item;
}

void main()
{
    Nodeptr head = getNode();
    Nodeptr top = head;
    head->next = top;
    push(&top, 7);
    push(&top, 8);
    push(&top, 9);
    printf("\n%d", pop(&top));
    printf("\n%d", pop(&top));
    printf("\n%d", pop(&top));
}
