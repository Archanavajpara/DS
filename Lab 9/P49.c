#include <stdio.h>
#include <stdlib.h>

int *intPtr = NULL;
char *charPtr = NULL;
float *floatPtr = NULL;

void allocating_memory(int a, char b, float c) {
  
    intPtr = (int *)malloc(sizeof(int));
    charPtr = (char *)malloc(sizeof(char));
    floatPtr = (float *)malloc(sizeof(float));

    if (intPtr == NULL || charPtr == NULL || floatPtr == NULL) {
        printf("Memory allocation failed.\n");
        return;
    }

    *intPtr = a;
    *charPtr = b;
    *floatPtr = c;
}

void assigning_value() {
    int a;
    char b;
    float c;
    printf("Enter an integer value: ");
    scanf("%d", &a);
    printf("Enter a character: ");
    scanf(" %c", &b);
    printf("Enter a float value: ");
    scanf("%f", &c);

    allocating_memory(a, b, c);
}

void free_memory() {
    if (intPtr != NULL) {
        free(intPtr);
        intPtr = NULL;
    }
    if (charPtr != NULL) {
        free(charPtr);
        charPtr = NULL;
    }
    if (floatPtr != NULL) {
        free(floatPtr);
        floatPtr = NULL;
    }

    printf("Memory successfully freed.\n");
}

void Display() {
    if (intPtr == NULL || charPtr == NULL || floatPtr == NULL) {
        printf("No memory allocated yet.\n");
        return;
    }

    printf("Integer value: %d\n", *intPtr);
    printf("Character value: %c\n", *charPtr);
    printf("Float value: %.2f\n", *floatPtr);
}

int main() {
    int choice;
    while (1) {
        printf("\n1. Assign values\n2. Display\n3. Free memory\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                assigning_value();
                break;
            case 2:
                Display();
                break;
            case 3:
                free_memory();
                break;
            default:
                printf("Invalid choice. Try again.\n");
        }
    }
}
