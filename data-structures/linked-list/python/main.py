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


linked_list = LinkedList()

for i in range(5):
    linked_list.insert_head(i + 1)
# 5 -> 4 -> 3 -> 2 -> 1 -> None

linked_list.insert_head(10)
# 10 -> 5 -> 4 -> 3 -> 2 -> 1 -> None

linked_list.delete_head()
# 5 -> 4 -> 3 -> 2 -> 1 -> None

print(*linked_list)
# 5 4 3 2 1
