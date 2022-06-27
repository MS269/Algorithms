#include <stdio.h>
#include <stdlib.h>

#define SIZE 1 << 2 + 1

int tree[SIZE];

// root - left - right
void preorder(int root) {
  if (root > 0 && root < SIZE && tree[root] != 0) {
    printf("%d ", tree[root]);
    preorder(root * 2);
    preorder(root * 2 + 1);
  }
}

// left - root - right
void inorder(int root) {
  if (root > 0 && root < SIZE && tree[root] != 0) {
    inorder(root * 2);
    printf("%d ", tree[root]);
    inorder(root * 2 + 1);
  }
}

// right - left - root
void postorder(int root) {
  if (root > 0 && root < SIZE && tree[root] != 0) {
    postorder(root * 2);
    postorder(root * 2 + 1);
    printf("%d ", tree[root]);
  }
}

int main() {
  tree[1] = 1;
  tree[2] = 2;
  tree[3] = 3;
  tree[4] = 4;
  tree[5] = 5;

  preorder(1);
  printf("\n");

  inorder(1);
  printf("\n");

  postorder(1);
  printf("\n");

  return 0;
}
