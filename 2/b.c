#include <stdio.h>
#include <stdlib.h>

// Node structure
struct Node {
    int data;
    struct Node* next;
};

struct Node* head = NULL;

// Insert at middle
void insertAtMiddle(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;

    // If list is empty or has only one node
    if (head == NULL || head->next == NULL) {
        newNode->next = head;
        head = newNode;
        printf("Inserted %d at middle.\n", value);
        return;
    }

    int count = 0;
    struct Node* temp = head;
    while (temp != NULL) {
        count++;
        temp = temp->next;
    }

    int mid = count / 2;
    temp = head;

    for (int i = 1; i < mid; i++) {
        temp = temp->next;
    }

    newNode->next = temp->next;
    temp->next = newNode;

    printf("Inserted %d at middle.\n", value);
}

// Display list
void display() {
    struct Node* temp = head;

    if (temp == NULL) {
        printf("List is empty.\n");
        return;
    }

    printf("List: ");
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// Main with switch-case menu
int main() {
    int choice, value;

    while (1) {
        printf("\n*** MENU ***\n");
        printf("1. Insert at Middle\n");
        printf("2. Display List\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to insert at middle: ");
                scanf("%d", &value);
                insertAtMiddle(value);
                break;
            case 2:
                display();
                break;
            case 3:
                printf("Exiting program.\n");
                exit(0);
            default:
                printf("Invalid choice. Try again.\n");
        }
    }

    return 0;
}
