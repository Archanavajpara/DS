#include<stdio.h>
int top=-1;
int stack[20];
void push(int value)
{
    if(top>=20)
    {
        printf("stack overflow");
    }
    else
    {
        top++;
        stack[top]=value;
    }
}
void pop()
{
    if (top==-1)
    {
        printf("Stack underflow");
    }
    else
    {
        top--;
    }
}
void peep(int i)
{
    if (top-i+1<0)
    {
        printf("Stack underflow");
    }
    else
    {
        printf("value:%d",stack[i]);
    }
}
void change(int i)
{
    int value;
    if (top-i+1<0)
    {
        printf("Stack underflow");
    }
    else
    {
        printf("Enter a value:");
        scanf("%d",value);
        stack[i]=value;
    }
}
void display()
{ 
	int i;
    for(i = 0; i <= top; i++)
    {
        printf("%d,",stack[i]);
    }
}
void main()
{
    int choice,value,index;
    while (1)
    {
       printf("\n1.push\n2.pop\n3.peep\n4.change\n5.display\n"); 
       printf("Enter your choice:");
       scanf("%d",&choice);
       switch (choice)
       {
       case 1:
        printf("Enter the value:");
        scanf("%d",&value);
        push(value);
        break;
        
       case 2:
        pop();
        break;
        
       case 3:
        printf("Enter index:");
        scanf("%d",index); 
        peep(index);
        break;
        
       case 4:
        printf("Enter the index:");
        scanf("%d",&index);
        change(index);
        break;
        
       case 5:
        display();
        break;
        
       default:
        break;
       }
    }
    
}
