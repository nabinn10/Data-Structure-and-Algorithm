
//1. WAP to create a new node and add at the beginning and display.
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

    // Add nodes at the beginning
    addNodeAtBeginning(&head, 55);
    addNodeAtBeginning(&head, 10);
    addNodeAtBeginning(&head, 15);

    // Display the linked list
    printf("Linked List: ");
    displayList(head);

    return 0;
}
// Function to add a node at the beginning of the list
void addNodeAtBeginning(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    newNode->next = *head;
    *head = newNode;
}
