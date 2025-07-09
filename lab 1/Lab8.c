#include<stdio.h>
int main()
{
	int n;
	printf("Enter a number:");
	scanf("%d",&n);
	fact(n);
	
}
int fact(int n)
{
	if(n>=1)
	{
		printf("factorial is:%d",n*(n-1));
		fact(n);
	}
	else
	{
		printf("1");
	}
	return 0;
}
