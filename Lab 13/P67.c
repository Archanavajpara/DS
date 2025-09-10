//gcd
#include<stdio.h>
#include<stdlib.h>
struct node
{
    int info;
    struct node * link;
};

struct node * first=NULL;

void InsertAtFirst(int x)
{
    struct node * newNode=(struct node*)malloc(sizeof(struct node));
    newNode->info=x;
    newNode->link=first;
    first=newNode;
}
int gcd(int a,int b)
{
    int min;
    if (a>=b)
    {
        min=b;
    }
    else
    {
        min=a;
    }
    for (int  i = min; i>=1; i--)
    {
        if (a%i==0 && b%i==0)
        {
            min=i;
            break;
        } 
    }
    return min;
}
void display()
{
    if(first==NULL)
    {
        printf("Linked list is Empty");
        return;
    }
    struct node * save = first;
    while (save != NULL)
    {
        printf("%d->",save->info);
        save=save->link;
    }
    printf("null");
}
void update()
{
    int num;

   
    if(first==NULL)
    {
        printf("Linked list is Empty");
        return;
    }
    struct node * current=first;
    struct node * next=current->link;

    while(next!=NULL){
        struct node * newNode=(struct node*)malloc(sizeof(struct node));
        newNode->info=gcd(current->info,next->info);
        current->link=newNode;
        newNode->link=next;

        current=newNode->link;
        next=next->link;
    }
}
void main()
{
    int choice,num;
    while(1)
    {
     printf("\n1.InsertAtFirst\n2.Update GCD nodes\n3.Display");
     printf("\nEnter your choice:");
     scanf("%d",&choice);

     switch (choice)
     {
     case 1:
        printf("Enter a number:");
        scanf("%d",&num);
        InsertAtFirst(num);
        break;
     case 2:
        update();
        break;
    case 3: 
        display();
     default:
        break;
     }
    }

}