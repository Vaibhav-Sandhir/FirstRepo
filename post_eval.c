#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Stack
{
    int top;
    int stack[20];
} Stack;

void push(Stack *s, int item)
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

int pop(Stack *s)
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

int evaluate(Stack *s, char postfix[])
{
    int i;
    int op1;
    int op2;
    int ans;
    int n = strlen(postfix);
    for (i = 0; i < n; i++)
    {
        if (postfix[i] == '*' || postfix[i] == '-' || postfix[i] == '/' || postfix[i] == '+')
        {
            op1 = pop(s);
            op2 = pop(s);
            switch (postfix[i])
            {
            case '*':
                ans = op2 * op1;
                push(s, ans);
                break;
            case '/':
                ans = op2 / op1;
                push(s, ans);
                break;
            case '-':
                ans = op2 - op1;
                push(s, ans);
                break;
            case '+':
                ans = op2 + op1;
                push(s, ans);
                break;
            }
        }
        else
        {
            int val = postfix[i] - '0';
            push(s, val);
        }
    }
    return pop(s);
}

void main()
{
    Stack *s, s1;
    s = &s1;
    s->top = -1;
    char postfix[20];
    printf("\nEnter Postfix expression: ");
    scanf("%s", postfix);
    printf("\nAnswer is : %d", evaluate(s, postfix));
}