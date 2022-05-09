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

    public static void main(String[] args) {
        SinglyLinkedList singlyLinkedList = new SinglyLinkedList();

        for (int i = 0; i < 5; i++) {
            singlyLinkedList.insertHead(i + 1);
            System.out.println(singlyLinkedList.toString());
        }

        for (int i = 0; i < 5; i++) {
            System.out.print(singlyLinkedList.getData(i) + " ");
        }
        System.out.println();

        for (int i = 0; i < 5; i++) {
            singlyLinkedList.setData(i, i + 1);
            System.out.print(singlyLinkedList.getData(i) + " ");
        }
        System.out.println();

        for (int i = 0; i < 5; i++) {
            System.out.println(singlyLinkedList.deleteHead() + " " + singlyLinkedList.toString());
        }
    }

}
