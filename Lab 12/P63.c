//reverse
#include<stdio.h>
#include<stdlib.h>
struct node {
    int info;
    struct node *link;
};
struct node *first=NULL;

void insertAtFirst(int x){
    struct node *newNode=(struct node*)malloc(sizeof(struct node));
    newNode->info=x;
    newNode->link=first;
    first=newNode;
    if(first == NULL){
        first=newNode;
    }
    else {
        struct node* save = first;

        while (save != NULL)
        {
            save = save->link;
        }
        
    }
}
void reverse()
{
    struct node *prev = NULL;
    struct node *current = first;
    struct node *next = NULL;
    while (current!=NULL)
    {
        next=current->link;
        current->link=prev;
        prev=current;
        current=next;
    }
    first=prev;

}
void Display() {
    struct node *save = first;
    if (save == NULL) {
        printf("List is empty.\n");
        return;
    }
    while (save != NULL) {
        printf("%d -> ", save->info);
        save = save->link;
    }
    printf("NULL\n");
}
void main()
{ 
    int a,num_first;
    while(1){
        printf("1.InsertAtFirst\n2.Reverse and Display");
        printf("\nEnter your choice:");
        scanf("%d",&a);
        switch (a)
        {
        case 1:
                    
            printf("\nEnter a number:");
            scanf("%d",&num_first);
            insertAtFirst(num_first);
            break;
        
        case 2:
            printf("\nBefore Reverse:");
            Display();
            reverse();
            printf("\nAfter Reverse:");
            Display();
        }
    }
}