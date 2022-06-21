#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

#define DEFAULT_CAPACITY 1 << 3

typedef struct dynamic_array {
  int* data;
  int size;
  int capacity;
} dynamic_array_t;

dynamic_array_t* init() {
  dynamic_array_t* da = malloc(sizeof(dynamic_array_t));
  da->data = malloc(DEFAULT_CAPACITY * sizeof(int*));
  da->size = 0;
  da->capacity = DEFAULT_CAPACITY;
  return da;
}

// O(1)
void update(dynamic_array_t* da, int index, int value) {
  assert(index >= 0 && index < da->size);
  da->data[index] = value;
}

// O(n)
void insert(dynamic_array_t* da, int index, int value) {
  assert(index >= 0 && index <= da->size++);
  if (da->size > da->capacity) {
    da->data = realloc(da->data, (da->capacity <<= 1) * sizeof(int*));
  }
  for (int i = da->size; i > index; i--) {
    da->data[i] = da->data[i - 1];
  }
  da->data[index] = value;
}

// O(n)
void delete (dynamic_array_t* da, int index) {
  assert(index >= 0 && index < da->size--);
  for (int i = index; i < da->size; i++) {
    da->data[i] = da->data[i + 1];
  }
  da->data[da->size] = 0;
}

void print(dynamic_array_t* da) {
  for (int i = 0; i < da->size; i++) {
    printf("%d ", da->data[i]);
  }
  printf("\n");
}

int main() {
  dynamic_array_t* da = init();

  for (int i = 0; i < 10; i++) {
    insert(da, 0, i + 1);
    print(da);
  }
  printf("\n");

  for (int i = 0; i < 10; i++) {
    update(da, i, i + 1);
    print(da);
  }
  printf("\n");

  for (int i = 0; i < 10; i++) {
    delete (da, 0);
    print(da);
  }
  printf("\n");

  return 0;
}
