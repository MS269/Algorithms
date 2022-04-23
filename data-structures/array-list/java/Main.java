import java.util.ArrayList;
import java.util.Arrays;

public class Main {
    public static void main(String[] args) {
        // 크기가 5인 배열 리스트
        ArrayList<Integer> arrayList = new ArrayList<>(Arrays.asList(0, 0, 0, 0, 0));

        // 원소에 접근하는 데에 드는 시간 복잡도는 O(1)이다.
        for (int i = 0; i < 5; i++) {
            arrayList.set(i, i + 1);
        }

        // 원소를 삽입하는 데에 드는 시간 복잡도는 O(n)이다.
        arrayList.add(0, 0);
    }
}