#include<stdio.h>
int main()
{
	int i,n,max,min,max1=0,min1=0;
	printf("Enter a size of array:");
	scanf("%d",&n);
	int a[n];
	
	for(i=0;i<n;i++)
	{
		printf("Enter elements:");
		scanf("%d",&a[i]);
	}
	
	max=a[0];
	for(i=0;i<n;i++)
	{
		if(max<a[i])
		{
		  max=a[i];	
		  max1=i;
		}
	}
	printf("max=%d",max);
	printf("\nmax_index=%d",max1);
	
	min=a[0];
	for(i=0;i<n;i++)
	{
		if(min>a[i])
		{
		  min=a[i];
		  min1=i;	
		
		}
	}
	printf("\nmin=%d",min);
	printf("\nmin_index=%d",min1);
}

