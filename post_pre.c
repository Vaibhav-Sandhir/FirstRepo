#include <stdio.h>
#include <string.h>
#include <stdlib.h>
typedef struct
{
    char arr[50][50];
    int top;
} Stack;
void push(Stack *s, char str[])
{
    strcpy(s->arr[++s->top], str);
}
char *pop(Stack *s)
{
    return s->arr[s->top--];
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
    Stack st;
    st.top = -1;

    char prefix[50], postfix[50];
    int i;
    printf("Enter prefix expression : ");
    scanf("%s", prefix);
    printf("Prefix : %s\n", prefix);

    for (i = strlen(prefix) - 1; i >= 0; i--)
    {
        char ch = prefix[i];

        if (ch == '+' || ch == '-' || ch == '*' || ch == '/')
        {
            char *op1 = pop(&st);
            char *op2 = pop(&st);
            char postfix[] = {ch, '\0'};
            strcat(postfix, op2);
            strcat(postfix, op1);
            push(&st, postfix);
        }
        else
        {
            char postfix[] = {ch, '\0'};
            push(&st, postfix);
        }
    }
    char *temp = pop(&st);
    reverse(temp);
    printf("Postfix expression : %s", temp);
}