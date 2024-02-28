#include <stdio.h>
#include <stdlib.h>

int n = 6;
int A[] = {1,2,3,4,5,6};

void printSol()
{
    for(int i = 0;i < n;i++)
        printf("%d ",A[i]);
    printf("\n");
}
void Perm(int start)
{
    if(start == n)
    {
        printSol();
        return;
    }
    for(int i = start;i < n;i++)
    {
        int aux = A[i];
        A[i] = A[start];
        A[start] = aux;
        Perm(start+1);
        aux = A[i];
        A[i] = A[start];
        A[start] = aux;
    }
}

int main(){
    Perm(0);
    return 0;
}
