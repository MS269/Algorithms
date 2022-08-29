# Graph(그래프)

정점(Vertex, Node)과 간선(Edge)의 집합

- cf) 트리는 사이클이 허용되지 않는 그래프이다.

## 용어

- Undirected Graph(무방향 그래프): 방향이 없는 그래프

  - Degree(차수): 정점에 연결된 간선의 개수

- Directed Graph(방향 그래프, Digraph): 방향성이 있는 그래프

  - Indegree: 정점으로 들어오는 간선의 개수
  - OutDegree: 정점에서 나가는 간선의 개수

- Complete Graph(완전 그래프): 최대 간선 수를 가진 그래프

  - 무방향 그래프에서는 N(N-1)/2개
  - 방향 그래프에서는 N(N-1)개

- Sub Graph(부분 그래프): 원래 그래프의 부분 그래프

- Weight Graph(가중치 그래프, Network): 간선에 가중치가 있는 그래프

## 구현

### Adjacent Matrix(인접 행렬): 정방 행렬을 사용하는 방법

- Time Complexity(두 정점의 연결 관계): O(1)
- Space Complexity: O(V²)
- Dense Graph(밀집 그래프)를 표현할 때 효과적이다.

### Adjacent List(인접 리스트): 연결 리스트를 사용하는 방법

- Time Complexity(두 정점의 연결 관계): 최악의 경우에 O(V)
- Space Complexity: O(E+V)
- Sparse Graph(희소 그래프)를 표현할 때 효과적이다.
