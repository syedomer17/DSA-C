#include <stdio.h>
#define SIZE 10

// Function prototypes
void push(int);
void pop();
void display();

// Global variables
int stack[SIZE], top = -1;

int main() {
    int value, choice;

    while (1) {
        // Display menu
        printf("\n\n************* STACK MENU *************\n");
        printf("\t1. Push()\n\t2. Pop()\n\t3. Display()\n\t4. Exit");
        printf("\n\nEnter your option from the menu: ");
        
        // Check if input is valid
        if (scanf("%d", &choice) != 1) {
            printf("\nOUTPUT:\t Invalid input! Please enter a number.");
            while (getchar() != '\n'); // Clear input buffer
            continue;
        }

        printf("\n************* Program Output *************\n");

        // Switch case to handle user choices
        switch (choice) {
            case 1:
                printf("\nEnter the value to be inserted: ");
                if (scanf("%d", &value) != 1) {
                    printf("\nOUTPUT:\t Invalid input! Please enter a valid number.");
                    while (getchar() != '\n'); // Clear buffer
                    continue;
                }
                push(value);
                break;
            case 2:
                pop();
                break;
            case 3:
                display();
                break;
            case 4:
                printf("\nExiting program...\n");
                return 0;
            default:
                printf("\nOUTPUT:\t Wrong selection! Try again.");
        }
    }
}

// Function to push an element onto the stack
void push(int value) {
    if (top == SIZE - 1)
        printf("\nOUTPUT:\t Stack is full! Insertion is not possible!");
    else {
        stack[++top] = value;
        printf("\nOUTPUT:\t Insertion successful! Inserted value: %d", value);
    }
}

// Function to pop an element from the stack
void pop() {
    if (top == -1)
        printf("\nOUTPUT:\t Stack is empty! Deletion is not possible!");
    else
        printf("\nOUTPUT:\t Deleted value: %d", stack[top--]);
}

// Function to display the stack elements
void display() {
    if (top == -1)
        printf("\nOUTPUT:\t Stack is empty!");
    else {
        printf("\nStack elements are:\n\n");
        for (int i = top; i >= 0; i--)
            printf("%d\n", stack[i]);
    }
}
