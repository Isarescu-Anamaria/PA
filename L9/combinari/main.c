#include <stdio.h>
#include <conio.h>

int n=5,k=4;
int A[]={1,2,3,4,5};
int Sol[20];

void printSol(){
    for(int i = 0;i < k;i++)
        printf("%d ",Sol[i]);
    printf("\n");
}
void Comb(int start,int sol_len){
    if(sol_len == k){
        printSol();
        return;
    }
    for(int i = start;i < n-(k-(sol_len+1));i++){
        Sol[sol_len]=A[i];
        Comb(i+1,sol_len+1);
    }
}

int main() {
    Comb(0,0);
}
