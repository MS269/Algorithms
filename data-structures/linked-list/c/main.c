#include <stdio.h>
#include <stdlib.h>

struct Node {
  int data;
  struct Node *next;
};

struct Node *head = NULL;

// 맨 앞에 노드를 삽입하는 데에 드는 시간 복잡도는 O(1)이다.
void insert_head(int value) {
  struct Node *new = (struct Node *)malloc(sizeof(struct Node));
  new->data = value;
  new->next = NULL;

  if (head == NULL) {
    head = new;
  } else {
    new->next = head;
    head = new;
  }
}

// 맨 앞의 노드를 삭제하는 데에 드는 시간 복잡도는 O(1)이다.
void delete_head() {
  if (head != NULL) {
    struct Node *temp = head;
    head = head->next;
    free(temp);
  }
}

// 노드에 접근하는 데에 드는 시간 복잡도는 O(n)이다.
void print() {
  struct Node *now = head;

  while (now != NULL) {
    printf("%d ", now->data);
    now = now->next;
  }
  printf("\n");
}

int main(void) {
  for (int i = 0; i < 5; i++) {
    insert_head(i + 1);
  }
  // 5 -> 4 -> 3 -> 2 -> 1 -> NULL

  insert_head(10);
  // 10 -> 5 -> 4 -> 3 -> 2 -> 1 -> NULL

  delete_head();
  // 5 -> 4 -> 3 -> 2 -> 1 -> NULL

  print();
  // 5 4 3 2 1

  return 0;
}
