//largest element using pointer
#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, i;
    int *ptr;
    int max=0;

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    
    ptr = (int *)malloc(n * sizeof(int));
    if (ptr == NULL) {
        printf("Memory not allocated.\n");
        }

        printf("Enter %d numbers:\n", n);
     for (i = 0; i < n; i++) 
    {
        scanf("%d", ptr + i);
    }
     max = *ptr;

    for (i = 1; i < n; i++) {
        if (*(ptr + i) > max) {
            max = *(ptr + i);
        }
    }

    printf("The largest number is: %d\n", max);

   
    free(ptr);

    return 0;
}