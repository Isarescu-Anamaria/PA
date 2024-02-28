#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node* link;
};

struct node* push(struct node **top,int data)
{
    struct node *newNode;
    newNode = (struct node *)malloc(sizeof(newNode));
    if(newNode == NULL)
    {
        printf("Stack overflow");
        exit(1);
    }
    newNode->data = data;
    newNode->link = NULL;
    newNode->link = *top;
    *top = newNode;
    return top;
}

struct node *pop(struct node **top)
{
    struct node *temp;
    temp = *top;
    if(temp == NULL)
    {
        printf("stiva este goala");
        exit(1);
    }
    struct node *ptr;
    ptr = *top;
    *top = ptr->link;
    free(temp);
    temp = NULL;
    return top;
}

void print(struct node *top)
{
    struct node *temp;
    temp = top;
    printf("Elementele stivei sunt:\n");
    while(temp)
    {
        printf("%d ",temp->data);
        temp = temp->link;
    }
    printf("\n");
}

int main()
{
    struct node *top = (struct node*)malloc(sizeof(struct node));
    top = NULL;
    push(&top,1);
    push(&top,2);
    push(&top,3);
    push(&top,4);
    push(&top,5);
    print(top);
    pop(&top);
    pop(&top);
    print(top);
    return 0;
}
