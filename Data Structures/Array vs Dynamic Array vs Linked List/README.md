# Array vs Dynamic Array vs Linked List

## Array(배열)

논리적 저장 순서와 물리적 저장 순서가 일치한다.

따라서 인덱스(index)로 해당 원소(element)에 접근할 수 있다.

찾고자 하는 인덱스를 알고 있다면 O(1)의 시간 복잡도로 해당 원소에 접근할 수 있다.

즉 random access가 가능하다.

삭제 또는 삽입의 과정에서 해당 원소에 접근하여 작업을 완료한 뒤(O(1)), 빈 공간이 생기므로 shift 해줘야하는 비용이 발생한다(O(n)).

## Dynamic Array(동적 배열)

## Linked List(연결 리스트)
