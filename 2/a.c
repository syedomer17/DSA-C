#include <stdio.h>
#include <stdlib.h>
#define SIZE 5

int queue[SIZE];
int front = -1, rear = -1;

// Function to insert an element into the queue
void enqueue(int value) {
    if (rear == SIZE - 1) {
        printf("Queue is full (Overflow).\n");
    } else {
        if (front == -1) front = 0; // Set front on first insertion
        rear++;
        queue[rear] = value;
        printf("Inserted %d into queue.\n", value);
    }
}

// Function to remove an element from the queue
void dequeue() {
    if (front == -1 || front > rear) {
        printf("Queue is empty (Underflow).\n");
    } else {
        printf("Deleted %d from queue.\n", queue[front]);
        front++;
    }
}

// Function to display the queue
void display() {
    if (front == -1 || front > rear) {
        printf("Queue is empty.\n");
    } else {
        printf("Queue elements: ");
        for (int i = front; i <= rear; i++) {
            printf("%d ", queue[i]);
        }
        printf("\n");
    }
}

// Main function
int main() {
    int choice, value;

    while (1) {
        printf("\n*** QUEUE MENU ***\n");
        printf("1. Enqueue\n2. Dequeue\n3. Display\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to enqueue: ");
                scanf("%d", &value);
                enqueue(value);
                break;
            case 2:
                dequeue();
                break;
            case 3:
                display();
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice. Try again.\n");
        }
    }

    return 0;
}
