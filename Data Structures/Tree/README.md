# Tree

Node와 Edge로 이루어져있다.

비선형 구조이며, 계층적 관계를 표현한다.

노드의 개수가 N개면, 간선은 N-1개를 가진다.

사이클이 존재할 수 없다(만약 사이클이 존재한다면 그래프이다).

루트에서 한 노드로 가는 경로는 유일한 경로 뿐이다.

## 용어

- Node(노드): 트리를 구성하는 기본 원소
- Edge(간선): 트리를 구성하기 위해 노드를 연결하는 선
- Root Node(루트 노드): 최상위 노드
- Parent Node(부모 노드): 루트 노드 방향으로 연결된 노드
- Child Node(자식 노드): 루트 노드 반대 방향으로 연결된 노드
- Siblings Node(형제 노드): 같은 부모 노드를 갖는 노드
- Leaf Node(리프 노드, 단말 노드): 자식이 없는 노드

## Tree Traversal(트리 순회)

DFT(Depth-First Traversal, 깊이 우선 순회) 세가지가 있다.

### Pre-order Traversal(전위 순회), NLR

각 루트를 순차적으로 먼저 방문하는 방식

루트 > 왼쪽 > 오른쪽

1 > 2 > 4 > 5 > 3

### In-order Traversal(중위 순회), LNR

왼쪽 하위 트리를 방문 후 루트를 방문하는 방식

왼쪽 > 루트 > 오른쪽

4 > 2 > 5 > 1 > 3

### Post-order Traversal(후위 순회), LRN

왼쪽 하위 트리부터 하위를 모두 방문 후 루트를 방문하는 방식

왼쪽 > 오른쪽 > 루트

4 > 5 > 2 > 3 > 1

## Binary Tree(이진 트리)

루트 노드를 중심으로 두개의 서브 트리로 나뉘어 진다.

- Full Binary Tree(정 이진 트리): 모든 노드가 0개 또는 2개의 자식 노드를 갖는 이진 트리
- Perfect Binary Tree(포화 이진 트리): 모든 내부 노드가 2개의 자식 노드를 가지며 모든 리프 노드가 동일한 높이를 갖는 이진 트리
- Complete Binary Tree(완전 이진 트리): 왼쪽에서 오른쪽으로 순서대로 채워진 이진 트리

## BST(Binary Search Tree)