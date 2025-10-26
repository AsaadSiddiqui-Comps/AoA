#include <stdio.h>

void sort(float w[], float p[], int n) {
    int i, j;
    float ratio[n], temp;
    for (i = 0; i < n; i++) {
        ratio[i] = p[i] / w[i];
    }
    for (i = 0; i < n - 1; i++) {
        for (j = i + 1; j < n; j++) {
            if (ratio[i] < ratio[j]) {
                temp = ratio[i];
                ratio[i] = ratio[j];
                ratio[j] = temp;
                temp = w[i];
                w[i] = w[j];
                w[j] = temp;
                temp = p[i];
                p[i] = p[j];
                p[j] = temp;
            }
        }
    }
}

float knapsack(float w[], float p[], float M, int n) {
    float x[10];
    float max = 0;
    int cp, i;

    for (i = 0; i < n; i++)
        x[i] = 0;

    cp = M;

    sort(w, p, n);

    i = 0;
    while (i < n && w[i] <= cp) {
        x[i] = 1;
        cp = cp - w[i];
        i++;
    }

    if (i < n)
        x[i] = cp / w[i];

    for (i = 0; i < n; i++)
        max = max + (x[i] * p[i]);

    return max;
}

int main() {
    int n, i;
    float w[10], p[10], M;

    printf("Enter number of items: ");
    scanf("%d", &n);

    printf("Enter weights of items: ");
    for (i = 0; i < n; i++)
        scanf("%f", &w[i]);

    printf("Enter profits of items: ");
    for (i = 0; i < n; i++)
        scanf("%f", &p[i]);

    printf("Enter capacity of knapsack: ");
    scanf("%f", &M);

    float maxProfit = knapsack(w, p, M, n);
    printf("Maximum profit: %.2f\n", maxProfit);

    return 0;
}
