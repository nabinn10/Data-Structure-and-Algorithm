#include <stdio.h>
#define MAX 100

// Define the queue structure
typedef struct {
    int items[MAX];
    int front;
    int rear;
} Queue;

// Initialize the queue
void initialize(Queue* queue) {
    queue->front = -1;
    queue->rear = -1;
}

// Check if the queue is empty
int isEmpty(Queue queue) {
    return queue.front == -1;
}

// Check if the queue is full
int isFull(Queue queue) {
    return queue.rear == MAX - 1;
}

// Insert an item into the queue
void insert(Queue* queue, int item) {
    if (isFull(*queue)) {
        printf("Queue is full. Cannot insert %d.\n", item);
        return;
    }
    if (isEmpty(*queue)) {
        queue->front = 0;
    }
    queue->items[++queue->rear] = item;
    printf("Inserted: %d\n", item);
}

// Delete an item from the queue
int delete(Queue* queue) {
    if (isEmpty(*queue)) {
        printf("Queue is empty. Cannot delete.\n");
        return -1; // Return a sentinel value to indicate error
    }
    int item = queue->items[queue->front];
    if (queue->front == queue->rear) {
        queue->front = queue->rear = -1; // Reset the queue
    } else {
        queue->front++;
    }
    return item;
}

// Display the queue
void display(Queue queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty.\n");
        return;
    }
    printf("Queue: ");
    for (int i = queue.front; i <= queue.rear; i++) {
        printf("%d ", queue.items[i]);
    }
    printf("\n");
}

int main() {
    Queue queue;
    initialize(&queue);

    printf("Is queue empty? %s\n", isEmpty(queue) ? "Yes" : "No");

    insert(&queue, 1);
    insert(&queue, 2);
    insert(&queue, 3);

    display(queue);

    printf("Deleted: %d\n", delete(&queue));
    display(queue);

    printf("Is queue empty? %s\n", isEmpty(queue) ? "Yes" : "No");

    delete(&queue);
    delete(&queue);
    delete(&queue); // Attempt to delete from an empty queue

    display(queue);

    return 0;
}
