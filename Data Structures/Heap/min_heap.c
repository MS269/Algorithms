#include <stdio.h>
#include <stdlib.h>

typedef struct min_heap {
  int *data;
  int size;
  int count;
} min_heap_t;

min_heap_t *create_heap(min_heap_t *heap) {
  heap = (min_heap_t *)malloc(sizeof(min_heap_t));
  heap->size = 1;
  heap->data = (int *)malloc(heap->size * sizeof(int));
  heap->count = 0;
  return heap;
}

// O(logn)
void up_heapify(min_heap_t *heap, int index) {
  int parent = (index - 1) / 2;
  if (parent < 0) {
    return;
  }
  if (heap->data[index] < heap->data[parent]) {
    int temp = heap->data[index];
    heap->data[index] = heap->data[parent];
    heap->data[parent] = temp;
    up_heapify(heap, parent);
  }
}

// O(logn)
void down_heapify(min_heap_t *heap, int index) {
  if (index >= heap->count) {
    return;
  }
  int left = index * 2 + 1;
  int right = index * 2 + 2;
  int leftflag = 0, rightflag = 0;
  int minimum = heap->data[index];
  if (left < heap->count && minimum > heap->data[left]) {
    minimum = heap->data[left];
    leftflag = 1;
  }
  if (right < heap->count && minimum > heap->data[right]) {
    minimum = heap->data[right];
    leftflag = 0;
    rightflag = 1;
  }
  if (leftflag) {
    heap->data[left] = heap->data[index];
    heap->data[index] = minimum;
    down_heapify(heap, left);
  }
  if (rightflag) {
    heap->data[right] = heap->data[index];
    heap->data[index] = minimum;
    down_heapify(heap, right);
  }
}

// O(logn)
void push(min_heap_t *heap, int data) {
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
void pop(min_heap_t *heap) {
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
int top(min_heap_t *heap) {
  if (heap->count != 0) {
    return heap->data[0];
  }
  return 0;
}

int main() {
  min_heap_t *head = create_heap(head);

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
