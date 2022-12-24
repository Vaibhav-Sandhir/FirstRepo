#include <stdio.h>
#include <string.h>
#define max 100
typedef struct{
    int top;
    char stack[max];
}Stack;

void Push(Stack *s,char ele){
    if(s->top==max-1){
        printf("Stack Overflow");
    }
    s->stack[++(s->top)] = ele;
}

void Pop(Stack *s){
    if(s->top < 0){
        printf("Stack Underflow");
    }
    s->stack[s->top--];
}

void main(){
    Stack *s,s1;
    int i;
    char exp[100];
    s = &s1;
    s->top = -1;
    printf("Enter Expression \n");
    scanf("%s",&exp);
    for(i=0;i<strlen(exp);i++){
        if(exp[i] == '(' || exp[i] == '{' || exp[i] == '['){
            Push(s,exp[i]);        
        }
        else if(exp[i] == ')' || exp[i] == '}' || exp[i] == ']'){
            Pop(s);
        }
    }
    if(s->top==-1){
        printf("Balanced");
    }
    else{
        printf("Unbalanced");
    }
}