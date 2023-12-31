# include <stdio.h>
# include <stdlib.h>

typedef struct Node Node;
typedef Node* Nodeptr;

struct Node {
    int data;
    Nodeptr next;
};


Nodeptr create(Nodeptr head, int data) {
    Nodeptr newNode = (Nodeptr) malloc (sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

Nodeptr insertAfter(Nodeptr head, int where, int data) {
    Nodeptr newNode = create(head, data);
    Nodeptr temp = head;

    if (!head) return newNode;

    if (temp->data == where) {
        newNode->next = temp->next;
        temp->next = newNode;
        return head;
    }
    while (temp->next && temp->data != where) {
            printf("%d\n", temp->data);
            temp = temp->next;

    }
    newNode->next = temp->next;
    temp->next = newNode;
    return head;
}

Nodeptr insertEnd(Nodeptr head, int data) {
    Nodeptr newNode = create(head, data);

    if (!head) {
        head = newNode;
        return newNode;
    }
    Nodeptr temp = head;
    while (temp->next) {
        temp = temp->next;
    }
    temp->next = newNode;
    return head;
}

void printTraverse(Nodeptr head) {
    if (!head->next) {
        printf("Node 1: %d\n", head->data);
        
    }
    int counter = 0;
    Nodeptr temp = head;
    while (temp->next) {
        printf("Node %d: %d\n", counter++, temp->data);
        temp=temp->next;
    }
    
}

int main() {
    Nodeptr head = NULL;
    head = insertEnd(head, 10);
    head = insertEnd(head, 20);
    head = insertEnd(head, 30);
    head = insertEnd(head, 40);
    head = insertEnd(head, 50);
    head = insertEnd(head, 60);
    printTraverse(head);
    printf("\n");
    head = insertAfter(head, 10, 30);
    printf("%d\n", head->data);
    printTraverse(head);
    //printTraverse(head);

    //Nodeptr inserAt

}