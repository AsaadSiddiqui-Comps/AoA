#include<stdio.h>
#include<conio.h>

void main(){
    int arr[10], n, i, j, x;

    //Input
    printf("Enter the size of an array:");
    scanf("%d", &n);
    printf("Enter the elements of the array:\n");
    for(i=0; i<n; i++)
        scanf("%d", &arr[i]);
    
        

        //Sorting
        for(j=1; j<=n-1; j++){
            x=arr[j];
            i=j-1;
            while((i>=0) && (arr[i]>x)){
                arr[i+1]=arr[i];
                i--;
            }
             arr[i+1]=x;
        }

    //Output
    printf("The sorted array is:");
    for(i=0; i<n; i++)
        printf("%5d", arr[i]);
}

