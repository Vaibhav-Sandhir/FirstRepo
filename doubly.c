#include <stdio.h>
#include <stdlib.h>

typedef struct Node *Nodeptr;

typedef struct Node
{
    int data;
    Nodeptr llink;
    Nodeptr rlink;
} Node;

Nodeptr getNode()
{
    Nodeptr node = (Node *)malloc(sizeof(Node));
    return node;
}

void insert_front(Nodeptr *head, int data)
{
    Nodeptr p = (*head)->rlink;
    Nodeptr temp = getNode();
    temp->data = data;
    if (p == NULL)
    {
        (*head)->rlink = temp;
    }
    else
    {
        (*head)->rlink = temp;
        temp->rlink = p;
        p->llink = temp;
    }
}

void insert_back(Nodeptr *head, int data)
{
    Nodeptr temp = getNode();
    temp->data = data;
    Nodeptr p = *head;
    while (p->rlink != NULL)
    {
        p = p->rlink;
    }
    p->rlink = temp;
    temp->llink = p;
}

void insert_index(Nodeptr *head, int data, int index)
{
    Nodeptr temp = getNode();
    temp->data = data;
    Nodeptr p = (*head)->rlink;
    while (index != 0)
    {
        p = p->rlink;
        index--;
    }
    temp->llink = p->llink;
    temp->rlink = p;
    (p->llink)->rlink = temp;
    p->llink = temp;
}

void delete_front(Nodeptr *head)
{
    Nodeptr p = (*head)->rlink;
    (*head)->rlink = p->rlink;
    (p->rlink)->llink = NULL;
    free(p);
}

void delete_back(Nodeptr *head)
{
    Nodeptr p = (*head)->rlink;
    while (p->rlink != NULL)
    {
        p = p->rlink;
    }
    (p->llink)->rlink = NULL;
    p->llink = NULL;
    free(p);
}

void delete_index(Nodeptr *head, int index)
{
    Nodeptr p = (*head);
    while (index != 0)
    {
        p = p->rlink;
        index--;
    }
    (p->llink)->rlink = p->rlink;
    (p->rlink)->llink = p->llink;
    p->rlink = NULL;
    p->llink = NULL;
    free(p);
}

void display(Nodeptr head)
{
    Nodeptr p = head->rlink;
    while (p != NULL)
    {
        printf("  %d", p->data);
        p = p->rlink;
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