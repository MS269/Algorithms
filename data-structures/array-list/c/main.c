#include <stdio.h>
#include <stdlib.h>

int main(void) {
  int *array = malloc(sizeof(int) * 5);  // 크기가 5인 동적 배열 선언

  // 원소에 접근하는 데에 드는 시간 복잡도는 O(1)이다.
  for (int i = 0; i < 5; i++) {
    array[i] = i + 1;
  }
  // array = {1, 2, 3, 4, 5}

  // 원소를 삽입하는 데에 드는 시간 복잡도는 O(n)이다.
  array = realloc(array, sizeof(int) * 6);
  for (int i = 5; i > 0; i--) {
    array[i] = array[i - 1];
  }
  array[0] = 10;
  // array = {10, 1, 2, 3, 4, 5}

  // 원소를 삭제하는 데에 드는 시간 복잡도는 O(n)이다.
  for (int i = 0; i < 5; i++) {
    array[i] = array[i + 1];
  }
  array = realloc(array, sizeof(int) * 5);
  // array = {1, 2, 3, 4, 5}

  // free는 꼭! 해줘야한다.
  free(array);

  return 0;
}
