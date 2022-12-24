#include <stdio.h>
#include <ctype.h>
#define max 100

typedef struct Stack
{
    char stack[100];
    int top;
} Stack;

void Push(Stack *s, char item)
{
    if (s->top == max - 1)
    {
        printf("Stack Overflow");
    }
    s->stack[++(s->top)] = item;
}

char Pop(Stack *s)
{
    if (s->top < 0)
    {
        printf("Stack Undeflow");
    }
    return (s->stack[s->top--]);
}

void display(Stack *s)
{
    int i;
    for (i = 0; i <= (s->top); i++)
    {
        printf("%c", s->stack[i]);
    }
    printf("\t");
}

void main()
{
    char name[100];
    char ch = '\0';
    int i = 0;
    Stack s1, *s;
    s = &s1;
    s->top = -1;
    printf("Enter a string ");
    gets(name);
    while (name[i] != '\0')
        Push(s, name[i++]);
    while (s->top != -1)
    {
        ch = Pop(s);
        printf("%c\t", ch);
        display(s);
    }
    return;
}