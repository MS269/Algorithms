array_list = []  # 빈 리스트 선언

# 맨 뒤에 원소를 삽입하는 데에 드는 시간 복잡도는 O(1)이다.
for i in range(5):
    array_list.append(i + 1)
# array_list = [1, 2, 3, 4, 5]

# 원소에 접근하는 데에 드는 시간 복잡도는 O(1)이다.
print(array_list[4])
# 5

# 원소를 삽입하는 데에 드는 시간 복잡도는 O(n)이다.
array_list.insert(0, 10)
# array_list = [10, 1, 2, 3, 4, 5]

# 원소를 삭제하는 데에 드는 시간 복잡도는 O(n)이다.
del array_list[0]
# array_list = [1, 2, 3, 4, 5]
