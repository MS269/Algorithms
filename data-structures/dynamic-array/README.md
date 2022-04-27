# 동적 배열(Dynamic Array)

메모리가 동적(dynamic)으로 할당되는 배열(array)이다.

배열은 정적(static)으로 메모리를 할당해서 크기(capacity)를 늘리거나 줄일 수 없는데, 이 문제를 해결하기 위해서 동적 배열을 사용한다.

## C

C에서는 stdlib.h 라이브러리를 이용한다.

malloc을 사용했으면 free를 **꼭!** 해줘야한다.
그렇지 않으면, 메모리 누수가 발생할 수 있다.

```c
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
```

## Java

Java에서는 보통 ArrayList를 사용한다.

아래 코드는 Arrays 라이브러리를 이용해서 구현한 것이다.

```java
private static final int DEFAULT_CAPACITY = 1 << 4;

private int[] dynamicArray;
private int size;
private int capacity;

public DynamicArray(final int capacity) {
    this.dynamicArray = new int[capacity];
    this.size = 0;
    this.capacity = capacity;
}

public DynamicArray() {
    this(DEFAULT_CAPACITY);
}

// 맨 뒤에 원소를 삽입하는 데에 드는 시간 복잡도는 O(1)이다.
public void add(final int value) {
    if (this.size >= this.capacity) {
        this.dynamicArray = Arrays.copyOf(this.dynamicArray, newCapacity(this.capacity << 1));
    }

    this.dynamicArray[this.size] = value;
    this.size++;
}

// 원소에 접근하는 데에 드는 시간 복잡도는 O(1)이다.
public void set(final int index, int value) {
    if (index >= this.size) {
        return;
    }

    this.dynamicArray[index] = value;
}

// 임의의 인덱스에 원소를 삽입하는 데에 드는 시간 복잡도는 O(n)이다.
public void insert(final int index, int value) {
    if (index >= this.size) {
        return;
    }

    if (this.size >= this.capacity) {
        this.dynamicArray = Arrays.copyOf(this.dynamicArray, newCapacity(this.capacity << 1));
    }

    for (int i = this.size; i > index; i--) {
        this.dynamicArray[i] = dynamicArray[i - 1];
    }

    dynamicArray[index] = value;
    this.size++;
}

// 임의의 인덱스의 원소를 삭제하는 데에 드는 시간 복잡도는 O(n)이다.
public void delete(final int index) {
    if (index >= this.size) {
        return;
    }

    for (int i = index; i < this.size; i++) {
        this.dynamicArray[i] = this.dynamicArray[i + 1];
    }

    this.dynamicArray[this.size - 1] = 0;
    this.size--;

    if (this.capacity > DEFAULT_CAPACITY && this.size << 2 <= this.capacity) {
        this.dynamicArray = Arrays.copyOf(this.dynamicArray, newCapacity(this.capacity >> 1));
    }
}

private int newCapacity(final int capacity) {
    this.capacity = capacity;
    return capacity;
}
```

## Python

Python에서는 리스트(list) 자료구조를 사용한다.

```python
array1 = []  # 빈 리스트 선언
array2 = [1, 2, 3, 4, 5]  # 리스트 초기화

# 원소를 맨 뒤에 삽입하는 데에 드는 시간 복잡도는 O(1)이다.
for i in range(5):
    array1.append(0)
# array1 = [0, 0, 0, 0, 0]

# 임의의 인덱스로 원소에 접근하는 데에 드는 시간 복잡도는 O(1)이다.
for i in range(5):
    array1[i] = i + 1
# array1 = [1, 2, 3, 4, 5]

# 임의의 인덱스에 원소를 삽입하는 데에 드는 시간 복잡도는 O(n)이다.
array1.insert(0, 10)
# array1 = [10, 1, 2, 3, 4 , 5]

# 임의의 인덱스의 원소를 삭제하는 데에 드는 시간 복잡도는 O(n)이다.
del array1[0]
# array1 = [1, 2, 3, 4, 5]
```

[velog] <https://velog.io/@ms269/%EC%9E%90%EB%A3%8C%EA%B5%AC%EC%A1%B0-%EB%8F%99%EC%A0%81-%EB%B0%B0%EC%97%B4Dynamic-Array>
