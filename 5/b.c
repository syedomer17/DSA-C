#include <stdio.h>
#include <stdlib.h>

// Define the node structure
struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
};

struct Node* head = NULL;

// Delete from beginning
void deleteFromBeginning() {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    struct Node* temp = head;
    head = head->next;

    if (head != NULL)
        head->prev = NULL;

    printf("Deleted node with value %d from beginning.\n", temp->data);
    free(temp);
}

// Delete from end
void deleteFromEnd() {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    struct Node* temp = head;

    // Only one node
    if (head->next == NULL) {
        printf("Deleted node with value %d from end.\n", temp->data);
        free(temp);
        head = NULL;
        return;
    }

    // Traverse to last node
    while (temp->next != NULL)
        temp = temp->next;

    temp->prev->next = NULL;
    printf("Deleted node with value %d from end.\n", temp->data);
    free(temp);
}

// Display the list
void display() {
    struct Node* temp = head;
    if (temp == NULL) {
        printf("List is empty.\n");
        return;
    }

    printf("List: ");
    while (temp != NULL) {
        printf("%d <-> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// Insert at end (for testing/demo)
void insertAtEnd(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;

    if (head == NULL) {
        newNode->prev = NULL;
        head = newNode;
    } else {
        struct Node* temp = head;
        while (temp->next != NULL)
            temp = temp->next;
        temp->next = newNode;
        newNode->prev = temp;
    }
}

// Main function with menu
int main() {
    int choice, value;

    // Preload some data
    insertAtEnd(10);
    insertAtEnd(20);
    insertAtEnd(30);

    while (1) {
        printf("\n*** MENU ***\n");
        printf("1. Delete from Beginning\n");
        printf("2. Delete from End\n");
        printf("3. Display List\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                deleteFromBeginning();
                break;
            case 2:
                deleteFromEnd();
                break;
            case 3:
                display();
                break;
            case 4:
                printf("Exiting program.\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}
