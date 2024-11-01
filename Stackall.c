#include <stdio.h>
#define MAX 100

// Define the stack structure
typedef struct {
    int items[MAX];
    int top;
} Stack;

// Initialize the stack
void initialize(Stack* stack) {
    stack->top = -1;
}

// Check if the stack is empty
int isEmpty(Stack stack) {
    return stack.top == -1;
}

// Check if the stack is full
int isFull(Stack stack) {
    return stack.top == MAX - 1;
}

// Insert an item onto the stack
void insert(Stack* stack, int item) {
    if (isFull(*stack)) {
        printf("Stack is full. Cannot insert %d.\n", item);
        return;
    }
    stack->items[++stack->top] = item;
    printf("Inserted: %d\n", item);
}

// Delete an item from the stack
int delete(Stack* stack) {
    if (isEmpty(*stack)) {
        printf("Stack is empty. Cannot delete.\n");
        return -1; // Return a sentinel value to indicate error
    }
    return stack->items[stack->top--];
}

// Display the stack
void display(Stack stack) {
    if (isEmpty(stack)) {
        printf("Stack is empty.\n");
        return;
    }
    printf("Stack: ");
    for (int i = 0; i <= stack.top; i++) {
        printf("%d ", stack.items[i]);
    }
    printf("\n");
}

int main() {
    Stack stack;
    initialize(&stack);

    printf("Is stack empty? %s\n", isEmpty(stack) ? "Yes" : "No");

    insert(&stack, 1);
    insert(&stack, 2);
    insert(&stack, 3);

    display(stack);

    printf("Deleted: %d\n", delete(&stack));
    display(stack);

    printf("Is stack empty? %s\n", isEmpty(stack) ? "Yes" : "No");

    delete(&stack);
    delete(&stack);
    delete(&stack); // Attempt to delete from an empty stack

    display(stack);

    return 0;
}
