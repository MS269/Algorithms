#include <stdio.h>
#include <stdlib.h>

#define DEFAULT_CAPACITY 1 << 4

int *dynamic_array = NULL;
int size = 0;
int capacity = DEFAULT_CAPACITY;

// 빈 동적 배열 선언
void init() { dynamic_array = (int *)malloc(sizeof(int) * capacity); }

// 맨 뒤에 원소를 삽입하는 데에 드는 시간 복잡도는 O(1)이다.
void add(const int value) {
  if (size >= capacity) {
    capacity <<= 1;
    dynamic_array = realloc(dynamic_array, sizeof(int *) * capacity);
  }

  dynamic_array[size] = value;
  size++;
}

// 원소에 접근하는 데에 드는 시간 복잡도는 O(1)이다.
void set(const int index, const int value) {
  if (index >= size) {
    return;
  }

  dynamic_array[index] = value;
}

// 임의의 인덱스에 원소를 삽입하는 데에 드는 시간 복잡도는 O(n)이다.
void insert(const int index, const int value) {
  if (index >= size) {
    return;
  }

  if (size >= capacity) {
    capacity <<= 1;
    dynamic_array = realloc(dynamic_array, sizeof(int *) * capacity);
  }

  for (int i = size; i > index; i--) {
    dynamic_array[i] = dynamic_array[i - 1];
  }

  dynamic_array[index] = value;
  size++;
}

// 임의의 인덱스의 원소를 삭제하는 데에 드는 시간 복잡도는 O(n)이다.
void delete (const int index) {
  if (index >= size) {
    return;
  }

  for (int i = index; i < size; i++) {
    dynamic_array[i] = dynamic_array[i + 1];
  }

  dynamic_array[size - 1] = 0;
  size--;

  if (capacity > DEFAULT_CAPACITY && size << 2 <= capacity) {
    capacity >>= 1;
    dynamic_array = realloc(dynamic_array, sizeof(int *) * capacity);
  }
}

void print() {
  for (int i = 0; i < size; i++) {
    printf("%d ", dynamic_array[i]);
  }
  printf("\n");
}

int main(void) {
  init();

  for (int i = 0; i < 5; i++) {
    add(0);
  }
  print();

  for (int i = 0; i < 5; i++) {
    set(i, i + 1);
  }
  print();

  insert(0, 10);
  print();

  delete (0);
  print();

  free(dynamic_array);

  return 0;
}
