#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct node {
  int data;
  struct node* next;
} node_t;

node_t* create_node(int data, node_t* next) {
  node_t* new_node = (node_t*)malloc(sizeof(node_t));
  new_node->data = data;
  new_node->next = next;
  return new_node;
}

int size(node_t* head) {
  if (head == NULL) {
    return 0;
  }
  int s = 1;
  node_t* cur = head;
  while (cur->next != NULL) {
    cur = cur->next;
    s++;
  }
  return s;
}

// O(n)
node_t* update(node_t* head, int index, int data) {
  assert(index >= 0 && index < size(head));
  node_t* cur = head;
  for (int i = 0; i < index; i++) {
    cur = cur->next;
  }
  cur->data = data;
  return head;
}

// O(n)
node_t* insert(node_t* head, int index, int data) {
  assert(index >= 0 && index <= size(head));
  node_t* new_node = create_node(data, NULL);
  if (head == NULL) {
    head = new_node;
  } else if (index == 0) {
    new_node->next = head;
    head = new_node;
  } else {
    node_t* cur = head;
    for (int i = 0; i < index; i++) {
      cur = cur->next;
    }
    new_node->next = cur->next;
    cur->next = new_node;
  }
  return head;
}

// O(1)
node_t* insert_head(node_t* head, int data) { return insert(head, 0, data); }

// O(n)
node_t* delete (node_t* head, int index) {
  assert(index >= 0 && index < size(head));
  if (index == 0) {
    node_t* temp = head;
    head = head->next;
    free(temp);
  } else {
    node_t* cur = head;
    for (int i = 0; i < index; i++) {
      cur = cur->next;
    }
    node_t* temp = cur->next;
    cur->next = cur->next->next;
    free(temp);
  }
  return head;
}

// O(1)
node_t* delete_head(node_t* head) { return delete (head, 0); }

void print(node_t* node) {
  if (node != NULL) {
    printf("%d ", node->data);
    print(node->next);
  } else {
    printf("\n");
  }
}

int main() {
  node_t* head = NULL;

  for (int i = 0; i < 10; i++) {
    head = insert(head, 0, i + 1);
    print(head);
  }
  printf("\n");

  for (int i = 0; i < 10; i++) {
    head = update(head, i, i + 1);
    print(head);
  }
  printf("\n");

  for (int i = 0; i < 10; i++) {
    head = delete (head, 0);
    print(head);
  }
  printf("\n");

  return 0;
}
