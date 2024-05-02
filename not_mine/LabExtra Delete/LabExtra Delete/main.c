#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
  int data;
  struct Node *left;
  struct Node *right;
} Node;

Node *createNode(int data) {
  Node *node = (Node *)malloc(sizeof(Node));
  node->data = data;
  node->left = NULL;
  node->right = NULL;
  return node;
}

void deleteNode(Node **root, int data) {
  if (*root == NULL) {
    return;
  }

  if (data < (*root)->data) {
    deleteNode(&(*root)->left, data);
  } else if (data > (*root)->data) {
    deleteNode(&(*root)->right, data);
  } else {
    // Node found
    if ((*root)->left == NULL) {
      // Leaf node
      Node *temp = *root;
      *root = (*root)->right;
      free(temp);
    } else if ((*root)->right == NULL) {
      // Node with one child
      Node *temp = *root;
      *root = (*root)->left;
      free(temp);
    } else {
      // Node with two children
      Node *successor = (*root)->right;
      while (successor->left != NULL) {
        successor = successor->left;
      }

      (*root)->data = successor->data;
      deleteNode(&(*root)->right, successor->data);
    }
  }
}

//PreOrder
void printTree(Node *root) {
  if (root == NULL) {
    return;
  }

  printf("%d ", root->data);
  printTree(root->left);
  printTree(root->right);
}

int main(void) {
  Node *root = NULL;

  // Insert nodes
  root = createNode(10);
  root->left = createNode(5);
  root->right = createNode(15);
  root->left->left = createNode(3);
  root->left->right = createNode(7);
  root->right->left = createNode(13);
  root->right->right = createNode(17);

  // Print tree
  printf("Tree before deletion:\n");
  printTree(root);

  // Delete node 15
  deleteNode(&root, 15);

  // Print tree
  printf("\nTree after deletion:\n");
  printTree(root);
  printf("\n");

  return 0;
}
