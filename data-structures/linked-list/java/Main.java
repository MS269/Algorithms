import java.util.LinkedList;

public class Main {
    public static void main(String[] args) {
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
    }
}
