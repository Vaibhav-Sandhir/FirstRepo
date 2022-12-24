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
        int ans = item;
        s->stack[++s->top] = ans;
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

int calculate(Stack *s, char prefix[])
{
    int i;
    int n = strlen(prefix);
    reverse(prefix);
    for (i = 0; i < n; i++)
    {
        if (prefix[i] == '*' || prefix[i] == '+' || prefix[i] == '-' || prefix[i] == '/')
        {
            int op1 = pop(s);
            int op2 = pop(s);
            // printf("%d   %d", op1, op2);
            int ans = 0;
            switch (prefix[i])
            {
            case '*':
                ans = op1 * op2;
                // printf("%d", ans);
                push(s, ans);
                break;
            case '/':
                ans = op1 / op2;
                push(s, ans);
                break;
            case '+':
                ans = op1 + op2;
                push(s, ans);
                break;
            case '-':
                ans = op1 - op2;
                push(s, ans);
                break;
            }
        }
        else
        {
            int val = prefix[i] - '0';
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
    char prefix[20] = {0};
    printf("\nEnter prefix expression: ");
    scanf("%s", prefix);
    printf("\nAnswer is: %d", calculate(s, prefix));
}