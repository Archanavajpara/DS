#include<stdio.h>
void main()
{
    int a,i,x,n,j,k;
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
    for(i=0;i<a;i++)
    {
        for(j=i+1;j<a;j++)
        {
            if(arr[i]==arr[j])
            {
                for(k=j;i<=a-1;k++)
                {
                    arr[i]=arr[i+1];
                }
                a--;
            }
        }
    }
    for( j=0; j<a+1; j++)
    {
        printf("%d \n",arr[j]);
    }
}