#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NR_NODURI 10

int time = 0;
int d[10],f[10];
typedef struct g{
    char color[10][10];
    int vizitat[NR_NODURI],mat[NR_NODURI][NR_NODURI];
}graf;
int n;
void citire_date(int n,graf* g)
{
    int i,j;
    printf("numarul de noduri este:");
    scanf("%d",&n);
    if(n>NR_NODURI)
        return ;
    printf("matricea de adiacenta este:");
    for(i = 0;i < n;i++)
        for(j = 0;j < n;j++)
            scanf("%d",&g->mat[i][j]);
    printf("\n");
    for(i = 0;i < n;i++)
      {
       for(j = 0;j < n;j++)
            printf("%d ",g->mat[i][j]);
            printf("\n");
      }
}
void DFS(int var,int n,graf *g)
{
    int i;
    i = var;
    time++;
    d[i] = time;

    printf("%d->%s\ la s %d\n",i,g->color[i],d[i]);
    strcpy(g->color[i], "grey");
    g->vizitat[var]=1;
    for(i = 0; i < n; i++)
        if(i != var)
            if(g->vizitat[i] == 0 && g->mat[var][i] == 1)
            {DFS(i,n,g);

            }
    strcpy(g->color[i],"black");
    f[i] = time;
    printf("%d-timpul final\n",f[i]);

}

int main()
{
    graf* g=(graf*)malloc(sizeof(graf));
    for(int i = 0; i < n;i++)
        strcpy(g->color[i],"white");
    citire_date(n,g);
    DFS(0,n,g);
    return 0;
}
