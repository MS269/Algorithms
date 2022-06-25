#include <assert.h>
#include <stdio.h>

#define MAX 10

int stack[MAX];
int top = -1;

// O(1)
int is_empty() { return top == -1; }

// O(1)
int is_full() { return top == MAX - 1; }

// O(1)
void push(int value) {
  assert(!is_full());
  stack[++top] = value;
}

// O(1)
int pop() {
  assert(!is_empty());
  return stack[top--];
}

// O(1)
int peek() {
  assert(!is_empty());
  return stack[top];
}

int main() {
  for (int i = 0; i < 10; i++) {
    push(i + 1);
    printf("%d \n", peek());
  }
  printf("\n");

  for (int i = 0; i < 10; i++) {
    printf("%d \n", pop());
  }
  printf("\n");

  return 0;
}
