# DFS/BFS
<strong>DFS</strong>: Depth First Search <br>
<strong>BFS</strong>: Breadth First Search
 <br></br>    
  
## 🔎 필요한 자료구조 기초
### Search 
많은 양의 데이터 중에서 원하는 데이터를 찾는 과정. <br>
트리, 그래프 등의 자료구조 안에서 탐색을 하는 문제가 자주 나옴. 대표적인 탐색 알고리즘이 DFS, BFS.

------
### Stack
<strong>LIFO, Last In First Out</strong><br>
     나중에 들어온 데이터가 먼저 나감.<br>
<img src="https://user-images.githubusercontent.com/63590121/165519028-164f7c45-926b-4488-869d-377776efda90.jpeg">

* <strong> c++ stack </strong><br>
  * 헤더: ```#include <stack> ```
  * 선언: ``` stack<int> st;```
  * 메소드:
    ```
    st.push(1)  // 데이터 삽입
    st.pop()    // 데이터 삭제
    st.top()    // 최상위 데이터 반환
    st.empty()  // 비어있는지 확인
    st.size()   // 스택 사이즈 확인
    ```
* <strong> python stack </strong><br>
그냥 리스트에서 append(), pop() 하면 됨.

------
### Queue
<strong>FIFO, First In First Out</strong><br>
먼저 들어온 데이터가 먼저 나감.
<img src="https://user-images.githubusercontent.com/63590121/165520450-e25cfcd3-1a9f-4619-9548-fb2762b4c8bf.jpg">

* <strong> c++ queue </strong><br>
  * 헤더: ```#include <queue> ```
  * 선언: ``` queue<int> q;```
  * 메소드:
    ```
    q.push(1)   // 데이터 삽입
    q.pop()     // 데이터 삭제
    q.front()   // 맨 앞의 데이터 반환
    q.back()    // 맨 뒤의 데이터 반환
    q.empty()   // 비어있는지 확인
    q.size()    // 스택 사이즈 확인
    ```
* <strong> python queue </strong><br>
  * import: ``` from collections import deque ```
  * 선언: ``` queue = deque()```

------
### Graph
<strong> node + edge으로 이루어진 자료구조 </strong>
<img src="https://user-images.githubusercontent.com/63590121/165523898-ea85c083-088d-4042-9454-22cb5003fcb1.jpg">

* <strong> Adjacency Matrix 인접 행렬 </strong><br>
	* 2차원 배열로 그래프의 연결 관계 표현
	* 모든 연결 관계를 저장하므로 노드 개수가 많을수록 메모리가 낭비된다.
	* 예시:
	```
	int graph[3][3] = {
    	{0, 7, 5},
    	{7, 0, INF},
    	{5, INF, 0}
	};
	```
	
* <strong> Adjacency List 인접 리스트 </strong><br>
	* 리스트로 그래프의 연결 관계 표현
	* 연결된 정보만을 저장하기 때문에 메모리는 효율적이다.
	* 하지만 노드가 연결되어있는지 O(n) 탐색을 해야하므로 속도는 느리다.
	* 예시:	
	```
		vector<pair<int, int> > graph[3];
	
    	// 노드 0에 연결된 노드 정보 저장 {노드, 거리}
    	graph[0].push_back({1, 7});
    	graph[0].push_back({2, 5});

    	// 노드 1에 연결된 노드 정보 저장 {노드, 거리}
    	graph[1].push_back({0, 7});

    	// 노드 2에 연결된 노드 정보 저장 {노드, 거리}
    	graph[2].push_back({0, 5});
	```
<img src="https://user-images.githubusercontent.com/63590121/165523719-c7f36a0b-f2b7-48a3-b9de-0f482ab0a3d3.jpg">

## 📚 탐색 알고리즘 DFS, BFS

### DFS
<strong> Depth First Search</strong><br>
* 그래프에서 깊은 부분을 우선적으로 탐색하는 알고리즘.<br>
* 특정 경로로 탐색하다가 특정한 상황에서 최대한 깊이 들어가서 노드를 방문하고, 다시 되돌아옴.<br>
* stack 구현 또는 재귀 함수로 구현 가능
* 데이터의 개수가 N인 경우 O(N)의 시간 복잡도를 가진다.

#### 탐색 과정
1. 탐색 시작 노드를 stack에 삽입하고(push), 방문 처리를 한다.
2. 스택의 최상단 노드(top)에 방문하지 않은 인접한 노드가 있는 경우, 인접 노드를 스택에 넣고 방문 처리를 한다.<br>
방문하지 않은 인접 노드가 없는 경우 스택에서 삭제한다.(pop)
3. 2번을 모든 노드를 방문할때 까지 반복한다.

#### 예시 in c++
```
bool visited[9];	// 방문 처리를 위한 배열
vector<int> graph[9];	// 그래프

void dfs(int x) {
    // 현재 노드를 방문 처리
    visited[x] = true;
    cout << x << ' ';
    // 현재 노드 graph[x]와 연결된 다른 노드 graph[x][i] 를 재귀적으로 방문
    for (int i = 0; i < graph[x].size(); i++) {
        int y = graph[x][i];
        if (!visited[y]) dfs(y);
    }
}
```

### BFS
<strong> Breadth First Search</strong><br>
* 그래프에서 가까운 노드부터 우선적으로 탐색하는 알고리즘.<br>
* queue로 구현 가능
* 인접한 노드를 반복적으로 queue에 넣도록 구현한다.
* 데이터의 개수가 N인 경우 O(N)의 시간 복잡도를 가진다.
* 일반적인 경우 DFS보다 수행 시간이 빠름.

#### 탐색 과정
1. 탐색 시작 노드를 queue에 삽입하고(push), 방문 처리를 한다.
2. 큐에서 노드를 꺼내서(pop) 해당 노드와 인접한 노드 중 방문하지 않은 노드를 모두 큐에 삽입하고(push) 방문 처리를 한다.<br>
3. 2번을 queue가 비어있을 때까지(empty) 반복한다.

#### 예시 in c++
```
bool visited[9];	// 방문 처리를 위한 배열
vector<int> graph[9];	// 그래프

void bfs(int start) {
    queue<int> q;
    q.push(start);
    // 현재 노드를 방문 처리
    visited[start] = true;
    // 큐가 빌 때까지 반복
    while(!q.empty()) {
    	// 큐에서 하나의 원소를 뽑아 출력
        int x = q.front();
        q.pop();
        cout << x << ' ';
        // 해당 원소와 연결된, 아직 방문하지 않은 원소들을 큐에 삽입
        for(int i = 0; i < graph[x].size(); i++) {
            int y = graph[x][i];
            if(!visited[y]) {
                q.push(y);
                visited[y] = true;
            }
        }
    }
}
```




