#include <stdio.h>

typedef struct ListNode{
    double key;
    struct ListNode* prev;
    struct ListNode* next;
}node;

int main() {
    node lista[65000];
    printf("void* size: %u\n", sizeof(void*)*8);
    printf("size of 65k nodes: %llu\n", sizeof(lista));
    return 0;
}
