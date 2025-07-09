#include<stdio.h>
#include<stdlib.h>
struct node
{
    int info;
    struct node * link;
};
struct node *first=NULL;
int insertAtFirst(int x)
{
    struct node*newnode=(struct node*)malloc(sizeof(struct node));
    newnode->info=x;
    newnode->link=first;
    first=newnode;
    return 0;
}
void even_odd()
{
    struct node *even=NULL;
    struct node *odd=NULL;
    struct node *save=first;
    if (first==NULL)
    {
        printf("Linked list\n");
    }
    while (save != NULL) {
        struct node *newnode = (struct node *)malloc(sizeof(struct node));
        newnode->info = save->info;
        if (save->info % 2 == 0) {
            newnode->link = even;
            even = newnode;
        } else {
            newnode->link = odd;
            odd = newnode;
        }
        save = save->link;
    }

    printf("Even elements:\n");
    struct node*eventemp=even;
    if(even==NULL)
    {
        printf("Empty linked list\n");
        return;
    }
    while (eventemp!=NULL)
    {
        printf("%d->",eventemp->info);
        eventemp=eventemp->link;
    }
    printf("null\n");    


    printf("odd elements:\n");
    struct node*oddtemp=odd;
    if(odd==NULL)
    {
        printf("Empty linked list\n");
        return;
    }
    while (oddtemp!=NULL)
    {
        printf("%d->",oddtemp->info);
        oddtemp=oddtemp->link;
    }
    printf("null\n");  
    
}
void display()
{
    struct node*save=first;
    if(first==NULL)
    {
        printf("Empty linked list\n");
        return;
    }
    while (save!=NULL)
    {
        printf("%d->",save->info);
        save=save->link;
    }
    printf("null\n");    
}
void main()
{
    int choice,a;
    while (1)
    {
       printf("\n1.InsertAtFirst\n2.Even_Odd with Display\n3.Display of insertAtFirst\n");
       printf("Enter your choice:");
       scanf("%d",&choice);
       switch (choice)
       {
       case 1:
        printf("Enter a Element:");
        scanf("%d",&a);
        insertAtFirst(a);
        break;
       case 2:
        even_odd();
        break;
       case 3:
        display();
        break;
       default:
        break;
       }
    }
    
}