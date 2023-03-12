//implement knapsack

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

int main(int argc, char *argv[])
{
    int i, j, n, m, w[MAX], v[MAX], c[MAX][MAX];
    printf("Enter the number of items: ");
    scanf("%d", &n);
    printf("Enter the weights of the items: ");
    for (i = 1; i <= n; i++)
        scanf("%d", &w[i]);
    printf("Enter the values of the items: ");
    for (i = 1; i <= n; i++)
        scanf("%d", &v[i]);
    printf("Enter the capacity of the knapsack: ");
    scanf("%d", &m);
    for (i = 0; i <= n; i++)
        c[i][0] = 0;
    for (j = 0; j <= m; j++)
        c[0][j] = 0;
    for (i = 1; i <= n; i++)
        for (j = 1; j <= m; j++)
            if (w[i] > j)
                c[i][j] = c[i - 1][j];
            else
                c[i][j] = (c[i - 1][j] > c[i - 1][j - w[i]] + v[i]) ? c[i - 1][j] : c[i - 1][j - w[i]] + v[i];
    printf("The maximum value is %d ", c[n][m]);
    return 0;
}

