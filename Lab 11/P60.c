//stack
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
        printf("Stack is empty.\n");
        return;
    }
    struct node *temp = first;
    first = first->link;
    printf("Popped element: %d\n", temp->info);
    free(temp);
}

void display() {
    struct node *save = first;
    if (save == NULL) {
        printf("Stack is empty.\n");
        return;
    }
    printf("Stack elements: ");
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