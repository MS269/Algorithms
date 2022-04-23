#include <stdio.h>
#include <stdlib.h>

int main(void) {
  int *array_list = malloc(sizeof(int) * 5);  // 크기가 5인 배열 리스트

  // 원소에 접근하는 데에 드는 시간 복잡도는 O(1)이다.
  for (int i = 0; i < 5; i++) {
    array_list[i] = i + 1;
  }

  // 원소를 삽입하는 데에 드는 시간 복잡도는 O(n)이다.
  array_list = realloc(array_list, sizeof(int) * 6);
  for (int i = 5; i >= 0; i--) {
    array_list[i + 1] = array_list[i];
  }
  array_list[0] = 0;

  // free를 꼭! 해주어야한다.
  free(array_list);

  return 0;
}
