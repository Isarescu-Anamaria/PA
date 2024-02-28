#include <stdio.h>
#include <stdlib.h>
#define MAX 10

int stack_arr[MAX];
int top = -1;

void printStack()
{
    int i;
    if(top == -1)
    {
        printf("stiva este goala\n");
        return;
    }
    for(i = top; i >= 0; i--)
        printf("%d ",stack_arr[i]);
    printf("\n");
}

void push(int data)
{
    if(top == MAX - 1)
    {
        printf("stack overflow\n");
        return;
    }
    top = top + 1;
    stack_arr[top] = data;
}

void pop()
{
    //int value;
    if(top == -1)
    {
        printf("stiva este goala\n");
        exit(1);
    }
   // value = stack_arr[top];
    top = top - 1;
    //return value;
}

int main()
{
    push(1);
    push(2);
    push(3);
    push(4);
    push(5);
    printStack();
    pop();
    pop();
    printStack();
    return 0;
}
