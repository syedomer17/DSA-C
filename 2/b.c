#include <stdio.h>
#include <stdlib.h>

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

// Insert node at middle
void insertAtMiddle(int value) {
    struct Node* newNode = createNode(value);

    // If list is empty or has 1 node
    if (head == NULL || head->next == NULL) {
        newNode->next = head;
        head = newNode;
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

    printf("Node %d inserted at middle.\n", value);
}

// Display list
void display() {
    struct Node* temp = head;
    printf("Linked List: ");
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// Main function
int main() {
    int n, val;

    printf("Enter how many initial nodes you want: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("Enter value for node %d: ", i + 1);
        scanf("%d", &val);
        // Build list manually without insertAtEnd
        struct Node* newNode = createNode(val);
        if (head == NULL) {
            head = newNode;
        } else {
            struct Node* temp = head;
            while (temp->next != NULL)
                temp = temp->next;
            temp->next = newNode;
        }
    }

    printf("\nInitial ");
    display();

    printf("\nEnter value to insert at middle: ");
    scanf("%d", &val);
    insertAtMiddle(val);

    printf("\nAfter insertion ");
    display();

    return 0;
}
