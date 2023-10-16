# include <stdio.h>
# include <stdlib.h>

typedef struct Node Node;
typedef struct Node* Nodeptr;
typedef struct Queue Queue;
typedef struct Queue* Queueptr;


struct Node {
    int data;
    Nodeptr next;
};

struct Queue {
    Nodeptr front;
    Nodeptr rear;
};

Queueptr create() {
    Queueptr q = (Queueptr) malloc (sizeof(Queue));
    q->front = NULL;
    q->rear = NULL;
    return q;
}

void enqueue(Queueptr q, int data) {
    if (isFull(q)) {
        printf("Queue Full\n");
        return;
    }

    Nodeptr node = (Nodeptr) malloc (sizeof(Node));
    node->data = data;

    if (q->rear == NULL) {                 // Checks if rear has reached end of queue
        q->front = node;                   // In which case, re-start the queue
        q->rear = node;
        return;
    }

    q->rear->next = node;
    q->rear = node;
    return;

}

int dequeue(Queueptr q) {

    if (isEmpty(q)) {
        printf("Queue is empty\n");
        return -1;
    }

    Nodeptr temp;
    temp = q->rear;
    int val = temp->data;
    q->front = q->front->next;

    if (q->front == NULL) {
        q->rear = NULL;
    }

    free(temp);
    return val;
}