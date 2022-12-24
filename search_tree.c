#include <stdio.h>
#include <stdlib.h>

typedef struct Node *Nodeptr;
typedef struct Node
{
    int data;
    Nodeptr lchild;
    Nodeptr rchild;
} Node;
Nodeptr getNode()
{
    Nodeptr node = (Node *)malloc(sizeof(Node));
    return node;
}
// RECURSIVE TO CREATE TREE-------------------------------------------------------------
