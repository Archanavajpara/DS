#include<stdio.h>
#include<stdlib.h>
struct node
{
    int info;
    struct node * link;
};
struct node* First=NULL;

void display(int x)
{
    struct node* newNode=(struct node*)malloc(sizeof(struct node));
    newNode->info=x;
    newNode->link=First;
    First=newNode;
    printf("NewNode=%d",newNode->info);
}
    
void main()
{
    int x;
    printf("Enter a Number:");
    scanf("%d",&x);
    display(x);
}
