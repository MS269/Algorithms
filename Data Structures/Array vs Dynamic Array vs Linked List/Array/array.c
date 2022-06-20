#include <assert.h>
#include <stdio.h>

#define CAPACITY 10

int array[CAPACITY];
int size = 0;

// O(1)
void update(int position, int value) {
  assert(position >= 0 && position < CAPACITY && position < size);
  array[position] = value;
}

// O(n)
void insert(int position, int value) {
  assert(position >= 0 && position < CAPACITY && position <= size++);
  for (int i = size; i > position; i--) {
    array[i] = array[i - 1];
  }
  array[position] = value;
}

// O(n)
void delete (int position) {
  assert(position >= 0 && position < CAPACITY && position < size--);
  for (int i = position; i < size; i++) {
    array[i] = array[i + 1];
  }
  array[size] = 0;
}

void print() {
  for (int i = 0; i < size; i++) {
    printf("%d ", array[i]);
  }
  printf("\n");
}

int main() {
  for (int i = 0; i < 10; i++) {
    insert(size, i + 1);
  }
  print();

  for (int i = 0; i < 10; i++) {
    update(i, 10 - i);
  }
  print();

  for (int i = 0; i < 10; i++) {
    delete (0);
  }
  print();

  return 0;
}
