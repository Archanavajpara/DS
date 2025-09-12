//write a program of hashmap by using struct
#include<stdio.h>
#include<stdlib.h>
struct pair{
    int key;
    int value;
};
#define n 10
struct pair hash_map[n];
void init_hash_map()
{
    for(int i=0;i<n;i++)
    {
        strcpy(hash_map[i].key,-1);
        hash_map[i].value=-1;
    }
}

