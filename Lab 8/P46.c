// 46. Write a menu driven program to implement following operations on the Queue 
// using an Array 
// • ENQUEUE 
// • DEQUEUE 
// • DISPLAY
#include<stdio.h>
#define n 5
int queue[n];
int front=-1,rear=-1;
void enqueue(int x)
{
    if (rear>=n-1)
    {
        printf("Queue Overflow");
        return;
    }
    else{
        if(front=-1){
            front=0;
        }
        rear++;
        queue[rear]=x;
    }
}
void dequeue()
{
    if (front=-1||front>rear)
    {
        printf("Queue is Empty");
        return;
    }
    else
    {
        front++;
    }
}
void display()
{
     if (front=-1||front>rear)
    {
        printf("Queue is Empty");
        return;
    }
    else
    {
        for (int i = front; i <= rear; i++)
        {
            printf("%d",queue[i]);
        }
        printf("\n");
    }
}
void main()
{
    int choice,num;
    while (1)
    {
        printf("\n1.Enqueue\n2.Dequeue\n3.Display\n");
        printf("Enter your choice:");
        scanf("%d",&choice);
        switch (choice)
        {
        case 1 :
            printf("Enter a number:");
            scanf("%d",&num);
            enqueue(num);
            break;
        case 2:
            dequeue();
            break;
        case 3:
            display();
            break;
        default:
            break;
        }
    }
    
}