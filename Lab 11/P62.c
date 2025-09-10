//Duplicate
#include <stdio.h>
#include <stdlib.h>

struct node {
    int info;
    struct node *link;
};

struct node *first = NULL;

void insertAtFirst(int x) {
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    newNode->info = x;
    newNode->link = first;
    first = newNode;
}

void removeDuplicates() {
    struct node *save = first;
    while (save != NULL && save->link != NULL) {
        struct node *temp = save;
        while (temp->link != NULL) {
            if (save->info == temp->link->info) {
                struct node *next = temp->link;
                temp->link = temp->link->link;
                free(next);
            } else {
                temp = temp->link;
            }    
        }
        save = save->link;
    }
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

void main() {
    int a, num_first;
    while (1) {
        printf("1.InsertAtFirst\n2.Remove Duplicate\n3.Display");
        printf("\nEnter your choice:");
        scanf("%d",&a);
        switch (a) {
            case 1:
                printf("Enter a number: ");
                scanf("%d", &num_first);
                insertAtFirst(num_first);
                break;

            case 2:
                removeDuplicates();
                printf("Duplicates Removed.\n");
                break;

            case 3:
                Display();
                break;

            default:
                printf("Invalid choice.\n");
        }
    }
}
