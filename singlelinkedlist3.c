//3. WAP to create a new node and add at the given position and display.
#include <stdio.h>
#include <stdlib.h>

// Define a structure for a node
struct Node {
    int data;
    struct Node* next;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to add a node at the given position in the list
void addNodeAtPosition(struct Node** head, int data, int position) {
    struct Node* newNode = createNode(data);
    if (position == 1) {
        newNode->next = *head;
        *head = newNode;
    } else {
        struct Node* temp = *head;
        for (int i = 1; i < position - 1 && temp != NULL; i++) {
            temp = temp->next;
        }
        if (temp == NULL) {
            printf("Invalid position\n");
        } else {
            newNode->next = temp->next;
            temp->next = newNode;
        }
    }
}

// Function to display the linked list
void displayList(struct Node* head) {
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    struct Node* head = NULL; // Initialize an empty linked list

    // Add nodes at the given positions
    addNodeAtPosition(&head, 5, 1); // Add 5 at position 1
    addNodeAtPosition(&head, 10, 2); // Add 10 at position 2
    addNodeAtPosition(&head, 15, 2); // Add 15 at position 2

    // Display the linked list
    printf("Linked List: ");
    displayList(head);

    return 0;
}
