
//7. WAp to create 5 node and display.
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
    if (newNode == NULL) {
        printf("Memory allocation failed.\n");
        exit(1);
    }
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

    // Create 5 nodes and link them together
    for (int i = 5; i >= 1; i--) {
        struct Node* newNode = createNode(i);
        newNode->next = head;
        head = newNode;
    }

    // Display the linked list
    printf("Linked List: ");
    displayList(head);

    return 0;
}

