#include <stdio.h>
#include <stdlib.h>

int x[10];

int n=4;
void afis(int k)
{
    for(int i=0;i<k;i++)
        printf("%d ",x[i]);
    printf("\n");
}
int solutie(int s)
{
    if(s==4)
        return 1;
    else return 0;
}
int ok(int s)
{
    if(s>4)
        return 0;
    else
        return 1;
}
void back(int k,int s)
{

    for(int i=1;i<=10;i++)
    {
        x[k]=i;
        s=s+x[k];
        if(ok(s))
           {

            if(solutie(s))
                afis(k);
            else
                back(k+1,s);
           }
    }
}
int main()
{
    back(0,0);
    return 0;
}
