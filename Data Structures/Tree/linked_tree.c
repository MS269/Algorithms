#include <stdio.h>
#include <stdlib.h>

typedef struct node {
  int data;
  struct node *left;
  struct node *right;
} node_t;

node_t *create_node(int data) {
  node_t *new_node = (node_t *)malloc(sizeof(node_t));
  new_node->data = data;
  new_node->left = NULL;
  new_node->right = NULL;
  return new_node;
}

// root - left - right
void preorder(node_t *root) {
  if (root != NULL) {
    printf("%d ", root->data);
    preorder(root->left);
    preorder(root->right);
  }
}

// left - root - right
void inorder(node_t *root) {
  if (root != NULL) {
    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
  }
}

// right - left - root
void postorder(node_t *root) {
  if (root != NULL) {
    postorder(root->left);
    postorder(root->right);
    printf("%d ", root->data);
  }
}

int main() {
  node_t *root = create_node(1);
  root->left = create_node(2);
  root->right = create_node(3);
  root->left->left = create_node(4);
  root->left->right = create_node(5);

  preorder(root);
  printf("\n");

  inorder(root);
  printf("\n");

  postorder(root);
  printf("\n");

  return 0;
}
