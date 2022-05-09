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
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
  int data;
  struct Node *next;
} node_t;

typedef struct SinglyLinkedList {
  node_t *head;
  int size;
} singly_linked_list_t;

node_t *create_node(int data) {
  node_t *new_node = (node_t *)malloc(sizeof(node_t));
  new_node->data = data;
  new_node->next = NULL;
  return new_node;
}

singly_linked_list_t *init() {
  singly_linked_list_t *singly_linked_list =
      (singly_linked_list_t *)malloc(sizeof(singly_linked_list_t *));
  singly_linked_list->head = NULL;
  singly_linked_list->size = 0;
  return singly_linked_list;
}

// O(n)
int getData(singly_linked_list_t *self, int index) {
  assert(index >= 0 && index < self->size);
  node_t *temp = self->head;
  for (int i = 0; i < index; i++) {
    temp = temp->next;
  }
  return temp->data;
}

// O(n)
void setData(singly_linked_list_t *self, int index, int data) {
  assert(index >= 0 && index < self->size);
  node_t *temp = self->head;
  for (int i = 0; i < index; i++) {
    temp = temp->next;
  }
  temp->data = data;
}

// O(n)
void insert_nth(singly_linked_list_t *self, int index, int data) {
  assert(index >= 0 && index <= (self->size)++);
  node_t *new_node = create_node(data);
  if (self->head == NULL) {
    self->head = new_node;
  } else if (index == 0) {
    new_node->next = self->head;
    self->head = new_node;
  } else {
    node_t *temp = self->head;
    for (int i = 0; i < index - 1; i++) {
      temp = temp->next;
    }
    new_node->next = temp->next;
    temp->next = new_node;
  }
}

// O(1)
void insert_head(singly_linked_list_t *self, int data) {
  insert_nth(self, 0, data);
}

// O(n)
void insert_tail(singly_linked_list_t *self, int data) {
  insert_nth(self, self->size, data);
}

// O(n)
int delete_nth(singly_linked_list_t *self, int index) {
  assert(index >= 0 && index <= (self->size)-- - 1);
  node_t *delete_node = self->head;
  if (index == 0) {
    self->head = self->head->next;
  } else {
    node_t *temp = self->head;
    for (int i = 0; i < index - 1; i++) {
      temp = temp->next;
    }
    delete_node = temp->next;
    temp->next = temp->next->next;
  }
  int data = delete_node->data;
  free(delete_node);
  return data;
}

// O(1)
int delete_head(singly_linked_list_t *self) { return delete_nth(self, 0); }

// O(n)
int delete_tail(singly_linked_list_t *self) {
  return delete_nth(self, self->size - 1);
}

// O(n)
void print(singly_linked_list_t *self) {
  node_t *temp = self->head;
  while (temp != NULL) {
    printf("%d", temp->data);
    temp = temp->next;
    printf(temp != NULL ? "->" : "\n");
  }
}
```

### Java

```java
import java.util.StringJoiner;

class Node {

    int data;
    Node next;

    Node() {
    }

    Node(int data) {
        this(data, null);
    }

    Node(int data, Node next) {
        this.data = data;
        this.next = next;
    }

}

public class SinglyLinkedList extends Node {

    private Node head;
    private int size;

    public SinglyLinkedList() {
        head = null;
        size = 0;
    }

    public SinglyLinkedList(Node head, int size) {
        this.head = head;
        this.size = size;
    }

    public int size() {
        return size;
    }

    // O(n)
    public int getData(int index) {
        assert index >= 0 && index < size;
        Node temp = head;
        for (int i = 0; i < index; i++) {
            temp = temp.next;
        }
        return temp.data;
    }

    // O(n)
    public void setData(int index, int data) {
        assert index >= 0 && index < size;
        Node temp = head;
        for (int i = 0; i < index; i++) {
            temp = temp.next;
        }
        temp.data = data;
    }

