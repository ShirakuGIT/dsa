# include <stdio.h>
# include <stdlib.h>

// Basic Data Type Abstractions
typedef struct Node Node;
typedef Node* Nodeptr;
typedef struct Stack Stack;
typedef Stack* Stackptr;

struct Node {
    int data;
    Nodeptr next;
};

struct Stack {
    Nodeptr top;
};

Stackptr createStack() {
    Stackptr newStack = (Stackptr) malloc (sizeof(Stack));
    newStack->top = NULL;
    return newStack;
}

void push(Stackptr s, int data) {
    Nodeptr newNode = (Nodeptr) malloc (sizeof(Node));
    newNode->data = data;
    newNode->next = s->top;
    s->top = newNode;
}

int pop(Stackptr s) {
    if (!s->top) {
        printf("Stack Underflow, no items.\n");
        return -1;
    }
    Nodeptr temp = s->top;
    s->top = s->top->next;
    int data = temp->data;
    free(temp);
    return data;
}
