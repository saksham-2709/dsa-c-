#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 5

// Define the circular queue structure
typedef struct {
    int items[MAX_SIZE];
    int front, rear;
} CircularQueue;

// Function to initialize the circular queue
void initialize(CircularQueue *queue) {
    queue->front = -1;
    queue->rear = -1;
}

// Function to check if the circular queue is empty
int isEmpty(CircularQueue *queue) {
    return (queue->front == -1);
}

// Function to check if the circular queue is full
int isFull(CircularQueue *queue) {
    return ((queue->rear + 1) % MAX_SIZE == queue->front);
}

// Function to add an element to the circular queue
void enqueue(CircularQueue *queue, int value) {
    if (isFull(queue)) {
        printf("Queue Overflow\n");
        return;
    }
    if (isEmpty(queue)) {
        queue->front = 0;
        queue->rear = 0;
    } else {
        queue->rear = (queue->rear + 1) % MAX_SIZE;
    }
    queue->items[queue->rear] = value;
}

// Function to remove an element from the circular queue
int dequeue(CircularQueue *queue) {
    if (isEmpty(queue)) {
        printf("Queue Underflow\n");
        return -1;
    }
    int dequeuedItem = queue->items[queue->front];
    if (queue->front == queue->rear) {
        queue->front = -1;
        queue->rear = -1;
    } else {
        queue->front = (queue->front + 1) % MAX_SIZE;
    }
    return dequeuedItem;
}

// Function to get the front element of the circular queue
int front(CircularQueue *queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty\n");
        return -1;
    }
    return queue->items[queue->front];
}

int main() {
    CircularQueue queue;
    initialize(&queue);

    enqueue(&queue, 10);
    enqueue(&queue, 20);
    enqueue(&queue, 30);
    enqueue(&queue, 40);
    enqueue(&queue, 50);

    printf("Front element: %d\n", front(&queue));

    printf("Dequeued element: %d\n", dequeue(&queue));
    printf("Dequeued element: %d\n", dequeue(&queue));

    printf("Front element: %d\n", front(&queue));

    return 0;
}
