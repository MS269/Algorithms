#include <assert.h>
#include <stdio.h>

#define CAPACITY 10

int array[CAPACITY];
int size = 0;

// O(1)
void update(int index, int value) {
  assert(index >= 0 && index < CAPACITY && index < size);
  array[index] = value;
}

// O(n)
void insert(int index, int value) {
  assert(index >= 0 && index < CAPACITY && index <= size++);
  for (int i = size; i > index; i--) {
    array[i] = array[i - 1];
  }
  array[index] = value;
}

// O(n)
void delete (int index) {
  assert(index >= 0 && index < CAPACITY && index < size--);
  for (int i = index; i < size; i++) {
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
    insert(0, i + 1);
    print();
  }
  printf("\n");

  for (int i = 0; i < 10; i++) {
    update(i, i + 1);
    print();
  }
  printf("\n");

  for (int i = 0; i < 10; i++) {
    delete (0);
    print();
  }
  printf("\n");

  return 0;
}
