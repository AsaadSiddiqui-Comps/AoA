#include<stdio.h>
#include<conio.h>

void main()
{
    int arr[10], n, i, j, pos, largest;

    //Input
    printf("Enter the size of the array:");
    scanf("%d", &n);
    printf("Enter the elements of the array:\n");
    for(i=0; i<n; i++)
    scanf("%d",&arr[i]);

    //sorting
    for(j=n-1; j>=1; j--){
        largest=arr[0];
        pos=0;

        for(i=1; i<=j; i++)
        if(arr[i]>largest){
            largest=arr[i];
            pos=i;
        }

        arr[pos]=arr[j];
        arr[j]=largest;

    }
    //output
    printf("The sorted array is:");
    for(i=0; i<n; i++)
    printf("%5d", arr[i]);
}