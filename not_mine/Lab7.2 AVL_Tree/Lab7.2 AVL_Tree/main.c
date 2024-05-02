#include <stdio.h>
#include <stdlib.h>

typedef struct BST_NODE
{
    int data;
    struct BST_NODE *left;
    struct BST_NODE *right;
    int height;
} Node;

int height(Node *root);
int balance_factor(Node *root);
Node *createBSTNode(int data);
void preOrder(Node *root);
void inOrder(Node *root);
void postOrder(Node *root);
int maxof(int a, int b);
Node *rotateRight(Node *root);
Node *rotateLeft(Node *root);
Node *insertAVL_BST(Node *root, int data);

int height(Node *root)
{
    if (root == NULL)
        return 0;
    return root->height;
}

int maxof(int a, int b)
{
    return (a > b) ? a : b;
}

Node *createBSTNode(int data)
{
    Node *node = (Node *)malloc(sizeof(Node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    node->height = 1;
    return node;
}

// LL Rotation
Node *rotateRight(Node *root)
{
    Node *new_root = root->left;
    Node *old_R_OF_new_root = new_root->right;

    new_root->right = root;
    root->left = old_R_OF_new_root;

    root->height = maxof(height(root->left), height(root->right)) + 1;
    new_root->height = maxof(height(new_root->left), height(new_root->right)) + 1;
    return new_root;
}

// RR Rotation
Node *rotateLeft(Node *root)
{
    Node *new_root = root->right;
    Node *old_L_OF_new_root = new_root->left;

    new_root->left = root;
    root->right = old_L_OF_new_root;

    root->height = maxof(height(root->left), height(root->right)) + 1;
    new_root->height = maxof(height(new_root->left), height(new_root->right)) + 1;

    return new_root;
}

int balance_factor(Node *root)
{
    if (root == NULL)
        return 0;
    return height(root->left) - height(root->right);
}

void preOrder(Node *root)
{
    if (root != NULL)
    {
        printf("%d ", root->data);
        preOrder(root->left);
        preOrder(root->right);
    }
}

void inOrder(Node *root)
{
    if (root != NULL)
    {
        inOrder(root->left);
        printf("%d ", root->data);
        inOrder(root->right);
    }
}

void postOrder(Node *root)
{
    if (root != NULL)
    {
        postOrder(root->left);
        postOrder(root->right);
        printf("%d ", root->data);
    }
}

Node *insertAVL_BST(Node *root, int data)
{
    if (root == NULL)
        return createBSTNode(data);

    if (data < root->data)
        root->left = insertAVL_BST(root->left, data);
    else if (data > root->data)
        root->right = insertAVL_BST(root->right, data);
    else
        return root; // Duplicate data

    root->height = maxof(height(root->left), height(root->right)) + 1;

    int balance = balance_factor(root);

    // LL Rotation
    if (balance > 1 && data < root->left->data) // Corrected condition
        return rotateRight(root);

    // RR Rotation
    if (balance < -1 && data > root->right->data)
        return rotateLeft(root);

    // LR Rotation
    if (balance > 1 && data > root->left->data)
    {
        root->left = rotateLeft(root->left);
        return rotateRight(root);
    }

    // RL Rotation (mirror image of LR)
    if (balance < -1 && data < root->right->data)
    {
        root->right = rotateRight(root->right);
        return rotateLeft(root);
    }

    return root;
}
int main(void)
{
    int numberOfList, data;
    Node *root = NULL;
    scanf("%d", &numberOfList);
    for (int i = 0; i < numberOfList; i++)
    {
        scanf("%d", &data);
        root = insertAVL_BST(root, data);
    }
    preOrder(root);
    printf("\n");
    inOrder(root);
    printf("\n");
    postOrder(root);
    printf("\n");
    return 0;
}
