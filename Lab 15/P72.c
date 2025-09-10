//doubly linked list with head
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

void insertAtLast(int x) {
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    newNode->info = x;
    newNode->rptr = NULL;

    struct node *temp = head;
    while (temp->rptr != NULL)
        temp = temp->rptr;

    temp->rptr = newNode;
    newNode->lptr = temp;
}

void deleteAtPosition(int pos) {
    if (head->rptr == NULL || pos < 1) {
        printf("Invalid position or list is empty.\n");
        return;
    }

    struct node *temp = head->rptr;
    for (int i = 1; i < pos && temp != NULL; i++)
        temp = temp->rptr;

    if (temp == NULL) {
        printf("Position out of bounds.\n");
        return;
    }

    if (temp->lptr != NULL)
        temp->lptr->rptr = temp->rptr;
    if (temp->rptr != NULL)
        temp->rptr->lptr = temp->lptr;

    free(temp);
}

int countNodes() {
    int count = 0;
    struct node *temp = head->rptr;

    while (temp != NULL) {
        count++;
        temp = temp->rptr;
    }

    return count;
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
        printf("\n1. Insert At First\n2. Insert At Last\n3. Delete At Position\n4. Count Nodes\n5. Display");
        printf("\nEnter your choice: ");
        scanf("%d", &a);

        switch (a) {
            case 1:
                printf("Enter number: "); 
                scanf("%d", &num);
                insertAtFirst(num);
                break;
            case 2:
                printf("Enter number: ");
                scanf("%d", &num);
                insertAtLast(num);
                break;
            case 3:
                printf("Enter position: ");
                scanf("%d", &pos);
                deleteAtPosition(pos);
                break;
            case 4:
                printf("Total nodes: %d\n", countNodes());
                break;
            case 5:
                Display();
                break;
            default:
                printf("Invalid choice.\n");
        }
    }
}
