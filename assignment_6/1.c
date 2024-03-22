// Phubordin Poolnai 66070501040
#include <stdio.h>
#include <stdlib.h>

struct AVLNode
{
    int key;
    struct AVLNode *left;
    struct AVLNode *right;
    int height;
};

int getHeight(struct AVLNode *N)
{
    if (N == NULL)
        return 0;
    return N->height;
}

int max(int a, int b)
{
    return (a > b) ? a : b;
}

struct AVLNode *createNode(int key)
{
    struct AVLNode *node = (struct AVLNode *)malloc(sizeof(struct AVLNode));
    node->key = key;
    node->left = NULL;
    node->right = NULL;
    node->height = 1;
    return (node);
}

struct AVLNode *rightRotate(struct AVLNode *y)
{
    struct AVLNode *x = y->left;
    struct AVLNode *temp = x->right;

    x->right = y;
    y->left = temp;

    y->height = max(getHeight(y->left), getHeight(y->right)) + 1;
    x->height = max(getHeight(x->left), getHeight(x->right)) + 1;

    return x;
}

struct AVLNode *leftRotate(struct AVLNode *x)
{
    struct AVLNode *y = x->right;
    struct AVLNode *temp = y->left;

    y->left = x;
    x->right = temp;

    x->height = max(getHeight(x->left), getHeight(x->right)) + 1;
    y->height = max(getHeight(y->left), getHeight(y->right)) + 1;

    return y;
}

int getBalance(struct AVLNode *N)
{
    if (N == NULL)
        return 0;
    return getHeight(N->left) - getHeight(N->right);
}

struct AVLNode *avlInsert(struct AVLNode *node, int key)
{
    if (node == NULL)
        return (createNode(key));

    if (key < node->key)
        node->left = avlInsert(node->left, key);
    else if (key > node->key)
        node->right = avlInsert(node->right, key);
    else
        return node;

    node->height = 1 + max(getHeight(node->left), getHeight(node->right));

    int balance = getBalance(node);

    if (balance > 1 && key < node->left->key)
        return rightRotate(node);

    if (balance < -1 && key > node->right->key)
        return leftRotate(node);

    if (balance > 1 && key > node->left->key)
    {
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }

    if (balance < -1 && key < node->right->key)
    {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }

    return node;
}

int count = 0;
int k;
int result;

void inOrderTraversal(struct AVLNode *root)
{
    if (root == NULL)
    {
        return;
    }
    inOrderTraversal(root->left);
    count++;
    if (count == k)
    {
        result = root->key;
    }
    inOrderTraversal(root->right);
}

int main()
{
    struct AVLNode *root = NULL;
    int n, data;

    scanf("%d", &n);
    for (int i = 0; i < n; ++i)
    {
        scanf("%d", &data);
        root = avlInsert(root, data);
    }

    scanf("%d", &k);
    inOrderTraversal(root);
    if (count >= k)
    {
        printf("%d", result);
    }
    else
    {
        printf("None");
    }

    return 0;
}
