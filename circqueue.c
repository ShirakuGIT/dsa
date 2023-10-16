# include <stdio.h>
# include <stdlib.h>


# define MAX 100

typedef struct queue {
    int front;
    int rear;
    int array[MAX];
} Queue;

typedef Queue* Queueptr;


Queueptr create() {
    Queueptr q = (Queueptr) malloc (sizeof (Queue));
    q->front = -1;
    q->rear = -1;
    return q;
}

void enqueue(Queueptr q, int val) {
    if (isFull(q)) return -1;
    if (isEmpty(q)) {
        q->front = 0;
        q->array[q->rear] = val;
    }
    q->rear = q->rear + 1 % MAX;
    q->array[q->rear] = val;
}

int dequeue(Queueptr q) {
    if (isEmpty(q)) return -1;
    int val = q->array[q->front];
    if (q->front == q->rear) {
        q->front = q->rear = -1;   
    } else {
    q->front = q->front+1%MAX;
    }
    return val;
}

