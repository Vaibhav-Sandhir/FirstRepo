#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Stack
{
    int top;
    char stack[20];
} Stack;

void push(Stack *s, char item)
{
    if (s->top == 19)
    {
        printf("\nStack Overflow");
        exit(0);
    }
    else
    {
        s->stack[++s->top] = item;
    }
}

char pop(Stack *s)
{
    if (s->top == -1)
    {
        printf("\nStack Underflow");
        exit(0);
    }
    else
    {
        return s->stack[s->top--];
    }
}

int precedence(char c)
{
    switch (c)
    {
    case '(':
        return 0;
    case '+':
        return 1;
    case '-':
        return 1;
    case '*':
        return 2;
    case '/':
        return 2;
    case '^':
        return 3;
    }
}

void convert(Stack *s, char infix[], char postfix[])
{
    int i;
    int j = 0;
    int n = strlen(infix);
    for (i - 0; i < n; i++)
    {
        if (infix[i] == '*' || infix[i] == '+' || infix[i] == '-' || infix[i] == '/')
        {
            while (precedence(infix[i]) <= precedence(s->stack[s->top]) && s->top != -1)
            {
                postfix[j] = pop(s);
                j++;
            }
            push(s, infix[i]);
        }
        else if (infix[i] == '(')
        {
            push(s, infix[i]);
        }
        else if (infix[i] == ')')
        {
            while (s->stack[s->top] != '(')
            {
                postfix[j] = pop(s);
                j++;
            }
        }
        else
        {
            postfix[j] = infix[i];
            j++;
        }
    }
    while (s->top != -1)
    {
        postfix[j] = pop(s);
        j++;
    }
}

void main()
{
    Stack *s, s1;
    s = &s1;
    s->top = -1;
    char infix[20];
    char postfix[20] = {0};
    printf("\nEnter infix expression: ");
    scanf("%s", infix);
    convert(s, infix, postfix);
    printf("\n%s", postfix);
}
