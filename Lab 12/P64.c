//copy linked list
#include <stdio.h>
#include <stdlib.h>

struct node
{
    int info;
    struct node *link;
};

struct node *first1 = NULL;
struct node *first2 = NULL;

void InsertAtFirst(int x)
{
    struct node *newNode = (struct node *)malloc(sizeof(struct node));

    newNode->info = x;

    if (first1 == NULL)
    {
        newNode->link = first1;
        first1 = newNode;

    } // if
    else
    {
        struct node *save = first1;
        while (save->link != NULL)
        {
            save = save->link;
        } // while

        save->link = newNode;
        newNode->link = NULL;

    } // else
} // InsertAtFirst

void Display()
{
    if (first1 != NULL)
    {
        struct node *save1 = first1;
        int i = 1;
        printf("\nfirst link list :\n");
        while (save1 != NULL)
        {
            printf("%d->",save1->info);
            save1 = save1->link;
            i++;
        } // while
        printf("null");
        printf("Linked is null");
    }
    else
    {
        printf("\nlink list 1 is empty.\n");
    }

    if (first2 != NULL)
    {
        struct node *save2 = first2;
        int i = 1;
        printf("\nsecond link list :\n");
        while (save2 != NULL)
        {
            printf("%d->",save2->info);
            save2 = save2->link;
            i++;
        } // while
        printf("null");
    }
    else
    {
        printf("\nlink list 2 is empty.\n");
    }
} // display all nodes

void CopyList()
{
    if (first1 == NULL)
    {
        printf("Nodes doesn't exist .\n");
    } // if
    else
    {
        struct node *save = first1;
        while (save != NULL)
        {
            struct node *newNode = (struct node *)malloc(sizeof(struct node));
            newNode->info = save->info;
            newNode->link = NULL;
            if (first2 == NULL)
            {
                first2 = newNode;
            }
            else
            {
                struct node *temp = first2;
                while (temp->link != NULL)
                {
                    temp = temp->link;
                }
                temp->link = newNode;
            }//else
            save = save -> link ;
        } // while
    } // else
}

void main()
{
    while (1)
    {
        int x;
        printf("\n1.enter new node\n2.copylist\n3.display\n");
        int choice;
        scanf("Enter a Element:%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Enter Elements :");
            scanf("%d", &x);
            InsertAtFirst(x);
            break;
        case 2:
            CopyList();
            break;
        case 3:
            Display();
            break;
        default:
            break;
        }
    }
}