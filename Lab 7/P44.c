#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<math.h>

char stack[100];
int top = -1;

void push(char c){
    stack[++top] = c;
}

char pop(){
    return stack[top--];
}

void evalute_prefix(char exp[])
{
    int i;
    for(i = 0; i<strlen(exp); i++)
    {
        if (isdigit(exp[i]))
        {
            push(exp[i]-'0');
        }
        else
        {
            int val1 = pop();
            int val2 = pop();
            switch(exp[i])
            {
                case '+':
                push(val1 + val2);
                break;
                case '-':
                push(val2 - val1);
                break;
                case '*':
                push(val1 * val2);
                break;
                case '/':
                push(val2 / val1);
                break;
                case '^':
                push(pow(val1, val2));
            }
        }
        
    }
}

void main(){
    char exp[100];
    printf("Enter a prefix expression :");
    scanf("%s",exp);
    strrev(exp);
    evalute_prefix(exp);
    printf("Answer : %d",pop());
}
