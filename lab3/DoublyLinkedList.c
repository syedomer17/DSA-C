#include <stdio.h>
#include <stdlib.h>

// Node structure for Doubly Linked List
struct Node {
    int data;
    struct Node *next;
    struct Node *prev;
};

// Head pointer initialized to NULL
struct Node *head = NULL;

// Function prototypes
void insertAtBeginning(int);
void insertAtEnd(int);
void insertBetween(int, int, int);
void display();
void removeBeginning();
void removeEnd();
void removeSpecific(int);

int main() {
    int choice, value, choice1, loc1, loc2;

    while (1) {
        printf("\n\n****** MENU ******\n");
        printf("1. Insert\n2. Display\n3. Delete\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the value to insert: ");
                scanf("%d", &value);
                printf("Where do you want to insert?\n");
                printf("1. At Beginning\n2. At End\n3. Between\n");
                printf("Enter your choice: ");
                scanf("%d", &choice1);

                switch (choice1) {
                    case 1:
                        insertAtBeginning(value);
                        break;
                    case 2:
                        insertAtEnd(value);
                        break;
                    case 3:
                        printf("Enter the two values where you want to insert: ");
                        scanf("%d%d", &loc1, &loc2);
                        insertBetween(value, loc1, loc2);
                        break;
                    default:
                        printf("\nWrong Input!! Try again!\n");
                }
                break;

            case 2:
                display();
                break;

            case 3:
                printf("How do you want to delete?\n");
                printf("1. From Beginning\n2. From End\n3. Specific\n");
                printf("Enter your choice: ");
                scanf("%d", &choice1);

                switch (choice1) {
                    case 1:
                        removeBeginning();
                        break;
                    case 2:
                        removeEnd();
                        break;
                    case 3:
                        printf("Enter the value to delete: ");
                        scanf("%d", &loc2);
                        removeSpecific(loc2);
                        break;
                    default:
                        printf("\nWrong Input!! Try again!\n");
                }
                break;

            case 4:
                exit(0);

            default:
                printf("\nWrong input!!! Try again!!\n");
        }
    }
}

// Function to insert at the beginning
void insertAtBeginning(int value) {
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = head;
    newNode->prev = NULL;

    if (head != NULL) {
        head->prev = newNode;
    }
    head = newNode;
    printf("\nOne node inserted at the beginning!\n");
}

// Function to insert at the end
void insertAtEnd(int value) {
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;

    if (head == NULL) {
        newNode->prev = NULL;
        head = newNode;
    } else {
        struct Node *temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->prev = temp;
    }
    printf("\nOne node inserted at the end!\n");
}

// Function to insert between two nodes
void insertBetween(int value, int loc1, int loc2) {
    struct Node *temp = head;
    while (temp != NULL && temp->data != loc1 && temp->data != loc2) {
        temp = temp->next;
    }
    if (temp == NULL) {
        printf("\nGiven nodes not found!\n");
        return;
    }
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = temp->next;
    newNode->prev = temp;

    if (temp->next != NULL) {
        temp->next->prev = newNode;
    }
    temp->next = newNode;
    printf("\nOne node inserted between %d and %d!\n", loc1, loc2);
}

// Function to delete from the beginning
void removeBeginning() {
    if (head == NULL) {
        printf("\nList is Empty!\n");
        return;
    }
    struct Node *temp = head;
    head = head->next;
    if (head != NULL) {
        head->prev = NULL;
    }
    free(temp);
    printf("\nOne node deleted from the beginning!\n");
}

// Function to delete from the end
void removeEnd() {
    if (head == NULL) {
        printf("\nList is Empty!\n");
        return;
    }
    struct Node *temp = head;
    if (temp->next == NULL) {
        head = NULL;
        free(temp);
        printf("\nOne node deleted from the end!\n");
        return;
    }

    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->prev->next = NULL;
    free(temp);
    printf("\nOne node deleted from the end!\n");
}

// Function to delete a specific node
void removeSpecific(int delValue) {
    struct Node *temp = head;
    while (temp != NULL && temp->data != delValue) {
        temp = temp->next;
    }
    if (temp == NULL) {
        printf("\nGiven node not found in the list!\n");
        return;
    }
    if (temp->prev != NULL) {
        temp->prev->next = temp->next;
    } else {
        head = temp->next;
    }
    if (temp->next != NULL) {
        temp->next->prev = temp->prev;
    }
    free(temp);
    printf("\nOne node deleted!\n");
}

// Function to display the list
void display() {
    if (head == NULL) {
        printf("\nList is Empty\n");
        return;
    }
    struct Node *temp = head;
    printf("\nList elements are: \n");
    while (temp != NULL) {
        printf("%d <-> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}
