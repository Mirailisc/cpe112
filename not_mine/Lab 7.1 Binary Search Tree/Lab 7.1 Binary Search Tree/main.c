#include <stdio.h>
#include <stdlib.h>

typedef struct BST_NODE{
    int data;
    struct BST_NODE *left;
    struct BST_NODE *right;
}BST_NODE;

BST_NODE *createBST_NODE(int data);
void postOrder(BST_NODE *root);
void inOrder(BST_NODE *root);
void preOrder(BST_NODE *root);
BST_NODE* insertBST(BST_NODE *root,int data);

BST_NODE *createBST_NODE(int data){
    BST_NODE *node = (BST_NODE*) malloc(sizeof(BST_NODE));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}

void postOrder(BST_NODE *root){
    if (root!=NULL){
        postOrder(root->left);
        postOrder(root->right);
        printf("%d ",root->data);
    }
}

void inOrder(BST_NODE *root){
    if (root!=NULL){
        inOrder(root->left);
        printf("%d ",root->data);
        inOrder(root->right);
    }
}

void preOrder(BST_NODE *root){
    if (root!=NULL){
        printf("%d ",root->data);
        preOrder(root->left);
        preOrder(root->right);
    }
}

BST_NODE* insertBST(BST_NODE *root,int data){
    if (root==NULL)
        root = createBST_NODE(data);
    else if (data > root->data)
        root->right = insertBST(root->right, data);
    else if (data < root->data)
        root->left = insertBST(root->left, data);
    return root;
}

int main(void) {
    int numberBST,data;
    scanf("%d",&numberBST);
    scanf("%d",&data);
    BST_NODE *root = createBST_NODE(data);
    for (int i=0;i<numberBST-1;i++){
        scanf("%d",&data);
        insertBST(root, data);
    }
    preOrder(root);
    printf("\n");
    inOrder(root);
    printf("\n");
    postOrder(root);
    printf("\n");
    return 0;
}
