#include <stdio.h>
#include <stdlib.h>
#include <string.h>
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
typedef struct Stack
{
    Nodeptr stack[20];
    int top;
} Stack;
int isEmpty(Stack *s)
{
    return (s->top == -1);
}
void push(Stack *s, Nodeptr temp)
{
    s->stack[++s->top] = temp;
}
Nodeptr pop(Stack *s)
{
    return (s->stack[s->top--]);
}
typedef struct Queue
{
    int front;
    int rear;
    Nodeptr *arr;
} Queue;
int isEmptyq(Queue *q)
{
    return q->front == q->rear;
}
void enqueue(Queue *q, Nodeptr temp)
{
    q->arr[++q->rear] = temp;
}
Nodeptr dequeue(Queue *q)
{
    return q->arr[++q->front];
}
int max(int a, int b)
{
    if (a > b)
        return a;
    else
        return b;
}

// RECURSIVE TO CREATE BT UNTIL -1 IS ENTERED---------------------------------------------------
Nodeptr
createTreeRecursive(int item)
{
    int x;

    if (item != -1)
    {
        Nodeptr temp = getNode();
        temp->data = item;

        printf("\nEnter Left Child of %d : ", item);
        scanf("%d", &x);
        temp->lchild = createTreeRecursive(x);

        printf("\nEnter Right Child of %d : ", item);
        scanf("%d", &x);
        temp->rchild = createTreeRecursive(x);

        return temp;
    }
    return NULL;
}
//-------------------------------------------------------------------------------------------

// RECURSIVE TRAVERSALS----------------------------------------------------------------
void inorder_recursive(Nodeptr root)
{
    if (root)
    {
        inorder_recursive(root->lchild);
        printf("  %d", root->data);
        inorder_recursive(root->rchild);
    }
}

void preorder_recursive(Nodeptr root)
{
    if (root)
    {
        printf("  %d", root->data);
        preorder_recursive(root->lchild);
        preorder_recursive(root->rchild);
    }
}

void postorder_recursive(Nodeptr root)
{
    if (root)
    {
        postorder_recursive(root->lchild);
        postorder_recursive(root->rchild);
        printf("  %d", root->data);
    }
}
//----------------------------------------------------------------------------------------

// ITERATIVE TRAVERSAL---------------------------------------------------------------------
void inorder_iterative(Nodeptr root)
{
    Nodeptr cur;
    int done = 0;
    Stack *s, s1;
    s = &s1;
    s->top = -1;
    if (root == NULL)
        return;
    cur = root;
    while (!done)
    {
        while (cur != NULL)
        {
            push(s, cur);
            cur = cur->lchild;
        }
        if (!isEmpty(s))
        {
            cur = pop(s);
            printf("  %d", cur->data);
            cur = cur->rchild;
        }
        else
        {
            done = 1;
        }
    }
}
void preorder_iterative(Nodeptr root)
{
    Stack *s, s1;
    s = &s1;
    s->top = -1;
    Nodeptr cur;
    if (root == NULL)
        return;
    push(s, root);
    while (!isEmpty(s))
    {
        cur = pop(s);
        printf("  %d", cur->data);
        if (cur->rchild)
            push(s, cur->rchild);
        if (cur->lchild)
            push(s, cur->lchild);
    }
}
void postorder_iterative(Nodeptr root)
{
    typedef struct Stackpo
    {
        Nodeptr node;
        int flag;
    } Stackpo;
    Nodeptr cur;
    Stackpo s[20];
    int top = -1;
    if (root == NULL)
        return;
    cur = root;
    for (;;)
    {
        while (cur != NULL)
        {
            s[++top].node = cur;
            s[top].flag = 1;
            cur = cur->lchild;
        }
        while (s[top].flag < 0)
        {
            cur = s[top--].node;
            printf("  %d", cur->data);
            if (top == -1)
                return;
        }
        cur = s[top].node;
        cur = cur->rchild;
        s[top].flag = -1;
    }
}
//-------------------------------------------------------------------------------------

