#include<stdio.h>
int main()
{
	char a;
	printf("Enter a character:");
	scanf("%c",&a);
	if(a>='A' && a<='Z')
	{
		a=a+32;
	}
	if(a=='a'||a=='e'||a=='i'||a=='o'||a=='u')
	{
		printf("is a vowel");
	}
	else
	{
		printf("is a consonant");
	}
	return 0;
}
