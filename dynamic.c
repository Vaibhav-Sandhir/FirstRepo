#include<stdio.h>
#include<stdlib.h>

typedef struct {
   int size;
   int top;
   char *stack;
} Stack;

int isEmpty(Stack *s){
    return(s->top == -1);
}

int isFull(Stack *s){
    return(s->top >= (s->size)-1);
}

void Push(Stack *s,char ch){
    if(isFull(s)){
        printf("Stack full doubling the size now\n");
             s->size = s->size * 2;
             s->stack = (char*)realloc(s->stack,s->size*sizeof(char));
        }
    s->stack[++(s->top)]= ch;    
    }

char Pop(Stack *s){
    char cha;
     if(isEmpty(s)){
        printf("Stack Underflow\n");
     }
        return (s->stack[(s->top)--]);
}

void display(Stack *s){
    int i;
    for(i=0;i<=s->top;i++){
       printf("%c",s->stack[i]);
    }
    printf("\t");
}

void main(){
    Stack *s,s1;
    s=&s1;
    char name[100];
    int i;
    char ch;
    s->size = 1;
    s->top = -1;
    s->stack = (char*)calloc(s->size,sizeof(char));
                printf("Enter a string ");
        gets(name);
        while(name[i]!='\0')
            Push(s, name[i++]);
        while(s->top !=-1)
        {
            ch = Pop(s);
            printf("%c\t",ch);
            display(s);
        }
        Pop(s);
}