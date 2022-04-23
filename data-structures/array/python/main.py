array1 = [0] * 5  # 크기가 5인 배열 선언
array2 = [1, 2, 3, 4, 5]  # 배열 초기화

# 원소에 접근하는 데에 드는 시간 복잡도는 O(1)이다.
print(array2[2])

# 원소를 삭제하는 데에 드는 시간 복잡도는 O(n)이다.
del array2[0]
