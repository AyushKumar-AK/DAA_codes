//n queen preoblem 
//optimized solution
#include <stdio.h>
#include <math.h>
int board[20], count;

void queen(int row, int n)
{
    int i, j;
    for (i = 1; i <= n; i++)
    {
        if (place(row, i))
        {
            board[row] = i;
            if (row == n)
            {
                printf("\n\nSolution %d:\n", ++count);
                display(n);
            }
            else
            {
                queen(row + 1, n);
            }
        }
    }
}

int place(int row, int column)
{
    int i;
    for (i = 1; i <= row - 1; i++)
    {
        if (board[i] == column)
        {
            return 0;
        }
        else if (abs(board[i] - column) == abs(i - row))
        {
            return 0;
        }
    }
    return 1;
}

void display(int n)
{
    int i, j;
    for (i = 1; i <= n; i++)
    {
        printf("\n");
        for (j = 1; j <= n; j++)
        {
            if (board[i] == j)
            {
                printf("\tQ");
            }
            else
            {
                printf("\t-");
            }
        }
    }
}


int main()
{
    int n;
    printf("Enter the number of queens: ");
    scanf("%d", &n);
    queen(1, n);
    return 0;
}

//output
// Enter the number of queens: 4
// Solution 1:
//     -    Q    -    -
//     -    -    -    Q
//     Q    -    -    -
//     -    -    Q    -

// Solution 2:
//     -    -    Q    -
//     Q    -    -    -
//     -    -    -    Q
//     -    Q    -    -







