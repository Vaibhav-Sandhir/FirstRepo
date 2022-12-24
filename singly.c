#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

void insert_front(Nodeptr *head, int data)
{
    Nodeptr temp = getNode();
    temp->data = data;
    temp->next = (*head)->next;
    (*head)->next = temp;
}

void insert_back(Nodeptr *head, int data)
{
    Nodeptr p;
    p = *head;
    Nodeptr temp = getNode();
    temp->data = data;
    while (p->next != NULL)
    {
        p = p->next;
    }
    p->next = temp;
}

void insert_index(Nodeptr *head, int data, int index)
{
    Nodeptr p = *head;
    Nodeptr q;
    Nodeptr temp = getNode();
    temp->data = data;
    while (index != 0)
    {
        p = p->next;
        index--;
    }
    q = p->next;
    p->next = temp;
    temp->next = q;
}

void delete_front(Nodeptr *head)
{
    Nodeptr p;
    p = (*head)->next;
    (*head)->next = p->next;
    free(p);
}

void delete_back(Nodeptr *head)
{
    Nodeptr p, q;
    p = (*head)->next;
    q = *head;
    while (p->next != NULL)
    {
        p = p->next;
        q = q->next;
    }
    free(p);
    q->next = NULL;
}

void delete_index(Nodeptr *head, int index)
{
    Nodeptr p, q;
    p = (*head)->next;
    q = *head;
    while (index != 0)
    {
        p = p->next;
        q = q->next;
        index--;
    }
    q->next = p->next;
    free(p);
}

void display(Nodeptr head)
{
    Nodeptr p = head->next;
    while (p != NULL)
    {
        printf("  %d", p->data);
        p = p->next;
    }
    printf("\n");
}

void main()
{
    Nodeptr head = getNode();
    head->data = NULL;
    int option, index, item;
    while (1)
    {
        printf("\n1.Inset Front\n2.Insert Back\n3.Insert at Index\n4.Delete Front\n5.Delete Back\n6.Delete at Index\n7.Display\n");
        scanf("%d", &option);
        switch (option)
        {
        case 1:
            printf("\nEnter data: ");
            scanf("%d", &item);
            insert_front(&head, item);
            break;
        case 2:
            printf("\nEnter data: ");
            scanf("%d", &item);
            insert_back(&head, item);
            break;
        case 3:
            printf("\nEnter data and index 0 is head: ");
            scanf("%d %d", &item, &index);
            insert_index(&head, item, index);
            break;
        case 4:
            delete_front(&head);
            break;
        case 5:
            delete_back(&head);
            break;
        case 6:
            printf("\nEnter index: ");
            scanf("%d", &index);
            delete_index(&head, index);
            break;
        case 7:
            display(head);
            break;
        case -1:
            exit(0);
        }
    }
}