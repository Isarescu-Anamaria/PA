#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node *next;
};

void printList(struct node *tail)
{
    struct node *ptr = tail->next;
    do
    {
        printf("%d ",ptr->data);
        ptr = ptr->next;
    }while(ptr != tail->next);
}

struct node *addEmpty(int data)
{
    struct node *temp = (struct node*)malloc(sizeof(struct node));
    temp->data = data;
    temp->next = temp;
    return temp;
}

struct node *add_beg(struct node *tail, int data)
{
    if(tail == NULL)
    {
        struct node *temp = (struct node*)malloc(sizeof(struct node));
        temp->data = data;
        temp->next = temp;
        return temp;
    }
    else
    {
        struct node *newP = (struct node*)malloc(sizeof(struct node));
        newP->data = data;
        newP->next = tail->next;
        tail->next = newP;
        return tail;
    }
}

struct node *add_end(struct node *tail, int data)
{
    if(tail == NULL)
    {
        struct node *temp = (struct node*)malloc(sizeof(struct node));
        temp->data = data;
        temp->next = temp;
        return temp;
    }
    else
    {
        struct node *newP = (struct node*)malloc(sizeof(struct node));
        newP->data = data;
        newP->next = NULL;

        newP->next = tail->next;
        tail->next = newP;
        tail = tail->next;
        return tail;
    }
}

struct node *add_pos(struct node *tail, int data, int pos)
{
    struct node *p = tail->next;
    struct node *newP = (struct node*)malloc(sizeof(struct node));
    newP->data = data;
    newP->next = NULL;
    while(pos > 1)
    {
        p = p->next;
        pos--;
    }
    newP->next = p->next;
    p->next = newP;
    if(p == tail)
        tail = tail->next;
    return tail;
}

struct node *del_first(struct node *tail)
{
    if(tail == NULL)
        return tail;
    if(tail->next == tail)  //este doar un nod in lista
    {
        free(tail);
        tail = NULL;
        return tail;
    }
    struct node *temp = tail->next;
    tail->next = temp->next;
    free(temp);
    temp = NULL;
    return tail;
}

struct node *del_last(struct node *tail)
{
    if(tail == NULL)
        return tail;
    struct node *temp = tail->next;
    if(tail->next == tail)  //este doar un nod in lista
    {
        free(tail);
        tail = NULL;
        return tail;
    }
    while(temp->next != tail)
        temp = temp->next;
    temp->next = tail->next;
    free(tail);
    tail = temp;
    return tail;
}

struct node *del_pos(struct node *tail, int pos)
{
    if(tail == NULL)
        return tail;
    struct node *temp = tail->next;
    if(tail->next == tail)  //este doar un nod in lista
    {
        free(tail);
        tail = NULL;
        return tail;
    }
    while(pos > 2)
    {
        temp = temp->next;
        pos--;
    }
    struct node* temp2 = temp->next;
    temp->next = temp2->next;
    //daca stergem ultimul nod
    if(temp2 == tail)
        tail = temp;
    free(temp2);
    temp2 = NULL;
    return tail;
}

struct node *search(struct node *tail, int key)
{
    struct node *temp;
    if(tail == NULL)
        return NULL;

    temp = tail->next;
    do{
        if(temp->data == key)
            return temp;
        temp = temp->next;
    }while(temp != tail->next);
    return NULL;
}

int main()
{
    struct node *tail = NULL;
    tail = add_beg(tail, 45);
    tail = add_beg(tail, 34);
    tail = add_end(tail, 6);
    tail = add_end(tail, 56);
    tail = add_pos(tail, 67 ,2);
    printList(tail);
   // printf("\nlista dupa stergere este:\n");
   // tail = del_first(tail);
   // tail = del_last(tail);
   // tail = del_pos(tail, 2);
   // printList(tail);
    struct node *n = (struct node*)malloc(sizeof(struct node));
    n = search(tail, 34);
    if(n == NULL)
        printf("\nNULL\n");
    else
        printf("elementul cu cheia %d se afla in lista",n->data);
    return 0;
}
