#include <stdio.h>
#include <stdlib.h>

typedef struct max_heap {
  int *data;
  int size;
  int count;
} max_heap_t;

max_heap_t *create_heap(max_heap_t *heap) {
  heap = (max_heap_t *)malloc(sizeof(max_heap_t));
  heap->size = 1;
  heap->data = (int *)malloc(heap->size * sizeof(int));
  heap->count = 0;
  return heap;
}

// O(logn)
void up_heapify(max_heap_t *heap, int index) {
  int parent = (index - 1) / 2;
  if (parent < 0) {
    return;
  }
  if (heap->data[index] > heap->data[parent]) {
    int temp = heap->data[index];
    heap->data[index] = heap->data[parent];
    heap->data[parent] = temp;
    up_heapify(heap, parent);
  }
}

// O(logn)
void down_heapify(max_heap_t *heap, int index) {
  if (index >= heap->count) {
    return;
  }
  int left = index * 2 + 1;
  int right = index * 2 + 2;
  int leftflag = 0, rightflag = 0;
  int maximum = heap->data[index];
  if (left < heap->count && maximum < heap->data[left]) {
    maximum = heap->data[left];
    leftflag = 1;
  }
  if (right < heap->count && maximum < heap->data[right]) {
    maximum = heap->data[right];
    leftflag = 0;
    rightflag = 1;
  }
  if (leftflag) {
    heap->data[left] = heap->data[index];
    heap->data[index] = maximum;
    down_heapify(heap, left);
  }
  if (rightflag) {
    heap->data[right] = heap->data[index];
    heap->data[index] = maximum;
    down_heapify(heap, right);
  }
}

// O(logn)
void push(max_heap_t *heap, int data) {
  if (heap->count >= heap->size) {
    return;
  }
  heap->data[heap->count++] = data;
  if (4 * heap->count >= 3 * heap->size) {
    heap->data = (int *)realloc(heap->data, (heap->size <<= 1) * sizeof(int));
  }
  up_heapify(heap, heap->count - 1);
}

// O(logn)
void pop(max_heap_t *heap) {
  if (heap->count == 0) {
    return;
  }
  int temp = heap->data[--heap->count];
  heap->data[heap->count] = heap->data[0];
  heap->data[0] = temp;
  down_heapify(heap, 0);
  if (4 * heap->count <= heap->size) {
    heap->data = (int *)realloc(heap->data, (heap->size >>= 1) * sizeof(int));
  }
}

// O(1)
int top(max_heap_t *heap) {
  if (heap->count != 0) {
    return heap->data[0];
  }
  return 0;
}

int main() {
  max_heap_t *head = create_heap(head);

  for (int i = 0; i < 10; i++) {
    push(head, i + 1);
    printf("%d \n", top(head));
  }
  printf("\n");

  for (int i = 0; i < 10; i++) {
    pop(head);
    printf("%d \n", top(head));
  }
  printf("\n");

  return 0;
}
