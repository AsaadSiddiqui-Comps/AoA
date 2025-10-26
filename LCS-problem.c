#include <stdio.h>
#include <string.h>

int c[20][20];
char d[20][20];  // direction matrix should be char

// Function to print the LCS using backtracking
void display(char d[][20], char x[], int i, int j) {
    if (i == 0 || j == 0)
        return;

    if (d[i][j] == 'd') {
        display(d, x, i - 1, j - 1);
        printf("%c", x[i - 1]);
    } else if (d[i][j] == 'u') {
        display(d, x, i - 1, j);
    } else {
        display(d, x, i, j - 1);
    }
}

// Function to compute LCS
void lcs(char x[], char y[]) {
    int m, n, i, j;
    m = strlen(x);
    n = strlen(y);

    printf("Length of first string: %d\n", m);
    printf("Length of second string: %d\n", n);

    for (i = 0; i <= m; i++)
        c[i][0] = 0;
    for (j = 0; j <= n; j++)
        c[0][j] = 0;

    for (i = 1; i <= m; i++) {
        for (j = 1; j <= n; j++) {
            if (x[i - 1] == y[j - 1]) {
                c[i][j] = c[i - 1][j - 1] + 1;
                d[i][j] = 'd';
            } else if (c[i - 1][j] >= c[i][j - 1]) {
                c[i][j] = c[i - 1][j];
                d[i][j] = 'u';
            } else {
                c[i][j] = c[i][j - 1];
                d[i][j] = 'l';
            }
        }
    }

    printf("Longest Common Subsequence: ");
    display(d, x, m, n);
    printf("\n");
}

int main() {
    char x[20], y[20];

    printf("Enter first string: ");
    fgets(x, sizeof(x), stdin);
    x[strcspn(x, "\n")] = 0;  // remove newline

    printf("Enter second string: ");
    fgets(y, sizeof(y), stdin);
    y[strcspn(y, "\n")] = 0;

    lcs(x, y);

    return 0;
}
