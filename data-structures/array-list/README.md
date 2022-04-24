# 배열 리스트(Array List)

추상적 자료구조형인 리스트(list)를 배열(array)로 구현한 자료구조를 뜻한다.

리스트는 순열(sequence)이라고도 불리며, 순서를 가지고 일렬로 나열한 원소들의 모임을 뜻한다.

선형 자료구조이며, 임의 접근(random access)이 가능하다.

배열으로 구현했기 때문에, 시간 복잡도는 배열과 같다.

## 장점

- 배열과는 다르게 길이를 자유롭게 늘리거나 줄일 수 있다.
  그래서, 최대 길이를 알 수 없을 때에도 사용할 수 있다.

## C

C에서는 stdlib.h 라이브러리의 malloc을 이용한 동적 배열(dynamic array)을 사용한다.

malloc을 사용했으면 free를 **꼭!** 해줘야한다.
그렇지 않으면, 메모리 누수가 발생할 수 있다.

```c
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
```

## Java

Java에서는 보통 ArrayList를 사용한다.

```java
ArrayList<Integer> arrayList = new ArrayList<>(); // 빈 배열 리스트 선언

// 맨 뒤에 원소를 삽입하는 데에 드는 시간 복잡도는 O(1)이다.
for (int i = 0; i < 5; i++) {
    arrayList.add(i + 1);
}
// arrayList = [1, 2, 3, 4, 5]

// 원소에 접근하는 데에 드는 시간 복잡도는 O(1)이다.
System.out.println(arrayList.get(4));
// 5

// 원소를 삽입하는 데에 드는 시간 복잡도는 O(n)이다.
arrayList.add(0, 10);
// arrayList = [10, 1, 2, 3, 4, 5]

// 원소를 삭제하는 데에 드는 시간 복잡도는 O(n)이다.
arrayList.remove(0);
// arrayList = [1, 2, 3, 4, 5]
```

## Python

Python에서는 리스트 자료구조를 기본적으로 제공한다.

```python
array_list = []  # 빈 리스트 선언

# 맨 뒤에 원소를 삽입하는 데에 드는 시간 복잡도는 O(1)이다.
for i in range(5):
    array_list.append(i + 1)
# array_list = [1, 2, 3, 4, 5]

# 원소에 접근하는 데에 드는 시간 복잡도는 O(1)이다.
print(array_list[4])
# 5

# 원소를 삽입하는 데에 드는 시간 복잡도는 O(n)이다.
array_list.insert(0, 10)
# array_list = [10, 1, 2, 3, 4, 5]

# 원소를 삭제하는 데에 드는 시간 복잡도는 O(n)이다.
del array_list[0]
# array_list = [1, 2, 3, 4, 5]
```

[velog] <https://velog.io/@ms269/%EC%9E%90%EB%A3%8C%EA%B5%AC%EC%A1%B0-%EB%B0%B0%EC%97%B4-%EB%A6%AC%EC%8A%A4%ED%8A%B8Array-List>
