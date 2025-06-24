#include <stdio.h>
#include <stdlib.h>

// Define node structure
struct Node {
    int data;
    struct Node* next;
};

struct Node* head = NULL;

// Create new node
struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

// Insert node at end
void insertNode(int value) {
    struct Node* newNode = createNode(value);
    if (head == NULL) {
        head = newNode;
    } else {
        struct Node* temp = head;
        while (temp->next != NULL)
            temp = temp->next;
        temp->next = newNode;
    }
    printf("Inserted %d into the list.\n", value);
}

// Delete middle node
void deleteMiddle() {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    if (head->next == NULL) {
        printf("Only one node. Deleting: %d\n", head->data);
        free(head);
        head = NULL;
        return;
    }

    // Count nodes
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

    struct Node* toDelete = temp->next;
    temp->next = toDelete->next;
    printf("Deleted middle node: %d\n", toDelete->data);
    free(toDelete);
}

// Display list
void display() {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    struct Node* temp = head;
    printf("List: ");
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// Main
int main() {
    int choice, value;

    while (1) {
        printf("\n*** MENU ***\n");
        printf("1. Insert Node\n");
        printf("2. Delete Middle Node\n");
        printf("3. Display List\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to insert: ");
                scanf("%d", &value);
                insertNode(value);
                break;
            case 2:
                deleteMiddle();
                break;
            case 3:
                display();
                break;
            case 4:
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid choice. Try again.\n");
        }
    }

    return 0;
}
