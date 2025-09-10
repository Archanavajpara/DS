#include<stdio.h>
int main()
{
	int i,a;
	printf("Enter a size of array:");
	scanf("%d",&a);
	int b[a];
	for(i=0;i<a;i++)
	{
		printf("Enter elements:");
		scanf("%d",&b[i]);
	}
	
	for(i=0;i<a;i++)
	{
		printf("%d",b[i]);
	}
}
