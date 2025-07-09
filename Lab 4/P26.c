#include<stdio.h>
void main()
{
    int a,i,x,newno,n,j;
    printf("Enter a size of array:");
    scanf("%d",&a);

    int arr[a+1];
    for(i=0;i<a;i++)
    {
        printf("Enter a elements in ascending order:");
        scanf("%d",&arr[i]);
    }
    for(i=0;i<a;i++)
    {
        printf("%d",arr[i]); 
    }
    printf("\nEnter a number:");
    scanf("%d",&newno);
    
    for( i=0; i<a && arr[i]<newno;i++);

    x = i;
   for( i=a; i>=x; i--)
    {
        arr[i]=arr[i-1];
    }
    arr[x]=newno;
    for( j=0; j<a+1; j++)
    {
        printf("%d \n",arr[j]);
    }
}