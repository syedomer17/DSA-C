#include <stdio.h>
#include <stdlib.h>

// Structure for Circular Linked List node
struct Node {
    int data;
    struct Node *next;
};

// Global pointer to head node
struct Node *head = NULL;

// Function to insert at the beginning
void insertAtBeginning(int value) {
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = value;

    if (head == NULL) {
        newNode->next = newNode; // Circular link
        head = newNode;
    } else {
        struct Node *temp = head;
        while (temp->next != head) {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->next = head;
        head = newNode;
    }
}

// Function to insert at the end
void insertAtEnd(int value) {
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = value;
    
    if (head == NULL) {
        newNode->next = newNode;
        head = newNode;
    } else {
        struct Node *temp = head;
        while (temp->next != head) {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->next = head;
    }
}

// Function to insert at a specific position
void insertAtPosition(int value, int pos) {
    if (pos < 1) {
        printf("Invalid position!\n");
        return;
    }

    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = value;

    if (pos == 1) {
        insertAtBeginning(value);
        return;
    }

    struct Node *temp = head;
    for (int i = 1; temp->next != head && i < pos - 1; i++) {
        temp = temp->next;
    }

    newNode->next = temp->next;
    temp->next = newNode;
}

// Function to delete from the beginning
void deleteFromBeginning() {
    if (head == NULL) {
        printf("List is empty!\n");
        return;
    }

    struct Node *temp = head, *last = head;
    while (last->next != head) {
        last = last->next;
    }

    if (head->next == head) {
        free(head);
        head = NULL;
    } else {
        head = head->next;
        last->next = head;
        free(temp);
    }
}

// Function to delete from the end
void deleteFromEnd() {
    if (head == NULL) {
        printf("List is empty!\n");
        return;
    }

    struct Node *temp = head, *prev = NULL;
    while (temp->next != head) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == head) {
        free(head);
        head = NULL;
    } else {
        prev->next = head;
        free(temp);
    }
}

// Function to delete from a specific position
void deleteFromPosition(int pos) {
    if (head == NULL || pos < 1) {
        printf("Invalid position or empty list!\n");
        return;
    }

    if (pos == 1) {
        deleteFromBeginning();
        return;
    }

    struct Node *temp = head, *prev = NULL;
    for (int i = 1; temp->next != head && i < pos; i++) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == head) {
        printf("Position out of range!\n");
        return;
    }

    prev->next = temp->next;
    free(temp);
}

// Function to display the Circular Linked List
void displayList() {
    if (head == NULL) {
        printf("List is empty!\n");
        return;
    }

    struct Node *temp = head;
    printf("Circular Linked List: ");
    do {
        printf("%d -> ", temp->data);
        temp = temp->next;
    } while (temp != head);
    printf("(Back to Head)\n");
}

// Function to search for an element
void search(int key) {
    if (head == NULL) {
        printf("List is empty!\n");
        return;
    }

    struct Node *temp = head;
    int index = 1;
    do {
        if (temp->data == key) {
            printf("Element %d found at position %d\n", key, index);
            return;
        }
        temp = temp->next;
        index++;
    } while (temp != head);

    printf("Element %d not found in the list.\n", key);
}

// Function to count the number of nodes
int countNodes() {
    if (head == NULL)
        return 0;

    int count = 0;
    struct Node *temp = head;
    do {
        count++;
        temp = temp->next;
    } while (temp != head);

    return count;
}

// Main function to test all operations
int main() {
    int choice, value, pos;

    while (1) {
        printf("\n*** Circular Linked List Operations ***\n");
        printf("1. Insert at Beginning\n2. Insert at End\n3. Insert at Position\n");
        printf("4. Delete from Beginning\n5. Delete from End\n6. Delete from Position\n");
        printf("7. Display List\n8. Search\n9. Count Nodes\n10. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to insert at beginning: ");
                scanf("%d", &value);
                insertAtBeginning(value);
                break;
            case 2:
                printf("Enter value to insert at end: ");
                scanf("%d", &value);
                insertAtEnd(value);
                break;
            case 3:
                printf("Enter value and position: ");
                scanf("%d %d", &value, &pos);
                insertAtPosition(value, pos);
                break;
            case 4:
                deleteFromBeginning();
                break;
            case 5:
                deleteFromEnd();
                break;
            case 6:
                printf("Enter position to delete: ");
                scanf("%d", &pos);
                deleteFromPosition(pos);
                break;
            case 7:
                displayList();
                break;
            case 8:
                printf("Enter value to search: ");
                scanf("%d", &value);
                search(value);
                break;
            case 9:
                printf("Total nodes: %d\n", countNodes());
                break;
            case 10:
                printf("Exiting program.\n");
                return 0;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
}
