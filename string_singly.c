#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node *Nodeptr;

typedef struct Node
{
    char data[100];
    Nodeptr next;
} Node;

Nodeptr getNode()
{
    Nodeptr node = (Node *)malloc(sizeof(Node));
    return node;
}

void insert_front(Nodeptr *head, char data[])
{
    Nodeptr temp = getNode();
    strcpy(temp->data, data);
    temp->next = (*head)->next;
    (*head)->next = temp;
}

void insert_back(Nodeptr *head, char data[])
{
    Nodeptr p;
    p = *head;
    Nodeptr temp = getNode();
    strcpy(temp->data, data);
    while (p->next != NULL)
    {
        p = p->next;
    }
    p->next = temp;
}

void insert_index(Nodeptr *head, char data[], int index)
{
    Nodeptr p = *head;
    Nodeptr q;
    Nodeptr temp = getNode();
    strcpy(temp->data, data);
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
        printf("%s -> ", p->data);
        p = p->next;
    }
    printf("\n");
}

void main()
{
    Nodeptr head = getNode();
    int option, index, item;
    char sent[50];
    char words[50][50] = {0};
    int i, j, k;
    j = 0;
    i = 0;
    k = 0;
    printf("\nEnter sentence: ");
    scanf("%[^\n]s", sent);
    for (i = 0; sent[i] != '\0'; i++)
    {
        if (sent[i] == ' ' && sent[i + 1] != ' ' && sent[i + 1] != '\0')
        {
            insert_back(&head, words[j]);
            j++;
            k = 0;
        }
        else
        {
            words[j][k] = sent[i];
            k++;
        }
    }
    insert_back(&head, words[j]);
    display(head);
    display(head);
}