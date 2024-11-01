//6. WAP to delete a node of the given position and display.
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

// Function to delete a node at the given position in the list
void deleteNodeAtPosition(struct Node** head, int position) {
    if (*head == NULL) {
        printf("List is empty. Nothing to delete.\n");
    } else {
        struct Node* temp = *head;
        struct Node* prev = NULL;
        int count = 1;

        // Traverse to the node at the given position
        while (temp != NULL && count < position) {
            prev = temp;
            temp = temp->next;
            count++;
        }

        // If position is greater than the number of nodes in the list
        if (temp == NULL) {
            printf("Invalid position\n");
            return;
        }

        // If the node to be deleted is the first node
        if (prev == NULL) {
            *head = temp->next;
        } else {
            prev->next = temp->next;
        }

        // Free the memory occupied by the node
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

    // Delete a node at a given position
    int position = 2;
    deleteNodeAtPosition(&head, position);

    // Display the updated linked list
    printf("Linked List after deleting node at position %d: ", position);
    displayList(head);

    return 0;
}