// LEVEL ORDER TRAVERSAL---------------------------------------------------------------
void levelorder(Nodeptr root)
{
    Nodeptr cur = NULL;
    Queue *q, q1;
    q = &q1;
    q->front = -1;
    q->rear = -1;
    if (root == NULL)
        return;
    enqueue(q, root);
    while (!isEmptyq(q))
    {
        cur = dequeue(q);
        printf("  %d", cur->data);
        if (cur->lchild)
            enqueue(q, cur->lchild);
        if (cur->rchild)
            enqueue(q, cur->rchild);
    }
}
// INSERTION IN BT----------------------------------------------------------------------
void insertion(Nodeptr root, char direction[], int item)
{
    if (root == NULL)
        return;
    int i;
    Nodeptr temp, cur, parent;
    temp = getNode();
    temp->data = item;
    temp->lchild = temp->rchild = NULL;
    cur = root;
    parent = NULL;
    i = 0;

    while (cur && direction[i])
    {
        parent = cur;
        if (direction[i] == 'l' || direction[i] == 'L')
        {
            cur = cur->lchild;
        }
        else
        {
            cur = cur->rchild;
        }
        i++;
    }
    if (cur != NULL || direction[i] != '\0')
    {
        printf("\nInsertion not possible");
        free(temp);
        return;
    }
    if (direction[i - 1] == 'L' || direction[i - 1] == 'l')
        parent->lchild = temp;
    else
        parent->rchild = temp;
}
//---------------------------------------------------------------------------------------

// SEARCHING USING PREORDER--------------------------------------------------------------
int search(Nodeptr root, int ele)
{
    static int t = 0;
    if (root)
    {
        if (root->data == ele)
        {
            t++;
            return t;
        }
        if (t == 0)
            search(root->lchild, ele);
        if (t == 0)
            search(root->rchild, ele);
    }
}
//---------------------------------------------------------------------------------------

// COPYING A BINARY TREE USING RECURSION--------------------------------------------------
Nodeptr copy(Nodeptr root)
{
    Nodeptr temp;
    if (root == NULL)
        return NULL;
    temp = getNode();
    temp->data = root->data;
    temp->lchild = copy(root->lchild);
    temp->rchild = copy(root->rchild);
    return temp;
}
//---------------------------------------------------------------------------------------

// HEIGHT OF A BINARY TREE---------------------------------------------------------------
int height(Nodeptr root)
{
    if (root == NULL)
        return 0;
    return (1 + max(height(root->lchild), height(root->rchild)));
}
//---------------------------------------------------------------------------------------

// TOTAL NUMBER OF NODES IN THE TREE-----------------------------------------------------
int count_nodes(Nodeptr root)
{
    static int count = 0;
    if (root != NULL)
    {
        count_nodes(root->lchild);
        count++;
        count_nodes(root->rchild);
    }
    return count;
}
//---------------------------------------------------------------------------------------

// NUMBER OF LEAF NODES IN THE TREE------------------------------------------------------
int count_leaf(Nodeptr root)
{
    static int count = 0;
    if (root != NULL)
    {
        if (root->lchild == NULL && (root->rchild == NULL))
            count++;
        count_leaf(root->lchild);
        count_leaf(root->rchild);
    }
    return count;
}
//---------------------------------------------------------------------------------------

// EQUALITY OF 2 BINARY TREES------------------------------------------------------------
// int equal(Nodeptr root1,Nodeptr root2){
//     return((!root1 && !root2) || (root1 && root2))
// }

// MAIN----------------------------------------------------------------------------------
int main()
{
    Nodeptr root = NULL;
    int item;
    char direction[20];
    printf("\nEnter the root: ");
    scanf("%d", &item);
    root = createTreeRecursive(item);
    printf("\nThe preorder_recursive is : ");
    preorder_recursive(root);
    printf("\nThe preorder_iterative is : ");
    preorder_iterative(root);
    printf("\nThe postorder_recursive is : ");
    postorder_recursive(root);
    printf("\nThe postorder_iterative is : ");
    postorder_iterative(root);
    printf("\nThe inorder_recursive is : ");
    inorder_recursive(root);
    printf("\nThe inorder_iterative is : ");
    inorder_iterative(root);
    printf("\nThe levelorder traversal is : ");
    levelorder(root);
    printf("\nThe height of the tree is %d ", height(root));
    printf("\nThe total number of nodes in the tree are %d ", count_nodes(root));
    printf("\nTotal number of leaf nodes in the tree are %d", count_leaf(root));
    printf("\nEnter the direction string: ");
    scanf("%s", direction);
    printf("\nEnter the element to be inserted: ");
    scanf("%d", &item);
    insertion(root, direction, item);
    printf("\nEnter element to be searched: ");
    if (search(root, 20))
    {
        printf("\nElement Found");
    }
}
