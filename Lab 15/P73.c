//delete Alternate node from doubly linked linear list
#include <stdio.h>
#include <stdlib.h>

struct node {
    int info;
    struct node *rptr;
    struct node *lptr;
};

struct node *head = NULL;

void head_node() {
    head = (struct node *)malloc(sizeof(struct node));
    head->info = 0;     
    head->rptr = NULL;
    head->lptr = NULL;
}

void insertAtFirst(int x) {
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    newNode->info = x;
    newNode->rptr = head->rptr;
    newNode->lptr = head;

    if (head->rptr != NULL)
        head->rptr->lptr = newNode;

    head->rptr = newNode;
}

void deleteAlternate() {
    struct node *current = head->rptr;
    int index = 1;

    while (current != NULL && current->rptr != NULL) {
        struct node *toDelete = current->rptr;
        current->rptr = toDelete->rptr;

        if (toDelete->rptr != NULL)
            toDelete->rptr->lptr = current;

        free(toDelete);
        current = current->rptr;  
    }
}
void Display() {
    struct node *temp = head->rptr;

    if (temp == NULL) {
        printf("List is empty.\n");
        return;
    }

    while (temp != NULL) {
        printf("%d <-> ", temp->info);
        temp = temp->rptr;
    }
    printf("NULL\n");
}
void main() {
    int a, num, pos;
    head_node();  

    while (1) {
        printf("\n1. Insert At First\n2.Display\n3.Display");
        printf("\nEnter your choice: ");
        scanf("%d", &a);

        switch (a) {
            case 1:
                printf("Enter number: ");
                scanf("%d", &num);
                insertAtFirst(num);
                break;
            case 2:
                deleteAlternate();
                break;
            case 3:
                display();    
            default:
            printf("Invalid input");
                
        }
    }
}