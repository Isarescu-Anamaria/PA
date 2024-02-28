#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

struct Queue {
    int front, rear, size;    // rear=spate;front=fata
    int capacity;
    int* array;
};


struct Queue* createQueue(int capacity)
{
    struct Queue* queue = (struct Queue*)malloc(sizeof(struct Queue));
    queue->capacity = capacity;
    queue->front = -1;
    queue->rear = -1;
    queue->size = 0;

    queue->array = (int*)malloc(queue->capacity * sizeof(int));
    return queue;
}

int isFull(struct Queue* queue)
{
    if(queue->size == queue->capacity)
        return 1;
    else
        return 0;
}

// Queue is empty when size is 0
int isEmpty(struct Queue* queue)
{
    if(queue->size == 0)
        return 1;
    else
        return 0;
}

// Function to add an item to the queue.

void enqueue(struct Queue* queue, int item)
{
    if (isFull(queue))
        return;
    queue->rear = queue->rear + 1;
    if(queue->rear == 0)
        queue->front = 0;
    queue->array[queue->rear] = item;
    queue->size = queue->size + 1;
    printf("%d enqueued to queue\n", item);
}

// Function to remove an item from queue.

void dequeue(struct Queue* queue)
{
    if (isEmpty(queue))
        return ;
    int item = queue->array[queue->front];
    queue->front = queue->front + 1;
    queue->size = queue->size - 1;
    printf("%d dequeued from queue\n", item);
}

// Function to get front of queue

void front(struct Queue* queue)
{
    if (isEmpty(queue))
        printf("coada este goala\n");
    else
        printf("primul element este: %d\n",queue->array[queue->front]);
}

// Function to get rear of queue

void rear(struct Queue* queue)
{
    if (isEmpty(queue))
        printf("coada este goala\n");
    else
        printf("ultimul element este: %d\n",queue->array[queue->rear]);
}

int main()
{
    struct Queue* queue = createQueue(1000);

    enqueue(queue, 10);
    enqueue(queue, 20);
    enqueue(queue, 30);
    enqueue(queue, 40);
    dequeue(queue);


    front(queue);
    rear(queue);

    return 0;
}
