//implement longest common subsequences

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

int max(int a, int b)
{
    if(a > b)
        return a;
    else
        return b;
}


int lcs(char *x, char *y, char *z)
{
    int m = strlen(x);
    int n = strlen(y);
    int c[m+1][n+1];
    int i, j;
    for(i = 0; i <= m; i++)
        c[i][0] = 0;
    for(j = 0; j <= n; j++)
        c[0][j] = 0;
    for(i = 1; i <= m; i++)
        for(j = 1; j <= n; j++)
            if(x[i-1] == y[j-1])
                c[i][j] = c[i-1][j-1] + 1;
            else
                c[i][j] = max(c[i-1][j], c[i][j-1]);
    int k = c[m][n];
    z[k] = '\0';
    i = m;
    j = n;
    while(i > 0 && j > 0)
    {
        if(x[i-1] == y[j-1])
        {
            z[k-1] = x[i-1];
            i--;
            j--;
            k--;
        }
        else if(c[i-1][j] > c[i][j-1])
            i--;
        else
            j--;
    }
    return c[m][n];
}

int main()
{
    char x[MAX], y[MAX], z[MAX];
    printf("Enter the first string: ");
    scanf("%s", x);
    printf("Enter the second string: ");
    scanf("%s", y);
    int length = lcs(x, y, z);
    printf("The longest common subsequence is %s and its length is %d ", z, length);
    return 0;
}