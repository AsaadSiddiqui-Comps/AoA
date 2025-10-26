#include <stdio.h>
#include <stdlib.h>

int x[20];
int j;

int place(int k, int l)
{
    for (j = 1; j < k; j++)
    {
        if (x[j] == l)
            return 0;
        if (abs(x[j] - l) == abs(j - k))
            return 0;
    }
    return 1;
}

void Nqueens(int k, int n)
{
    int i;
    for (i = 1; i <= n; i++)
    {
        if (place(k, i))
        {
            x[k] = i;
            if (k == n)
            {
                for (j = 1; j <= n; j++)
                {
                    printf("%d ", x[j]);
                }
                printf("\n");
            }
            else
            {
                Nqueens(k + 1, n);
            }
        }
    }
}

int main()
{
    int n;
    
    printf("Enter the number of queens (N <= 19): ");
    if (scanf("%d", &n) != 1 || n < 1 || n > 19) {
        printf("Invalid input. Please enter an integer between 1 and 19.\n");
        return 1;
    }
    
    printf("Solutions (column numbers) are:\n");
    Nqueens(1, n);
    
    return 0;
}
