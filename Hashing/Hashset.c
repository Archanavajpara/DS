// implementation of Hash Set, resolcing collisions using Linear Probing
#include <stdio.h>
#define n 10
int hash_table[n];
void init_hash_table()
{
    for (int i = 0; i < n; i++)
    {
        hash_table[i] = -1;
    }
}
int hash_function(int key)
{
    return key % n;
}
void contains(int value)
{
    int index = hash_function(value);
    if (hash_table[index] == value)
    {
        printf("Present\n");
        return;
    }
    else if (hash_table[index] == -1)
    {
        printf("Not Present\n");
        return;
    }
    else
    {
        for (int i = 1; i < n; i++)
        {
            int probe_index = (index + i) % n;
            if (hash_table[probe_index] == value)
            {
                printf("Present\n");
                return;
            }
            else if (hash_table[probe_index] == -1)
            {
                printf("Not Present\n");
                return;
            }
        }
        printf("Not Present\n");
    }
}
void add(int value)
{
    int index = hash_function(value);
    if (hash_table[index] == -1)
    {
        hash_table[index] = value;
        return;
    }
    else if (hash_table[index] == value)
    {
        printf("Already Present\n");
        return;
    }
    else
    {
        for (int i = 1; i < n; i++)
        {
            int probe_index = (index + i) % n;
            if (hash_table[probe_index] == -1)
            {
                hash_table[probe_index] = value;
                return;
            }
            else if (hash_table[probe_index] == value)
            {
                printf("Already Present\n");
                return;
            }
        }
        printf("Hash Table Full\n");
    }
}
void main()
{
    init_hash_table();
    int choice, value;
    while (1)
    {
        printf("1. Add\n2. Contains\n3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Enter value to add: ");
            scanf("%d", &value);
            add(value);
            break;
        case 2:
            printf("Enter value to search: ");
            scanf("%d", &value);
            contains(value);
            break;
        case 3:
            return;
        default:
            printf("Invalid choice\n");
        }
    }
}