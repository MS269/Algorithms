#include <assert.h>
#include <stdio.h>

#define SIZE 10

int queue[SIZE];
int front = -1;
int rear = -1;

// O(1)
int is_empty() { return front == rear; }

// O(1)
int is_full() { return rear == SIZE - 1; }

// O(1)
void enqueue(int value) {
  assert(!is_full());
  queue[++rear] = value;
}

// O(1)
int dequeue() {
  assert(!is_empty());
  return queue[++front];
}

// O(1)
int peek() {
  assert(!is_empty());
  return queue[front];
}

int main() {
  for (int i = 0; i < 10; i++) {
    enqueue(i + 1);
  }
  printf("\n");

  for (int i = 0; i < 10; i++) {
    printf("%d \n", dequeue());
  }
  printf("\n");

  return 0;
}
