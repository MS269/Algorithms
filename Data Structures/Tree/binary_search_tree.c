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

// best: O(logn), worst: O(n)
node_t *insert(node_t *root, int data) {
  if (root == NULL) {
    root = create_node(data);
  } else if (data < root->data) {
    root->left = insert(root->left, data);
  } else if (data > root->data) {
    root->right = insert(root->right, data);
  }
  return root;
}

node_t *get_max(node_t *root) {
  if (root->right != NULL) {
    return get_max(root->right);
  }
  return root;
}

// best: O(logn), worst: O(n)
node_t *delete (node_t *root, int data) {
  if (root == NULL) {
    return root;
  } else if (data < root->data) {
    root->left = delete (root->left, data);
  } else if (data > root->data) {
    root->right = delete (root->right, data);
  } else if (data == root->data) {
    if ((root->left == NULL) && (root->right == NULL)) {
      free(root);
      return NULL;
    } else if (root->left == NULL) {
      node_t *temp = root;
      root = root->right;
      free(temp);
      return root;
    } else if (root->right == NULL) {
      node_t *temp = root;
      root = root->left;
      free(temp);
      return root;
    } else {
      node_t *temp = get_max(root->left);
      root->data = temp->data;
      root->left = delete (root->left, temp->data);
    }
  }
  return root;
}

// best: O(logn), worst: O(n)
int find(node_t *root, int data) {
  if (root == NULL) {
    return 0;
  } else if (data < root->data) {
    return find(root->left, data);
  } else if (data > root->data) {
    return find(root->right, data);
  } else if (data == root->data) {
    return 1;
  }
}

// left - root - right, ordered in ascending order
void inorder(node_t *root) {
  if (root != NULL) {
    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
  }
}

int main() {
  node_t *root = NULL;

  for (int i = 0; i < 10; i++) {
    root = insert(root, i + 1);
    inorder(root);
    printf("\n");
  }
  printf("\n");

  for (int i = 0; i < 10; i++) {
    root = delete (root, i + 1);
    inorder(root);
    printf("\n");
  }
  printf("\n");

  return 0;
}
