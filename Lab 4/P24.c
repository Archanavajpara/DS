#include<stdio.h>
void main()
{
    int a,i,insert_no,insert_index;
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
    printf("\nEnter a number for inserting:");
    scanf("%d",&insert_no);
    printf("\nEnter a index for insert_no:");
    scanf("%d",&insert_index);
    for ( i = a; i >=insert_index ; i--)
    {
        arr[i]=arr[i-1];
    }
    arr[insert_index]=insert_no;
    for ( i = 0; i <a+1; i++)
    {
        printf("%d",arr[i]);
    }
    
    



}