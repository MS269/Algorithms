public class Main {
    public static void main(String[] args) {
        int array1[] = new int[5]; // 크기가 5인 배열 선언
        int array2[] = { 1, 2, 3, 4, 5 }; // 배열 초기화

        // 원소에 접근하는 데에 드는 시간 복잡도는 O(1)이다.
        System.out.println(array2[2]);

        // 원소를 삭제하는 데에 드는 시간 복잡도는 O(n)이다.
        for (int i = 0; i < 4; i++) {
            array2[i] = array2[i + 1];
        }
        array2[4] = 0;
    }
}
