// 47. Write a menu driven program to implement following operations on a circular 
// queue using an Array 
// • Insert 
// • Delete 
// • Display all elements of the queue 


#include <stdio.h>
#define n 5

int queue[n];
int front = -1, rear = -1;

void Insert(int x) {
    if ((rear + 1) % n == front) {
        printf("Queue is FULL\n");
        return;
    }

    if (front == -1 && rear == -1) {
        front = rear = 0;
    } else {
        rear = (rear + 1) % n;
    }

    queue[rear] = x;
    printf("%d inserted\n", x);
}

void Delete() {
    if (front == -1 && rear == -1) {
        printf("Queue is EMPTY\n");
        return;
    }

    int deleted = queue[front];

    if (front == rear) {
    
        front = rear = -1;
    } else {
        front = (front + 1) % n;
    }

    printf("Deleted element: %d\n", deleted);
}

void display() {
    if (front == -1 && rear == -1) {
        printf("Queue is EMPTY\n");
        return;
    }

    printf("Queue elements: ");
    int i = front;
    while (1) {
        printf("%d ", queue[i]);
        if (i == rear)
            break;
        i = (i + 1) % n;
    }
    printf("\n");
}

int main() {
    int choice, num;
    while (1) {
        printf("\n1. Insert\n2. Delete\n3. Display\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter a number: ");
                scanf("%d", &num);
                Insert(num);
                break;
            case 2:
                Delete();
                break;
            case 3:
                display();
                break;
            case 4:
                return 0;
            default:
                printf("Invalid choice\n");
        }
    }
}
