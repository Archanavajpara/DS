//print array element using pointer
#include<stdio.h>
#include<stdlib.h>

int main()
{
    int n,i;
    printf("Enter the number of elements in the array: ");
    scanf("%d",&n);
    int arr[n];
    int *ptr=arr;

    printf(" enter elements:%d\n", n);
    for(i=0;i<n;i++)
    {
        printf("Element %d: ", i + 1);
        scanf("%d", ptr + i);
    }
       printf("\nArray elements are:\n");
       for (i = 0; i < n; i++) {
       printf("Element %d: %d\n", i + 1, *(ptr + i)); 
    }
}