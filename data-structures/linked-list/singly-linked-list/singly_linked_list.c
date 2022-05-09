#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
  int data;
  struct Node *next;
} node_t;

typedef struct SinglyLinkedList {
  node_t *head;
  int size;
} singly_linked_list_t;

node_t *create_node(int data) {
  node_t *new_node = (node_t *)malloc(sizeof(node_t));
  new_node->data = data;
  new_node->next = NULL;
  return new_node;
}

singly_linked_list_t *init() {
  singly_linked_list_t *singly_linked_list =
      (singly_linked_list_t *)malloc(sizeof(singly_linked_list_t *));
  singly_linked_list->head = NULL;
  singly_linked_list->size = 0;
  return singly_linked_list;
}

// O(n)
int getData(singly_linked_list_t *self, int index) {
  assert(index >= 0 && index < self->size);
  node_t *temp = self->head;
  for (int i = 0; i < index; i++) {
    temp = temp->next;
  }
  return temp->data;
}

// O(n)
void setData(singly_linked_list_t *self, int index, int data) {
  assert(index >= 0 && index < self->size);
  node_t *temp = self->head;
  for (int i = 0; i < index; i++) {
    temp = temp->next;
  }
  temp->data = data;
}

// O(n)
void insert_nth(singly_linked_list_t *self, int index, int data) {
  assert(index >= 0 && index <= (self->size)++);
  node_t *new_node = create_node(data);
  if (self->head == NULL) {
    self->head = new_node;
  } else if (index == 0) {
    new_node->next = self->head;
    self->head = new_node;
  } else {
    node_t *temp = self->head;
    for (int i = 0; i < index - 1; i++) {
      temp = temp->next;
    }
    new_node->next = temp->next;
    temp->next = new_node;
  }
}

// O(1)
void insert_head(singly_linked_list_t *self, int data) {
  insert_nth(self, 0, data);
}

// O(n)
void insert_tail(singly_linked_list_t *self, int data) {
  insert_nth(self, self->size, data);
}

// O(n)
int delete_nth(singly_linked_list_t *self, int index) {
  assert(index >= 0 && index <= (self->size)-- - 1);
  node_t *delete_node = self->head;
  if (index == 0) {
    self->head = self->head->next;
  } else {
    node_t *temp = self->head;
    for (int i = 0; i < index - 1; i++) {
      temp = temp->next;
    }
    delete_node = temp->next;
    temp->next = temp->next->next;
  }
  int data = delete_node->data;
  free(delete_node);
  return data;
}

// O(1)
int delete_head(singly_linked_list_t *self) { return delete_nth(self, 0); }

// O(n)
int delete_tail(singly_linked_list_t *self) {
  return delete_nth(self, self->size - 1);
}

// O(n)
void print(singly_linked_list_t *self) {
  node_t *temp = self->head;
  while (temp != NULL) {
    printf("%d", temp->data);
    temp = temp->next;
    printf(temp != NULL ? "->" : "\n");
  }
}

int main(void) {
  singly_linked_list_t *singly_linked_list = init();

  for (int i = 0; i < 5; i++) {
    insert_head(singly_linked_list, i + 1);
    print(singly_linked_list);
  }

  for (int i = 0; i < 5; i++) {
    printf("%d ", getData(singly_linked_list, i));
  }
  printf("\n");

  for (int i = 0; i < 5; i++) {
    setData(singly_linked_list, i, i + 1);
    printf("%d ", getData(singly_linked_list, i));
  }
  printf("\n");

  for (int i = 0; i < 5; i++) {
    printf("%d ", delete_head(singly_linked_list));
    print(singly_linked_list);
  }

  return 0;
}
