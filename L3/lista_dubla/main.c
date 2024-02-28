#include <stdio.h>
#include <stdlib.h>

struct node{
    struct node *prev;
    int data;
    struct node *next;
};

void print_list(struct node *head)
{
    struct node *ptr = head;
    while(ptr != NULL)
    {
        printf("%d ",ptr->data);
        ptr = ptr->next;
    }
    printf("\n");
}

void print_backward(struct node *head)
{
    struct node *ptr = head;
    while(ptr->next != NULL)
        ptr = ptr->next;
    while(ptr->prev != head->prev)
    {
        printf("%d ",ptr->data);
        ptr = ptr->prev;
    }
    printf("%d ",head->data);
    printf("\n");
}

struct node* add_beg(struct node *head, int data)
{
        struct node *temp = (struct node*)malloc(sizeof(struct node));
        temp->prev = NULL;
        temp->data = data;
        temp->next = NULL;
    if(head == NULL)
    {
        head = temp;
        return head;
    }
    else
    {
        temp->next = head;
        head->prev = temp;
        head = temp;
        return head;
    }
}

struct node *add_end(struct node *head, int data)
{
        struct node *temp , *tp;
        temp = (struct node*)malloc(sizeof(struct node));
        temp->prev = NULL;
        temp->data = data;
        temp->next = NULL;
        if(head == NULL)
        {
            head = temp;
            return head;
        }
        else
        {   tp = head;
            while(tp->next != NULL)
                tp = tp->next;
            tp->next = temp;
            temp->prev = tp;
            return head;
        }
}

 struct node *add_after_pos(struct node *head, int data, int position)
 {
        struct node *newP = NULL;
        struct node *temp = head;
        struct node *temp2 = NULL;

        struct node *n;
        n = (struct node*)malloc(sizeof(struct node));
        n->prev = NULL;
        n->data = data;
        n->next = NULL;
        newP = n;

        while(position != 1)
        {
            temp = temp->next;
            position--;
        }
        if(temp->next == NULL)
        {
            temp->next = newP;
            newP->prev = temp;
        }
        else
        {
            temp2 = temp->next;
            temp->next = newP;
            temp2->prev = newP;
            newP->next = temp2;
            newP->prev = temp;
        }
        return head;
 }

//functie creare lista
struct node* createList(struct node *head)
{
    int n,data,i;
    printf("Nmarul de noduri este: ");
    scanf("%d", &n);

    if(n==0)
        return head;

    for(i = 0;i < n; i++)
    {
        printf("Elementu pt nodul %d este: ",i+1);
        scanf("%d", &data);
        head = add_end(head, data);
    }

}

struct node *del_first(struct node *head)
{
    struct node *temp = head;
    head = head->next;
    free(temp);
    temp = NULL;
    head->prev = NULL;
    return head;
}

struct node *del_last(struct node *head)
{
    struct node *temp = head;
    struct node *temp2;
    while(temp->next != NULL)
        temp = temp->next;
    temp2 = temp->prev;
    temp2->next = NULL;
    free(temp);
    return head;
}

struct node *del_pos(struct node *head, int position)
{
    struct node *temp = head;
    struct node *temp2 = NULL;
    if(position == 1)
    {
        head = del_first(head);
        return head;
    }
    while(position > 1)
    {
        temp = temp->next;
        position--;
    }
    if(temp->next == NULL)
        head = del_last(head);
    else
    {
        temp2 = temp->prev;
        temp2->next = temp->next;
        temp->next->prev = temp2;
        free(temp);
        temp = NULL;
    }
    return head;
}

// cautare nod

struct node *search(struct node *head, int key)
{
    struct node *ptr = head;
    while(ptr != NULL)
    {
        if(ptr->data == key)
            break;
        ptr = ptr->next;
    }
    return ptr;
}

int main()
{
    struct node *head = (struct node*)malloc(sizeof(struct node));
    head = NULL;
    head = add_beg(head,12);
    head = add_beg(head,30);
    head = add_end(head,9);
    head = add_end(head,34);
    int position = 2;
    head = add_after_pos(head, 25, position);
    print_list(head);
   // head = createList(head);
    //printf("Lista dupa stergere este:\n");
    //head = del_first(head);
    //head = del_last(head);
    //head = del_pos(head,2);
    //print_list(head);
    //printf("Lista afisata invers este:\n");
    //print_backward(head);
    struct node *n = (struct node*)malloc(sizeof(struct node));
    n = search(head,9);
    if(n == NULL)
        printf("NULL");
    else
        printf("nodul se afla in lista si acesta este: %d",n->data);
    return 0;
}
