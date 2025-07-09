#include<stdio.h>
void main()
{
    int a,i,delet_index;
    printf("Enter a size of array:");
    scanf("%d",&a);

    int arr[a];
    for(i=0;i<a;i++)
    {
        printf("Enter a elements:");
        scanf("%d",&arr[i]);
    }
     for(i=0;i<a;i++)
    {
        printf("%d",arr[i]);
        
    }
    printf("\nEnter a index for delet_no:");
    scanf("%d",&delet_index);
    for ( i = delet_index; i <=a-1 ; i++)
    {
        arr[i]=arr[i+1];
    }
    a--;
    for ( i = 0; i <a; i++)
    {
        printf("%d",arr[i]);
    }

}