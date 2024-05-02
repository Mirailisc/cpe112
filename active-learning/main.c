#include <stdio.h>
#include <stdlib.h>

// Structure for a node of the splay tree
typedef struct Node
{
    int key;
    struct Node *left, *right;
} Node;

// Function to create a new node
Node *newNode(int key)
{
    Node *node = (Node *)malloc(sizeof(Node));
    node->key = key;
    node->left = node->right = NULL;
    return node;
}

// Function to perform a right rotation
Node *rightRotate(Node *x)
{
    Node *y = x->left;
    x->left = y->right;
    y->right = x;
    return y;
}

// Function to perform a left rotation
Node *leftRotate(Node *x)
{
    Node *y = x->right;
    x->right = y->left;
    y->left = x;
    return y;
}

// Function to perform splay operation on a given key in the subtree rooted at root
Node *splay(Node *root, int key)
{
    if (root == NULL || root->key == key)
        return root;

    // Key is in left subtree
    if (key < root->key)
    {
        // Key is not in tree, return root
        if (root->left == NULL)
            return root;

        // Zig-Zig (Left Left)
        if (key < root->left->key)
        {
            printf("Zig rotation at key %d\n", root->left->key);
            root->left->left = splay(root->left->left, key);
            root = rightRotate(root);
        }
        // Zig-Zag (Left Right)
        else if (key > root->left->key)
        {
            printf("Zig-Zag rotation at key %d\n", root->left->key);
            root->left->right = splay(root->left->right, key);
            if (root->left->right != NULL)
                root->left = leftRotate(root->left);
        }

        // Do the second rotation to move x to root
        return (root->left == NULL) ? root : rightRotate(root);
    }
    // Key is in right subtree
    else
    {
        // Key is not in tree, return root
        if (root->right == NULL)
            return root;

        // Zag-Zig (Right Left)
        if (key < root->right->key)
        {
            printf("Zag-Zig rotation at key %d\n", root->right->key);
            root->right->left = splay(root->right->left, key);
            if (root->right->left != NULL)
                root->right = rightRotate(root->right);
        }
        // Zag-Zag (Right Right)
        else if (key > root->right->key)
        {
            printf("Zag rotation at key %d\n", root->right->key);
            root->right->right = splay(root->right->right, key);
            root = leftRotate(root);
        }

        // Do the second rotation to move x to root
        return (root->right == NULL) ? root : leftRotate(root);
    }
}

// Function to insert a new key into the splay tree
Node *insert(Node *root, int key)
{
    // If tree is empty, create a new node
    if (root == NULL)
        return newNode(key);

    // Splay the last node of the tree
    root = splay(root, key);

    // If key is already present, return root
    if (root->key == key)
        return root;

    // Allocate memory for new node
    Node *node = newNode(key);

    // If key is greater than root's key, set right child of root as the left child of the new node
    if (root->key < key)
    {
        node->left = root;
        node->right = root->right;
        root->right = NULL;
    }
    // If key is smaller than root's key, set left child of root as the right child of the new node
    else
    {
        node->right = root;
        node->left = root->left;
        root->left = NULL;
    }

    // New node becomes the root
    return node;
}

// Function to perform an inorder traversal of the splay tree
void inorder(Node *root)
{
    if (root != NULL)
    {
        inorder(root->left);
        printf("%d ", root->key);
        inorder(root->right);
    }
}

int main()
{
    Node *root = NULL;
    root = insert(root, 10);
    root = insert(root, 20);
    root = insert(root, 30);
    root = insert(root, 40);
    root = insert(root, 50);

    printf("Inorder traversal of the splay tree: ");
    inorder(root);
    printf("\n");

    return 0;
}
