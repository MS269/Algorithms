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


def main():
    singly_linked_list = SinglyLinkedList()

    for i in range(5):
        singly_linked_list.insert_head(i + 1)
        print(singly_linked_list)

    for i in range(5):
        print(singly_linked_list[i], end=" ")
    print()

    for i in range(5):
        singly_linked_list[i] = i + 1
        print(singly_linked_list[i], end=" ")
    print()

    for i in range(5):
        print(singly_linked_list.delete_head(), singly_linked_list)


if __name__ == "__main__":
    main()
