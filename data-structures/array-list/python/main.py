array_list = [0] * 5  # 크기가 5인 배열 리스트

# 원소에 접근하는 데에 드는 시간 복잡도는 O(1)이다.
for i in range(5):
    array_list[i] = i + 1

# 원소를 삽입하는 데에 드는 시간 복잡도는 O(n)이다.
array_list.insert(0, 0)
