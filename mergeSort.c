#include <stdio.h>

int a[10];
int temp[10];

void combine(int down, int mid, int up) {
    int i, j, k;
    i = down;
    j = mid + 1;
    k = down;

    while (i <= mid && j <= up) {
        if (a[i] <= a[j]) {
            temp[k] = a[i];
            i++;
        } else {
            temp[k] = a[j];
            j++;
        }
        k++;
    }

    while (i <= mid) {
        temp[k] = a[i];
        i++;
        k++;
    }

    while (j <= up) {
        temp[k] = a[j];
        j++;
        k++;
    }

    for (i = down; i <= up; i++) {
        a[i] = temp[i];
    }
}

void mergeSort(int down, int up) {
    if (down < up) {
        int mid = (down + up) / 2;
        mergeSort(down, mid);
        mergeSort(mid + 1, up);
        combine(down, mid, up);
    }
}

int main() {
    int n, i;

    printf("Enter the size of the array:\n");
    scanf("%d", &n);

    printf("Enter the elements:\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    mergeSort(0, n - 1);

    printf("Sorted array:\n");
    for (i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");

}

