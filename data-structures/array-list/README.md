# 배열 리스트(Array List)

배열은 메모리 주소가 연속될 것을 요구하기 때문에 길이를 줄이거나 늘리는 것이 불가능하다.
따라서 데이터가 계속해서 늘어나서 길이가 부족할 때 그리고 최대 길이를 알 수 없을 때에는 사용하기에 부적합하다.

이를 해결하기 위해 나온 것이 배열 리스트다.

배열 리스트는 길이를 자유롭게 줄이거나 늘릴 수 있고, 첨자가 있어서 원소에 접근하는 데에 드는 시간 복잡도가 배열과 같으며, 원소를 삽입하거나 삭제하는 데에 드는 시간 복잡도 또한 배열과 같다.

## C

C에서는 동적 배열(dynamic array)을 이용한다.

malloc을 했으면 free를 꼭 해주어야한다.
그렇지 않으면 메모리 누수가 발생할 수 있다.

```c
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
arra_listy[0] = 0;

// free를 꼭! 해주어야한다.
free(array_list);
```

## Java

Java에서는 보통 ArrayList를 사용한다.

```java
// 크기가 5인 배열 리스트
ArrayList<Integer> arrayList = new ArrayList<>(Arrays.asList(0, 0, 0, 0, 0));

// 원소에 접근하는 데에 드는 시간 복잡도는 O(1)이다.
for (int i = 0; i < 5; i++) {
    arrayList.set(i, i + 1);
}

// 원소를 삽입하는 데에 드는 시간 복잡도는 O(n)이다.
arrayList.add(0, 0);
```

## Python

Python에서는 리스트 자료구조를 기본적으로 제공한다.

```python
array_list = [0] * 5  # 크기가 5인 배열 리스트

# 원소에 접근하는 데에 드는 시간 복잡도는 O(1)이다.
for i in range(5):
    array_list[i] = i + 1

# 원소를 삽입하는 데에 드는 시간 복잡도는 O(n)이다.
array_list.insert(0, 0)
```

[velog] <https://velog.io/@ms269/%EC%9E%90%EB%A3%8C%EA%B5%AC%EC%A1%B0-%EB%B0%B0%EC%97%B4-%EB%A6%AC%EC%8A%A4%ED%8A%B8Array-List>
