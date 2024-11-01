//4. WAP to delete first node and display.
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

// Function to delete the first node of the doubly linked list
void deleteFirstNode(struct Node** head) {
    if (*head == NULL) {
        printf("List is empty. Nothing to delete.\n");
        return;
    }
    struct Node* temp = *head;
    *head = (*head)->next;
    if (*head != NULL) {
        (*head)->prev = NULL;
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

    // Delete the first node
    deleteFirstNode(&head);

    // Display the updated doubly linked list
    printf("Updated Doubly Linked List after deleting first node: ");
    displayList(head);

    return 0;
}
