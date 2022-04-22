#include <stdio.h>

int main(void) {
  int array1[5];                   // 크기가 5인 배열 선언
  int array2[] = {1, 2, 3, 4, 5};  // 배열 초기화
  int *array3;                     // int array3[]과 비슷하다.

  // 원소에 접근하는 데에 드는 시간 복잡도는 O(1)이다.
  printf("%d\n", array2[2]);

  // 원소를 삭제하는 데에 드는 시간 복잡도는 O(n)이다.
  for (int i = 0; i < 4; i++) {
    array2[i] = array2[i + 1];
  }
  array2[4] = 0;

  return 0;
}
