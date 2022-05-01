import java.util.Arrays;

public class DynamicArray {

    private static final int DEFAULT_CAPACITY = 1 << 4;

    private int[] dynamicArray;
    private int size;
    private int capacity;

    public DynamicArray() {
        this(DEFAULT_CAPACITY);
    }

    public DynamicArray(final int capacity) {
        this.dynamicArray = new int[capacity];
        this.size = 0;
        this.capacity = capacity;
    }

    // 맨 뒤에 원소를 삽입하는 데에 드는 시간 복잡도는 O(1)이다.
    public void add(final int value) {
        if (this.size >= this.capacity) {
            this.dynamicArray = Arrays.copyOf(this.dynamicArray, newCapacity(this.capacity << 1));
        }

        this.dynamicArray[this.size] = value;
        this.size++;
    }

    // 원소에 접근하는 데에 드는 시간 복잡도는 O(1)이다.
    public void set(final int index, int value) {
        if (index >= this.size) {
            return;
        }

        this.dynamicArray[index] = value;
    }

    // 임의의 인덱스에 원소를 삽입하는 데에 드는 시간 복잡도는 O(n)이다.
    public void insert(final int index, int value) {
        if (index >= this.size) {
            return;
        }

        if (this.size >= this.capacity) {
            this.dynamicArray = Arrays.copyOf(this.dynamicArray, newCapacity(this.capacity << 1));
        }

        for (int i = this.size; i > index; i--) {
            this.dynamicArray[i] = dynamicArray[i - 1];
        }

        dynamicArray[index] = value;
        this.size++;
    }

    // 임의의 인덱스의 원소를 삭제하는 데에 드는 시간 복잡도는 O(n)이다.
    public void delete(final int index) {
        if (index >= this.size) {
            return;
        }

        for (int i = index; i < this.size; i++) {
            this.dynamicArray[i] = this.dynamicArray[i + 1];
        }

        this.dynamicArray[this.size - 1] = 0;
        this.size--;

        if (this.capacity > DEFAULT_CAPACITY && this.size << 2 <= this.capacity) {
            this.dynamicArray = Arrays.copyOf(this.dynamicArray, newCapacity(this.capacity >> 1));
        }
    }

    public void print() {
        for (int i = 0; i < this.size; i++) {
            System.out.print(this.dynamicArray[i] + " ");
        }
        System.out.println();
    }

    private int newCapacity(final int capacity) {
        this.capacity = capacity;
        return capacity;
    }

    public static void main(String[] args) {
        DynamicArray dynamicArray = new DynamicArray();

        for (int i = 0; i < 5; i++) {
            dynamicArray.add(0);
        }
        dynamicArray.print();

        for (int i = 0; i < 5; i++) {
            dynamicArray.set(i, i + 1);
        }
        dynamicArray.print();

        dynamicArray.insert(0, 10);
        dynamicArray.print();

        dynamicArray.delete(0);
        dynamicArray.print();
    }

}
