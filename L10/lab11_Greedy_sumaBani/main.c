/*#include <stdio.h>
#include <stdlib.h>

#define MAX 1000000

int fmax(int a[],n,max)
{
    int i;
    for(i = 0; i < n ; i++)
        if(a[i] > max)
            max = a[i];
    return max;
}

int main()
{
    int x;
    int a = {1,5,10,50,100,200,500};
    scanf("%d",&x);
    printf("suma de bani este:%d",x);
    int suma_max;
    int suma_ramasa;
    while(a)
    {

    }
    return 0;
}
*/

#include <stdio.h>
#define COINS 7
#define MAX 20

// All denominations of Indian Currency
int coins[COINS] = { 1, 5, 10, 50, 100, 200, 2000 };

void findMin(int cost)
{
    int coinList[MAX] = { 0 };
    int i, k = 0;

    for (i = COINS - 1; i >= 0; i--) {
        while (cost >= coins[i]) {
            cost -= coins[i];
            // Add coin in the list
            coinList[k++] = coins[i];
        }
    }

    for (i = 0; i < k; i++) {
        // Print
        printf("%d ", coinList[i]);
    }
    return;
}

int main()
{
    // input value
    int n = 93;

    printf("Following is minimal number"
           "of change for %d: ",
           n);
    findMin(n);
    return 0;
}
