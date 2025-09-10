#include<stdio.h>
int main()
{
	int i,m,n,sum=0;
	printf("Enter a first number:");
	scanf("%d",&m);
	printf("Enter a second number:");
	scanf("%d",&n);
	for(i=m;i<=n;i++)
	{
		sum+=i;	
	}
	printf("Sum=%d",sum);
}