    // O(n)
    public void insertNth(int index, int data) {
        assert index >= 0 && index <= size++;
        Node newNode = new Node(data);
        if (head == null) {
            head = newNode;
        } else if (index == 0) {
            newNode.next = head;
            head = newNode;
        } else {
            Node temp = head;
            for (int i = 0; i < index - 1; i++) {
                temp = temp.next;
            }
            newNode.next = temp.next;
            temp.next = newNode;
        }
    }

    // O(1)
    public void insertHead(int data) {
        insertNth(0, data);
    }

    // O(n)
    public void insertTail(int data) {
        insertNth(size, data);
    }

    // O(n)
    public int deleteNth(int index) {
        assert index >= 0 && index <= size-- - 1;
        Node deleteNode = head;
        if (index == 0) {
            head = head.next;
        } else {
            Node temp = head;
            for (int i = 0; i < index - 1; i++) {
                temp = temp.next;
            }
            deleteNode = temp.next;
            temp.next = temp.next.next;
        }
        int data = deleteNode.data;
        deleteNode = null;
        return data;
    }

    // O(1)
    public int deleteHead() {
        return deleteNth(0);
    }

    // O(n)
    public int deleteTail() {
        return deleteNth(size - 1);
    }

    // O(n)
    @Override
    public String toString() {
        StringJoiner joiner = new StringJoiner("->");
        Node temp = head;
        while (temp != null) {
            joiner.add(temp.data + "");
            temp = temp.next;
        }
        return joiner.toString();
    }

}
```

### Python

```py
from typing import Any


class Node:
    def __init__(self, data: Any):
        self.data: Any = data
        self.next: Node = None

    def __repr__(self) -> str:
        return f"Node({self.data})"


class SinglyLinkedList:
    def __init__(self):
        self.head: Node = None

    # O(n)
    def __iter__(self) -> Any:
        temp = self.head
        while temp:
            yield temp.data
            temp = temp.next

    # O(n)
    def __len__(self) -> int:
        return(len(tuple(iter(self))))

    # O(n)
    def __repr__(self) -> str:
        return "->".join([str(item) for item in self])

    # O(n)
    def __getitem__(self, index: int) -> Any:
        assert 0 <= index < len(self), "index out of range"
        for i, node in enumerate(self):
            if i == index:
                return node

    # O(n)
    def __setitem__(self, index: int, data: Any) -> None:
        assert 0 <= index < len(self), "index out of range"
        temp = self.head
        for _ in range(index):
            temp = temp.next
        temp.data = data

    # O(n)
    def insert_nth(self, index: int, data: Any) -> None:
        assert 0 <= index <= len(self), "index out of range"
        new_node = Node(data)
        if self.head == None:
            self.head = new_node
        elif index == 0:
            new_node.next = self.head
            self.head = new_node
        else:
            temp = self.head
            for _ in range(index - 1):
                temp = temp.next
            new_node.next = temp.next
            temp.next = new_node

    # O(1)
    def insert_head(self, data: Any) -> None:
        self.insert_nth(0, data)

    # O(n)
    def insert_tail(self, data: Any) -> None:
        self.insert_nth(len(self), data)

    # O(n)
    def delete_nth(self, index: int) -> Any:
        assert 0 <= index <= len(self) - 1, "index out of range"
        delete_node = self.head
        if index == 0:
            self.head = self.head.next
        else:
            temp = self.head
            for _ in range(index - 1):
                temp = temp.next
            delete_node = temp.next
            temp.next = temp.next.next
        return delete_node.data

    # O(1)
    def delete_head(self) -> Any:
        return self.delete_nth(0)

    # O(n)
    def delete_tail(self) -> Any:
        return self.delete_nth(len(self) - 1)
```

[velog] <https://velog.io/@ms269/%EC%9E%90%EB%A3%8C%EA%B5%AC%EC%A1%B0-%EC%97%B0%EA%B2%B0-%EB%A6%AC%EC%8A%A4%ED%8A%B8Linked-List>
