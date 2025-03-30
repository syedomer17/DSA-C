#include <stdio.h>
#define N 5  // Define maximum queue size

int main() {
    int queue[N], ch = 1, front = 0, rear = 0, i;

    do {
        printf("\n1. Enqueue\n2. Dequeue\n3. Display\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &ch);

        switch (ch) {
            case 1: // Enqueue operation
                if (rear == N) {
                    printf("Queue is full\n");
                } else {
                    printf("Enter Element: ");
                    scanf("%d", &queue[rear++]);
                    printf("Element inserted successfully\n");
                }
                break;

            case 2: // Dequeue operation
                if (front == rear) {
                    printf("Queue is empty\n");
                } else {
                    printf("%d is deleted\n", queue[front++]);
                }
                break;

            case 3: // Display queue elements
                printf("Queue elements are: ");
                if (front == rear) {
                    printf("Queue is empty\n");
                } else {
                    for (i = front; i < rear; i++) {
                        printf("%d | ", queue[i]);
                    }
                    printf("\n");
                }
                break;

            case 4: // Exit case
                printf("Exiting program...\n");
                break;

            default:
                printf("Enter a valid choice\n");
        }
    } while (ch != 4); // Loop until user chooses Exit

    return 0;
}
