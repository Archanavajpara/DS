//Sum of elements in the array using pointer
#include<stdio.h>
#include<stdlib.h>

int main()
{
    int n,i,sum=0;
    printf("Enter the number of elements in the array: ");
    scanf("%d",&n);
    int arr[n];
    int *ptr=arr;

    ptr = (int *)malloc(n * sizeof(int));
    if (ptr == NULL) {
        printf("Memory not allocated.\n");
    }

    printf("Enter %d numbers:\n", n);
    for (i = 0; i < n; i++)
    {
        scanf("%d", ptr + i);
    }

    printf(" enter elements:%d\n", n);
     for (i = 0; i < n; i++)
    {
        sum += *(ptr + i);
    }
     printf("Sum of elements in the array is: %d\n", sum);
}