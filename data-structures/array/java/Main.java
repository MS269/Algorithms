public class Main {
    public static void main(String[] args) {
        int array1[] = new int[5]; // 길이가 5인 배열 선언
        int array2[] = { 1, 2, 3, 4, 5 }; // 배열 초기화

        // 원소에 접근하는 데에 드는 시간 복잡도는 O(1)이다.
        for (int i = 0; i < 5; i++) {
            array1[i] = i + 1;
        }
        // array1 = { 1, 2, 3, 4, 5 }

        // 원소를 삽입하는 데에 드는 시간 복잡도는 O(n)이다.
        for (int i = 4; i > 0; i--) {
            array1[i] = array1[i - 1];
        }
        array1[0] = 10;
        // array1 = { 10, 1, 2, 3, 4 }

        // 원소를 삭제하는 데에 드는 시간 복잡도는 O(n)이다.
        for (int i = 0; i < 4; i++) {
            array1[i] = array1[i + 1];
        }
        array1[4] = 0;
        // array1 = { 1, 2, 3, 4, 0 }
    }
}
