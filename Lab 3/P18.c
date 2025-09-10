#include<stdio.h>
int main()
{
	int i,a,sum=0;
	float avg=0;
	printf("Enter a number:");
	scanf("%d",&a);
	for(i=0;i<=a;i++)
	{
		sum+=i;	
	}
	avg=sum/a;
	printf("Sum:%d",sum);
	printf("\nAvg:%f",avg);
}
