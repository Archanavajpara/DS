// 48. Write a menu driven program to implement following operations on the 
// Doubled Ended Queue using an Array 
// • Insert at front end, Insert at rear end 
// • Delete from front end, Delete from rear end 
// • Display all elements of the queue
#include<stdio.h>
#define n 20
int Q[n];
int rear=-1, front=-1;

void insert_Rear(int x)
{
    if(rear>= n-1)
    {
        printf("overflow");
        return;
    }
    rear++;
    Q[rear] = x;
    if(front ==-1)
    {
        front++;
    }
}

void insert_Front(int x)
{
    if(front==0)
    {
        printf("overflow");
        return;
    }
    if(front==-1)
    {
        front= rear= 0;
    }
    else{
        front = front-1;
    }
    Q[front]=x;
}

int delete_Rear()
{
    if(rear==-1)
    {
        printf("underflow");
        return -1;
    }
    int y = Q[rear];
    if(rear==front)
    {
        front=rear=-1;
    }
    else{
        rear--;
    }
    return y;
}

int delete_Front()
{
    if(front ==-1)
    {
        printf("underflow");
        return-1;
    }
    int y = Q[front];
    if(front== rear)
    {
        front = -1;
        rear = -1;
    }
    else{
        front++;
    }
    return y;
}

void display()
{
    if(front == -1)
    {
        printf("empty");
        return;
    }
    for(int i= front; i<=rear; i++)
    {
        printf("%d-->",Q[i]);
    }
}

void main()
{
    while(1)
    {
        int choice,k,j ;
        printf("1:insert_Rear\n2:insert_Front\n3:delete_Rear\n4:delete_Front\n5:exit\nENTER YOUR CHOICE:");
        scanf("%d",&choice);

        switch (choice)
        {
        case 1:
            printf("Enter a element:");
            scanf("%d",&k);
            insert_Rear(k);
            display();
            break;
        case 2:
            
            printf("Enter a element:");
            scanf("%d",&j);
            insert_Front(j);
            display();
            break;
        
         case 3:
            delete_Rear();
            display();
            break;
        
         case 4:
            delete_Front();
            display();
            break;

        default:
            break;
        }
    }
}