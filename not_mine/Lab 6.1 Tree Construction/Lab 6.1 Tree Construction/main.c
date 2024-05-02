#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct _tree_node{
    int data;
    struct _tree_node *right;
    struct _tree_node *left;
}tree_node;

tree_node* createTreeNode(int data);
void preOrder(tree_node*);
void inOrder(tree_node*);
void postOrder(tree_node*);

tree_node* createTreeNode(int data){
    tree_node *node = (tree_node*) malloc(sizeof(tree_node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}

void preOrder(tree_node *root){
    if (root!=NULL){
        printf("%d ",root->data);
        preOrder(root->left);
        preOrder(root->right);
    }
}

void inOrder(tree_node *root){
    if (root!=NULL){
        inOrder(root->left);
        printf("%d ",root->data);
        inOrder(root->right);
    }
}

void postOrder(tree_node *root){
    if (root!=NULL){
        postOrder(root->left);
        postOrder(root->right);
        printf("%d ",root->data);
    }
}

int main(void) {
    int number_child = 0, root_data=0;
    int data_input=0;
    char command[10];
    
    scanf("%d",&number_child);
    scanf("%d",&root_data);
    
    tree_node *root = createTreeNode(root_data);
    
    for (int i=0;i<number_child-1;i++){
        tree_node *ptr = root;
        scanf("%s %d",command,&data_input);
        int len =  (int) strlen(command)-1;
        for (int j=0;j<len;j++){
            if (command[j]=='L')
                ptr = ptr->left;
            else
                ptr = ptr->right;
        }
        if (command[len]=='L')
            ptr->left = createTreeNode(data_input);
        else
            ptr->right = createTreeNode(data_input);
    }
    preOrder(root);
    printf("\n");
    inOrder(root);
    printf("\n");
    postOrder(root);
    printf("\n");
    return 0;
}
