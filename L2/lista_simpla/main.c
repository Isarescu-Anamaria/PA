#include <stdio.h>
#include <stdlib.h>
//2. Sa se implementeze o functie care insereaza un element intr-o lista simplu inlantuita ordonata.

struct node{
    int data;
    struct node *link;
};

void count_of_nodes(struct node *head){
    int count = 0;
    if(head == NULL)
        printf("Linked list is empty");
    struct node *ptr = NULL;
    ptr = head;
    while(ptr != NULL){
        count++;
        ptr = ptr->link;
    }
    printf("\nnumarul de noduri este: %d\n",count);
}

void print_data(struct node *head){
    if(head == NULL)
        printf("Linked list is empty");
    struct node *ptr = NULL;
    ptr = head;
    while(ptr != NULL){
        printf("%d ",ptr->data);
        ptr = ptr->link;
    }
}

struct node* add_end(struct node *head, int data){
    struct node *ptr, *temp;
    //ptr = (struct node*)malloc(sizeof(struct node));
    temp = (struct node*)malloc(sizeof(struct node));
    temp->data = data;
    temp->link = NULL;
    if(head == NULL)
       {
         head = temp;
         return head;
       }
    else
    {   ptr = head;
        while(ptr->link != NULL)
            ptr = ptr->link;
        ptr->link = temp;
        return head;
    }
}

struct node* add_beg(struct node *head, int d){
    struct node *ptr = (struct node*)malloc(sizeof(struct node));
    ptr->data = d;
    ptr->link = NULL;
    if(head == NULL)
    {
        head = ptr;
        return head;
    }
    else
    {   ptr->link = head;
        head = ptr;
        return head;
    }
}


/* //adaugare element in lista metoda 2(pointer dublu)  main-->add_beg(&head,data)
void add_beg(struct node **head, int d){
    struct node *ptr = (struct node*)malloc(sizeof(struct node));
    ptr->data = d;
    ptr->link = NULL;

    ptr->link = *head;
    *head = ptr;
}
*/


void add_pos(struct node *head, int data, int pos){
    struct node *ptr = head;
    struct node *ptr2 = (struct node*)malloc(sizeof(struct node));
    ptr2->data = data;
    ptr2->link = NULL;

    pos--;
    while(pos != 1){
        ptr = ptr->link;
        pos--;
    }
    ptr2->link = ptr->link;
    ptr->link = ptr2;
}

struct node* del_first(struct node *head){
    if(head == NULL)
        printf("List is already empty");
    else
    {
        struct node *temp = head;
        head = head->link;
        free(temp);
    }
    return head;
}
/*
struct node* del_last(struct node *head){
    if(head == NULL)
        printf("List is already empty");
    else
        if(head->link == NULL)
        {
            free(head);
            head = NULL;
        }
        else
        {
            struct node *temp = head;
            struct node *temp2 = head;
            while(temp->link != NULL)
            {
                temp2 = temp;
                temp = temp->link;
            }
            temp2->link = NULL;
            free(temp);
            temp = NULL;
        }
    return head;
}
*/
// stergere ultimul folosind un singur pointer
void del_last(struct node *head)
{
     if(head == NULL)
        printf("List is already empty");
    else
        if(head->link == NULL)
        {
            free(head);
            head = NULL;
        }
        else
        {
            struct node *temp = head;
            while(temp->link->link != NULL)
            {
                temp = temp->link;
            }
            free(temp->link);
            temp->link = NULL;
        }
}

void del_pos(struct node **head ,int position)
{
    struct node *current = *head;
    struct node *previous = *head;
    if(*head == NULL)
        printf("List is already empty");
    else if(position == 1)
    {
        *head = current->link;
        free(current);
        current = NULL;
    }
    else
    {
        while(position != 1)
        {
            previous = current;
            current = current->link;
            position --;
        }
        previous->link = current->link;
        free(current);
        current = NULL;
    }
}

//functie care sterge toata lista
struct node *del_list(struct node *head)
{
    struct node *temp = head;

    while(temp != NULL)
    {
        temp = temp->link;
        free(head);
        head = temp;
    }
    return head;
}

struct node *search(struct node *head, int key)
{
        struct node *ptr = head;
        while(ptr != NULL)
            if(ptr->data == key)
                return ptr;
            else
                ptr = ptr->link;
        return NULL;
}

struct node *reverse(struct node *head)
{
    struct node *prev = NULL;
    struct node *next = NULL;
    while(head != NULL)
    {
        next = head->link;
        head->link = prev;
        prev = head;
        head = next;
    }
    head = prev;
    return head;
}

int main()
{
    struct node *head;
    head = (struct node*)malloc(sizeof(struct node));
    head = NULL;
    //head->data = 45;
    //head->link = NULL;

    head = add_end(head,98);
    head = add_end(head,3);
    head = add_beg(head,6);
    add_pos(head,37,3);
    print_data(head);
    count_of_nodes(head);
    head = reverse(head);
    printf("\nlista inversata este:\n");
    print_data(head);
    struct node *n = (struct node*)malloc(sizeof(struct node));
    n = search(head,37);
    if(n == NULL)
        printf("\nNULL\n");
    else
    printf("\nnodul cu cheia %d se afla in lista \n",n->data);
    //delete
    printf("\ndupa stergere lista este:\n");
    //head = del_first(head);
    del_last(head);
    //del_pos(&head,2);
    print_data(head);
    count_of_nodes(head);

    //stergere toata lista
   /* head = del_list(head);
    if(head == NULL)
        printf("\nNULL\n");
    count_of_nodes(head);
    */
    return 0;
}
