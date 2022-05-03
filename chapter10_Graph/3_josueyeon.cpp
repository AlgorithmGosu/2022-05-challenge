  #include <queue>
  #include <vector>
  #include <iostream>
  #include <algorithm>
  using namespace std;

// kruskal 알고리즘 사용
// 일단 최소 신장 트리를 생성하고 그 중에서 가장 가중치가 큰 간선을 제거해서 2개의 신장트리로 나눔

// 간선 연결 정보
vector<pair<int, pair<int, int>>> edges;

// 부모 노드 초기화
int parent[100001];

// 경로 압축
int findParent(int x)
{
    return parent[x] = (parent[x] == x ? x : findParent(parent[x]));
}

void unionParent(int a, int b)
{
    a = findParent(a);
    b = findParent(b);
    
    if (a < b)
        parent[b] = a;
    else
        parent[a] = b;
}

int main()
{
    // N(집의 개수), M(길의 개수), result(결과)
    int N, M, result = 0;
    int maxresult = 0;
    cin>>N>>M;
    
    // 간선 정보 입력받기
    for(int i = 0;i < M;i++)
    {
        int a, b, c;
        cin>>a>>b>>c;
        
        edges.push_back({c, {a, b}});
    }
    
    for(int i = 1;i <= N;i++)
        parent[i] = i;
    
    sort(edges.begin(), edges.end());
    
    for(int i = 0;i < edges.size();i++)
    {
        int cost = edges[i].first;
        int a = edges[i].second.first;
        int b = edges[i].second.second;
        
		// 사이클이 생기지 않으면 추가함
        if (findParent(a) != findParent(b))
        {
            unionParent(a, b);
            result += cost;
            maxresult = max(cost, maxresult);
        }
    }
    // 가장 값이 큰 간선을 제거함
    result -= maxresult;
    cout<<result<<endl;
    
    return 0;
    
}
