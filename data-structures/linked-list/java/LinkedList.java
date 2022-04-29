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

    public static void main(String[] args) {
        LinkedList linkedList = new LinkedList();

        for (int i = 0; i < 5; i++) {
            linkedList.insertHead(i + 1);
        }
        // 5 -> 4 -> 3 -> 2 -> 1 -> NULL

        linkedList.insertHead(10);
        // 10 -> 5 -> 4 -> 3 -> 2 -> 1 -> NULL

        linkedList.deleteHead();
        // 5 -> 4 -> 3 -> 2 -> 1 -> NULL

        linkedList.print();
        // 5 4 3 2 1
    }

}
