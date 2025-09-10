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
void insertAtLast(int x)
{
    struct node *newNode=(struct node*)malloc(sizeof(struct node));
    newNode->info=x;
    newNode->link=NULL;
    if(first == NULL){
        first=newNode;
    }
    else {
        struct node* save = first;

        while (save->link!= NULL)
        {
            
            save = save->link;
        }
        save->link=newNode;
    }
    
}
void deleteAtFirst(){
    if (first == NULL) {
        printf("List is empty.\n");
        return;
    }
    struct node *temp = first;
    first = first->link;
    free(temp);
}

void deleteAtLast() {
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


void deleteAtPosition(int pos) {
    if (first == NULL || pos < 1) {
        printf("Invalid position or list is empty.\n");
        return;
    }
    if (pos == 1) {
        struct node *temp = first;
        first = first->link;
        free(temp);
        return;
    }
    struct node *save = first;
    for (int i = 1; i < pos - 1 && save != NULL; i++) {
        save = save->link;
    }
    
    struct node *temp = save->link;
    save->link = temp->link;
    free(temp);
}

int countNodes() {
    int count = 0;
    struct node *save = first;
    while (save != NULL) {
        count++;
        save = save->link;
    }
    return count;
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
    int a,num_first,num_last,delete_first;
    
    while(1){
        printf("1.InsertAtFirst\n2.InsertAtLast\n3.DeleteAtFirst\n4.DeleteAtLast\n5.DeleteAtPosition\n6.CountNodes\n7. 1Display");
        printf("\nEnter:");
        scanf("%d",&a);
        switch (a)
        {
        case 1:
                    
            printf("\nEnter a number:");
            scanf("%d",&num_first);
            insertAtFirst(num_first);
            break;
        case 2:
            printf("\nEnter a number:");
            scanf("%d",&num_last);
            insertAtLast(num_last);
            break;
        case 3:
            deleteAtFirst();
            break; 
        case 4:
            deleteAtLast();
            break;
        case 5:
            printf("Enter position to delete: ");
            int pos;
            scanf("%d", &pos);
            deleteAtPosition(pos);
            break;
        case 6:
            printf("Number of nodes: %d\n", countNodes());
            break;
        case 7:
            Display();     
        default:
            break;
                
        }
    }

}