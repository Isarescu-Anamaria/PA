#include <stdio.h>
#include <iostream>

typedef struct ListNode1 {
    double key;
    struct ListNode1* prev;
    struct ListNode1* next;
}node1;

typedef struct ListNode2 {
    struct ListNode2* prev;
    double key;
    struct ListNode2* next;
}node2;

typedef struct ListNode3 {
    struct ListNode3* prev;
    struct ListNode3* next;
    double key;
}node3;

int main() {
    node1 lista[65000];
    node2 lista2[65000];
    node3 lista3[65000];
    const int FACTOR = 1000;
    printf("void* size: %u\n", sizeof(void*) * 8);
    printf("size of 65k nodes 1(B): %u\n", sizeof(lista));
    printf("size of 65k nodes 1(KB): %f\n", (float) sizeof(lista) / FACTOR);
    printf("size of 65k nodes 1(MB): %f\n", (float)sizeof(lista) / FACTOR / FACTOR);
    printf("size of 65k nodes 2(B): %u\n", sizeof(lista2));
    printf("size of 65k nodes 2(KB): %f\n", (float)sizeof(lista2) / FACTOR);
    printf("size of 65k nodes 2(MB): %f\n", (float)sizeof(lista2) / FACTOR / FACTOR);
    printf("size of 65k nodes 3(B): %u\n", sizeof(lista3));
    printf("size of 65k nodes 3(KB): %f\n", (float)sizeof(lista3) / FACTOR);
    printf("size of 65k nodes 3(MB): %f\n", (float)sizeof(lista3) / FACTOR / FACTOR);
    printf("size of (ptr, double, ptr): (%u,%u,%u)\n", sizeof(ListNode2*), sizeof(double), sizeof(ListNode2*));
    printf("size of node1: %u\n", sizeof(node1));
    printf("size of node2: %u\n", sizeof(node2));
    printf("size of node3: %u\n", sizeof(node3));
    std::cout << "alignment of node1: " << alignof(ListNode1) << std::endl;
    std::cout << "alignment of node2: " << alignof(ListNode2) << std::endl;
    std::cout << "alignment of node3: " << alignof(ListNode3) << std::endl;
    return 0;
}   