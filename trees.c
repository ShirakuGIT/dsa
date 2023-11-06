# include <stdio.h>
# include <stdlib.h>

typedef struct Node Node;
typedef struct Node* Nodeptr;

struct Node
{
    int data;
    Nodeptr left;
    Nodeptr right;  
};


Nodeptr newNode(Nodeptr root, int value) {
    Nodeptr node = (Nodeptr)malloc(sizeof(struct Node));
    node->data = value;
    node->left = NULL;
    node->right = NULL;
    return node;
}


// Binary Search Tree implementation of insert function
// root -> is the pointer to the first Node
// value -> is the value to be inserted
Nodeptr insert(Nodeptr root, int value)
{
    if (root == NULL)
    {
        return newNode(root, value);
    }
    else 
    {
        if (value < root->data) 
        {
            root->left = insert(root->left, value);
        }
        else
        {
            root->right = insert(root->right, value);
        }
    }
    return root;
}

// Inorder, Postorder, Preorder Traversal

void inorderTraversal(Nodeptr root)
{
    if (root != NULL)
    {
        inorderTraversal(root->left);
        printf("%d\n", root->data);
        inorderTraversal(root->right);
    }
}

int main(void)
{
    Nodeptr root;
    root = NULL;
    root = insert(root, 10);
    root = insert(root, 20);
    root = insert(root, 30);
    inorderTraversal(root);
    return 0; // It's a good practice to return a value from main
}
