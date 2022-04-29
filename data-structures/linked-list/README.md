# 연결 리스트(Linked List)

추상적 자료형인 리스트(list)를 구현한 자료구조로, 데이터를 포인터(pointer)로 연결해 저장한다.

데이터를 저장할 때, 데이터와 다음 데이터의 메모리 주소를 함께 저장하며, 이 묶음을 노드(node)라고 부른다.

보통 트리(tree)를 구현하기 위해서 사용한다.

## 특징

- 선형 자료구조이다.
  (= 자료가 앞뒤로 1:1로 선형이다.)
- 임의 접근(random access)이 불가능하다.
  - 임의의 노드에 접근하는 데에 드는 시간 복잡도가 O(n)이다.

## 장점

- 맨 앞이나 뒤에 노드의 삽입과 삭제에 드는 시간 복잡도는 O(1)이다.
- 크기(capacity)를 늘리거나 줄이는 것이 가능하다.

## 단점

- 데이터를 검색하는 데에 드는 시간 복잡도는 O(n)이다.
- 중간에 노드의 삽입과 삭제에 드는 시간 복잡도는 O(n)이다.
  (삽입이나 삭제할 위치를 검색하는 데에 드는 시간이다.)
- 다음 데이터의 메모리 주소도 함께 저장하기 때문에, 메모리를 더 많이 사용한다.

## 단순 연결 리스트(Singly Liked List)

맨 앞에 노드의 삽입과 삭제에 드는 시간 복잡도가 O(1)이다.

### C

```c
struct Node {
  int data;
  struct Node *next;
};

struct Node *head = NULL;

// 맨 앞에 노드를 삽입하는 데에 드는 시간 복잡도는 O(1)이다.
void insert_head(const int value) {
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

### Java

Java에서는 LinkedList를 제공한다.

```java
class Node {

    int data;
    Node next;

    Node() {
    }

    Node(final int value) {
        this(value, null);
    }

    Node(final int value, final Node next) {
        this.data = value;
        this.next = next;
    }

}

public class LinkedList extends Node {

    private Node head;

    public LinkedList() {
        head = null;
    }

    public LinkedList(final Node head) {
        this.head = head;
    }

    // 맨 앞에 노드를 삽입하는 데에 드는 시간 복잡도는 O(1)이다.
    public void insertHead(final int value) {
        Node newNode = new Node(value);

        if (head == null) {
            head = newNode;
        } else {
            newNode.next = this.head;
            this.head = newNode;
        }
    }

    // 맨 앞의 노드를 삭제하는 데에 드는 시간 복잡도는 O(1)이다.
    public void deleteHead() {
        if (head != null) {
            this.head = this.head.next;
        }
    }

    // 노드에 접근하는 데에 드는 시간 복잡도는 O(n)이다.
    public void print() {
        Node now = head;

        while (now != null) {
            System.out.print(now.data + " ");
            now = now.next;
        }
        System.out.println();
    }

}
```

## Python

```py
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
