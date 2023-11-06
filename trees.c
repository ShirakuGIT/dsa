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


Nodeptr newNode(Nodeptr root, int value)
{
    Nodeptr newNode = (Nodeptr) malloc (sizeof(Node));
    newNode->data = value;
    if (!root)
    {
        return newNode;
    }
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Binary Search Tree implementation of insert function
Nodeptr insert(Nodeptr root, int value)
{
    if (!root)
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
    if (root)
    {
        inorderTraversal(root->left);
        printf("%d");
        inorderTraversal(root->right);
    }
}

int main(void)
{
    
}