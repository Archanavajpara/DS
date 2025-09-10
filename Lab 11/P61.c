//queue
#include<stdio.h>
#include<stdlib.h>

struct node{
    int info;
    struct node *link;
};
struct node *first=NULL;
void push(int x)
{
    struct node * newNode=(struct node*)malloc(sizeof(struct node));
    newNode->info=x;
    newNode->link=first;
    first=newNode;
    if (first==NULL)
    {
        printf("List is empty");
        first=newNode;


    }
}
void pop() {
    
    if (first == NULL) {
        printf("List is empty.\n");
        return;
    }
    if (first->link == NULL) {
        free(first);
        first = NULL;
        return;
    }
    struct node *prev = NULL;
    struct node *temp = first;

    while (temp->link != NULL) {
        prev = temp;
        temp = temp->link;
    }
    free(temp);
    prev->link = NULL;
}

void display() {
    struct node *save = first;
    if (save == NULL) {
        printf("Queue is empty.\n");
        return;
    }
    printf("Queue elements: ");
    while (save != NULL) {
        printf("%d -> ", save->info);
        save = save->link;
    }
    printf("NULL\n");
}
void main()
{
    int a,num_first;
   
    while (1)
    {
        printf("1.push\n2.pop\n3.display");
        printf("\nEnter your choice:");
        scanf("%d",&a);
       switch (a)
       {
        case 1:
        printf("Enter the element to be inserted: ");
        scanf("%d",&num_first);
        push(num_first);
        break;

        case 2:
        pop();
        break;

        case 3:
        display();
        
        default:
        break;
       }
        
    }
    
}