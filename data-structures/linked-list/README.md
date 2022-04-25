# 연결 리스트(Linked List)

추상적 자료형인 리스트(list)를 구현한 자료구조로, 자료를 포인터(pointer)로 연결해 저장한다.

자료를 저장할 때, 자료와 다음 자료의 메모리 주소를 함께 저장하며, 이 묶음을 노드(node)라고 부른다.

선형 자료구조이며, 임의 접근(random access)이 불가능하다.

## 장점

- 배열(array)과는 다르게 길이를 자유롭게 늘리거나 줄일 수 있다.
  그래서, 최대 길이를 알 수 없을 때에도 사용할 수 있다.

- 자료의 삽입과 삭제를 배열에 비해 빠르게 한다.
  예를 들어, 배열은 맨 앞에 자료의 삽입과 삭제에 시간 복잡도 O(n)이 드는 반면에, 연결 리스트는 O(1)이 든다.
  하지만, 첫번째가 아닌 자료의 삽입과 삭제는 해당 자료를 검색하는 데에 시간이 들어 시간 복잡도 O(n)이 든다.

## 단점

- 배열과는 다르게 첨자(index)가 없어 임의 접근이 불가능하여, 첫번째 노드부터 순차적으로 접근해야하는데, 이 때 드는 시간 복잡도는 O(n)이다.

- 다음 자료의 메모리 주소도 함께 저장하기 때문에, 메모리를 더 많이 사용한다.

## C

연결 리스트 중 단순 연결 리스트(singly linked list)를 구현했다.

맨 앞에 원소 삽입과 삭제에 시간 복잡도가 O(1)이다.

맨 뒤의 노드 포인터도(tail)도 사용한다면, 맨 앞에 원소 삽입과 맨 뒤의 원소 삭제에 시간 복잡도가 O(1)이라서, 큐(queue) 구현에 적합하다.

```c
struct Node {
  int data;
  struct Node *next;
};

struct Node *head = NULL;

// 맨 앞에 노드를 삽입하는 데에 드는 시간 복잡도는 O(1)이다.
void insert_head(int value) {
  struct Node *new = (struct Node *)malloc(sizeof(struct Node));
  new->data = value;
  new->next = NULL;

  if (head == NULL) {
    head = new;
  } else {
    new->next = head;
    head = new;
  }
}

// 맨 앞의 노드를 삭제하는 데에 드는 시간 복잡도는 O(1)이다.
void delete_head() {
  if (head != NULL) {
    struct Node *temp = head;
    head = head->next;
    free(temp);
  }
}

// 노드에 접근하는 데에 드는 시간 복잡도는 O(n)이다.
void print() {
  struct Node *now = head;

  while (now != NULL) {
    printf("%d ", now->data);
    now = now->next;
  }
  printf("\n");
}
```

## Java

Java에서는 linkedList를 사용한다.

```java
LinkedList<Integer> linkedList = new LinkedList<>();

// 맨 뒤에 노드를 삽입하는 데에 드는 시간 복잡도는 O(1)이다.
for (int i = 0; i < 5; i++) {
    linkedList.add(i + 1);
}
// linkedList = [1, 2, 3, 4, 5]

// 맨 앞에 노드를 삽입하는 데에 드는 시간 복잡도는 O(1)이다.
linkedList.add(0, 10);
// linkedList = [10, 1, 2, 3, 4, 5]

// 맨 앞이나 맨 뒤의 노드를 삭제하는 데에 드는 시간 복잡도는 O(1)이다.
linkedList.remove();
// linkedList = [1, 2, 3, 4, 5]

// 노드에 접근하는 데에 드는 시간 복잡도는 O(n)이다.
System.out.println(linkedList.get(4));
// 5
```

## Python

연결 리스트 중 단순 연결 리스트(singly linked list)를 구현했다.

```python
class Node:
    def __init__(self, data):
        self.data = data
        self.next = None


class LinkedList:
    def __init__(self):
        self.head = None

    # 노드에 접근하는 데에 드는 시간 복잡도는 O(n)이다.
    def __iter__(self):
        now = self.head

        while now:
            yield now.data
            now = now.next

    # 맨 앞에 노드를 삽입하는 데에 드는 시간 복잡도는 O(1)이다.
    def insert_head(self, value):
        new = Node(value)

        if self.head == None:
            self.head = new
        else:
            new.next = self.head
            self.head = new

    # 맨 앞의 노드를 삭제하는 데에 드는 시간 복잡도는 O(1)이다.
    def delete_head(self):
        self.head = self.head.next
```

[velog] <https://velog.io/@ms269/%EC%9E%90%EB%A3%8C%EA%B5%AC%EC%A1%B0-%EC%97%B0%EA%B2%B0-%EB%A6%AC%EC%8A%A4%ED%8A%B8Linked-List>
