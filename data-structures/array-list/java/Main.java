import java.util.ArrayList;

public class Main {
    public static void main(String[] args) {
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
    }
}
