// 2a)  Implementation of Stacks ADT using linked lists.
#include <stdio.h>
#include <stdlib.h>

// Define the structure for a stack node
struct Node 
{
    int data;
    struct Node *next;
} *top = NULL;

// Function prototypes
void push(int);
void pop();
void display();

int main() 
{
    int choice, value;
    printf("\n:: Stack using Linked List ::\n");
    
    while (1) 
     {
        printf("\n****** MENU ******\n");
        printf("1. Push\n2. Pop\n3. Display\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) 
       {
            case 1:
                printf("Enter the value to be inserted: ");
                scanf("%d", &value);
                push(value);
                break;
            case 2:
                pop();
                break;
            case 3:
                display();
                break;
            case 4:
                exit(0);
            default:
                printf("\nWrong selection!!! Please try again!!!\n");
        }
    }
    return 0;
}

// Function to push an element onto the stack
void push(int value) 
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    if (newNode == NULL) 
    {
        printf("\nHeap Overflow! Memory allocation failed.\n");
        return;
    }
    newNode->data = value;
    newNode->next = top;
    top = newNode;
    printf("\nInsertion successful!\n");
}

// Function to pop an element from the stack
void pop() 
{
    if (top == NULL) 
    {
        printf("\nStack is Empty!!!\n");
    } 
    else 
     {
        struct Node *temp = top;
        printf("\nDeleted element: %d\n", temp->data);
        top = temp->next;
        free(temp);
    }
}

// Function to display the stack
void display() 
{
    if (top == NULL) 
    {
        printf("\nStack is Empty!!!\n");
    } 
   else 
    {
        struct Node *temp = top;
        printf("\nStack elements: \n");
        while (temp != NULL) 
        {
            printf("%d ---> ", temp->data);
            temp = temp->next;
        }
        printf("NULL\n");
    }
}
