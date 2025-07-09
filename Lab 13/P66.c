#include<stdio.h>
#include<stdlib.h>
struct node{
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
void sort_list()
{
    struct node * save=first;
    while(save!=NULL)
    {
        struct node * next=save->link;
        while (next!=NULL)
        {
            if(save->info > next->info)
            {
                int temp=save->info;
                save->info=next->info;
                next->info=temp;
            }
            else
            {
                next=next->link;
            } 
        }
        save=save->link;
    }
}
void display()
{
    struct node * save = first;
    if(first==NULL)
    {
        printf("List is empty\n");
        return;
    }
    else
    {
        while (save!=NULL)
        {
            printf("%d->",save->info);
            save=save->link;
        }
        printf("null");
    }
}
void main()
{
    int choice,num;
    while (1)
    {
        printf("\n1.InserAtFirst\n2.sort\n3.Display\n");
        printf("Enter your choice:");
        scanf("%d",&choice);
        switch (choice)
        {
        case 1:
            printf("Enter the element to be inserted:");
            scanf("%d",&num);
            InsertAtFirst(num);
            break;
        case 2:
            sort_list();
            break;
        case 3:
            display();    
        default:
            break;
        }
    }
    
}