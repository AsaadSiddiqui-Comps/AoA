#include <stdio.h>

void binsearch(int a[], int x, int low, int high) {
    if (low > high) {
        printf("Element not found\n");
        return; 
    }

    int mid = (low + high) / 2;

    if (x == a[mid]) {
        printf("Element found at index %d\n", mid);
    }
    else if (x < a[mid]) {
        binsearch(a, x, low, mid - 1); 
    }
    else {
        binsearch(a, x, mid + 1, high); 
    }
}

int main() {
    int n, x;
    printf("Enter number of elements: ");
    scanf("%d", &n);

    int a[n];
    printf("Enter %d sorted elements: ", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    printf("Enter element to search: ");
    scanf("%d", &x);

    binsearch(a, x, 0, n - 1);

    return 0;
}