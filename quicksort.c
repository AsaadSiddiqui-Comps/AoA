#include<stdio.h>
#include<conio.h>

int partition(int a[], int lb, int ub){
    int down, up, x, temp;
    down=lb;
    up=ub;
    x=a[lb];
    
    while(down<up){
        while((a[down]<=x) && (down<up))
        down++;
        while(a[up]>x)
        up--;
        if(down<up){
            temp=a[down];
            a[down]=a[up];
            a[up]=temp;
        }
    }
    a[lb]=a[up];
    a[up]=x;
    return up;
}

void quicksort(int a[], int lb, int ub){
    if(lb<ub){
        int j= partition(a,lb,ub);
        quicksort(a, lb, j-1);
        quicksort(a, j+1, ub);
    }
}

void main(){
    int a[10], n, i;
    
    //input
    printf("Enter the size of the array:\n");
    scanf("%d", &n);
    printf("Enter the elements:\n");
    for(i=0; i<n; i++)
    scanf("%d", &a[i]);
    quicksort(a,0,n-1);
    
    //output
    printf("The sorted array is:\n");
    for(i=0; i<n; i++)
    printf("%5d",a[i]);
}