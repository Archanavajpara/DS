#include<stdio.h>
void main()
{
    int n;
    
    printf("ENTER A NUMBER:");
    scanf("%d",&n);
    int a[n+1],x, newno;
    for(int i=0; i<n; i++)
    {
        printf("Enter a element:");
        scanf("%d",& a[i]);
    }

    printf("ENter a new number:");
    scanf("%d",& newno);
    int i;
    for( i=0; i<n && a[i]<newno;i++);

    x = i;
   for( i=n; i>=x; i--)
    {
        a[i]=a[i-1];
    }
    a[x]=newno;
    for(int j=0; j<n+1; j++)
    {
        printf("%d \n",a[j]);
    }
}