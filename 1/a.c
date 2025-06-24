#include <stdio.h>
#include <stdlib.h>

#define SIZE 10

int stack[SIZE];
int top = -1;
int i;

// Function prototypes
void push(int);
void pop();
void Display();

int main() {
    int value, choice;

    while (1) {
        printf("\n\n*** MENU ***");
        printf("\n1. Push\n2. Pop\n3. Display\n4. Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the value to be inserted: ");
                scanf("%d", &value);
                push(value);
                break;
            case 2:
                pop();
                break;
            case 3:
                Display();
                break;
            case 4:
                exit(0);
            default:
                printf("Wrong selection. Try again.");
        }
    }

    return 0;
}

// Push function
void push(int value) {
    if (top == SIZE - 1) {
        printf("Stack is full (Overflow)!");
    } else {
        top++;
        stack[top] = value;
        printf("Value %d inserted successfully.", value);
    }
}

// Pop function
void pop() {
    if (top == -1) {
        printf("Stack is empty (Underflow).");
    } else {
        printf("Deleted value: %d", stack[top]);
        top--;
    }
}

// Display function
void Display() {
    if (top == -1) {
        printf("Stack is empty!");
    } else {
        printf("Stack elements: ");
        for ( i = top; i >= 0; i--) {
            printf("%d ", stack[i]);
        }
    }
}
