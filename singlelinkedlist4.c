//4. WAP to delete first node and display.
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

// Function to delete the first node of the list
void deleteFirstNode(struct Node** head) {
    if (*head == NULL) {
        printf("List is empty. Nothing to delete.\n");
    } else {
        struct Node* temp = *head;
        *head = (*head)->next;
        free(temp);
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

    // Add some nodes to the list
    head = createNode(5);
    head->next = createNode(10);
    head->next->next = createNode(15);

    // Display the original linked list
    printf("Original Linked List: ");
    displayList(head);

    // Delete the first node
    deleteFirstNode(&head);

    // Display the updated linked list
    printf("Updated Linked List after deleting first node: ");
    displayList(head);

    return 0;
}
