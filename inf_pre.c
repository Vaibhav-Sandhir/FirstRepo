#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Stack
{
    char stack[20];
    int top;
} Stack;

void push(Stack *s, char data)
{
    if (s->top == 19)
    {
        printf("\nStack Overflow");
        exit(0);
    }
    else
    {
        s->stack[++s->top] = data;
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

void convert(Stack *s, char infix[], char prefix[])
{
    int i;
    int j = 0;
    for (i = 0; i < strlen(infix); i++)
    {
        if (infix[i] == '+' || infix[i] == '-' || infix[i] == '*' || infix[i] == '/' || infix[i] == '^')
        {
            while (precedence(infix[i]) < precedence(s->stack[s->top]) && s->top != -1)
            {
                prefix[j] = pop(s);
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
                prefix[j] = pop(s);
                j++;
            }
            pop(s);
        }
        else
        {
            prefix[j] = infix[i];
            j++;
        }
    }
    for (i = 0; s->top != -1; i++)
    {
        prefix[j] = pop(s);
        j++;
    }
}

void reverse(char arr[])
{
    int i;
    int j;
    int n = strlen(arr);
    for (i = 0, j = n - 1; i < n / 2; i++, j--)
    {
        char temp;
        temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }
}

void main()
{
    char prefix[20] = {0};
    char infix[20] = {0};
    printf("\nEnter infix expression: ");
    scanf("%s", infix);
    reverse(infix);
    Stack *s, s1;
    s = &s1;
    s->top = -1;
    convert(s, infix, prefix);
    reverse(prefix);
    printf("%s", prefix);
}