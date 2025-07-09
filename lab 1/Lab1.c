#include<stdio.h>
#define PI 3.14
int main (){
	int radius;
	float area;
	printf("Enter a radius:");
	scanf("%d",&radius);
	area=radius*radius*PI;
	printf("Area:%f",area);
	return 0;
}
