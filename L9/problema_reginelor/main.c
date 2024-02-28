#include <stdio.h>
#include <stdlib.h>
const int n = 4;
int Sol[n];

void printSol(int Sol[n])
{
    printf("solutia este:\n");
    for(int i = 0; i < n;i++)
        {
         for(int j = 0; j < n;j++)
            if(j == Sol[i])
                printf("R ");
            else
                printf(". ");
            printf("\n");
        }
}

int ok(int r,int c)
{
    for(int i = 0; i < r;i++)
    {
        if(c==Sol[i])
            return 0;    //sa nu fie pe aceeasi coloana
        if(r-i == abs(c-Sol[i]))
            return 0;   //sa nu fie pe aceeasi diagonala
    }
    return 1;
}

void Q(int row)
{
    if(row == n)
    {
        printSol(Sol);
        return;
    }
    for(int i = 0;i < n;i++)
    {
        if(ok(row,i))
            Q(row+1);
    }
}

int main()
{
    Q(0);
    return 0;
}
