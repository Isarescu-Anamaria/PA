#include <stdio.h>
#include <stdlib.h>

int count(int coins[], int n, int rest)
{
    // If sum is 0 then there is 1 solution
    // (do not include any coin)
    if (rest == 0)
        return 1;

    // If sum is less than 0 then no
    // solution exists
    if (rest < 0)
        return 0;

    // If there are no coins and sum
    // is greater than 0, then no
    // solution exist
    if (n <= 0)
        return 0;

    // count is sum of solutions (i)
    // including coins[n-1] (ii) excluding coins[n-1]
    return count(coins, n - 1, rest) + count(coins, n, rest - coins[n - 1]);

}

int main()
{
    int i, j;
    int coins[] = { 1, 2, 3 };
    int n = sizeof(coins) / sizeof(coins[0]);
    int rest = 4;
    printf("restul este: %d\n",rest);
    printf("numarul de monede necesare este: %d\n", count(coins, n, rest));

    return 0;
}
