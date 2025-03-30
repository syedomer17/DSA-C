// 2b): Implementation of Queues ADT using linked lists.

#include <stdio.h>
#include <stdlib.h>

// Define the structure for a queue node
struct Node 
{
    int data;
    struct Node *next;
} *front = NULL, *rear = NULL;

// Function prototypes
void insert(int);
void delete();
void display();

int main() 
{
    int choice, value;
    printf("\n:: Queue Implementation using Linked List ::\n");
    
    while (1) 
    {
        printf("\n****** MENU ******\n");
        printf("1. Insert\n2. Delete\n3. Display\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice)  
        {
            case 1:
                printf("Enter the value to insert: ");
                scanf("%d", &value);
                insert(value);
                break;
            case 2:
                delete();
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



// Function to insert an element into the queue
void insert(int value) 
{
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) 
    {
        printf("\nHeap Overflow! Memory allocation failed.\n");
        return;
    }
    newNode->data = value;
    newNode->next = NULL;

    if (front == NULL) 
    {
        front = rear = newNode;
    } 
    else 
    {
        rear->next = newNode;
        rear = newNode;
    }
    printf("\nInsertion successful!\n");
}

// Function to delete an element from the queue
void delete() 
{
    if (front == NULL) 
    {
        printf("\nQueue is Empty!!!\n");
    } 
    else 
     {
        struct Node *temp = front;
        printf("\nDeleted element: %d\n", temp->data);
        front = front->next;
        free(temp);
        
        // If the queue becomes empty, reset rear to NULL
        if (front == NULL) {
            rear = NULL;
        }
    }
}

// Function to display the queue elements
void display() 
{
    if (front == NULL) 
    {
        printf("\nQueue is Empty!!!\n");
    } 
   else 
   {
        struct Node *temp = front;
        printf("\nQueue elements: \n");
        while (temp != NULL) 
        {
            printf("%d ---> ", temp->data);
            temp = temp->next;
        }
        printf("NULL\n");
    }
}
