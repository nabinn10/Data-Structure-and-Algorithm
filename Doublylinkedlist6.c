//6. WAP to delete a node of the given position and display.
#include <stdio.h>
#include <stdlib.h>

// Define a structure for a node
struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed.\n");
        exit(1);
    }
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

// Function to delete a node at the given position in the list
void deleteNodeAtPosition(struct Node** head, int position) {
    if (*head == NULL) {
        printf("List is empty. Nothing to delete.\n");
        return;
    }
    if (position < 1) {
        printf("Invalid position\n");
        return;
    }
    struct Node* temp = *head;
    int count = 1;
    while (temp != NULL && count < position) {
        temp = temp->next;
        count++;
    }
    if (temp == NULL) {
        printf("Invalid position\n");
        return;
    }
    if (temp->prev != NULL) {
        temp->prev->next = temp->next;
    } else {
        *head = temp->next;
    }
    if (temp->next != NULL) {
        temp->next->prev = temp->prev;
    }
    free(temp);
}

// Function to display the doubly linked list
void displayList(struct Node* head) {
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d <-> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    struct Node* head = NULL; // Initialize an empty doubly linked list

    // Add some nodes to the list
    head = createNode(5);
    head->next = createNode(10);
    head->next->prev = head;

    // Display the original doubly linked list
    printf("Original Doubly Linked List: ");
    displayList(head);

    // Delete a node at position 2
    int position = 2;
    deleteNodeAtPosition(&head, position);

    // Display the updated doubly linked list
    printf("Updated Doubly Linked List after deleting node at position %d: ", position);
    displayList(head);

    return 0;
}
