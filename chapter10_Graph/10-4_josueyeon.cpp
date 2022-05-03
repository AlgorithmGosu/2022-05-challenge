#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

// kruskal algorithm : 최소 비용 신장 트리 생성 알고리즘

// 부모 테이블 초기화
int parent[100001];

// 모든 간선을 담을 리스트
vector<pair<int, pair<int, int>>> edges;

int findParent(int x)
{
    return parent[x] = (x == parent[x] ? x : findParent(parent[x]));
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
    // v(node), e(edge == union 연산 횟수), result(최종 비용)
    int v, e, result = 0;
    cin>>v>>e;
    
    // 맨 처음은 모든 노드의 부모를 자기 자신으로 초기화
    for(int i = 1;i <= v;i++)
        parent[i] = i;
    
    // 간선에 대한 정보 입력
    for(int i = 0;i < e;i++)
    {
        int a, b, cost;
        cin>>a>>b>>cost;
        
        // {비용, {node1, node2}} : 정렬하기 위함
        edges.push_back({cost, {a, b}});
    }
    
    // 간선을 비용 순으로 정렬
    sort(edges.begin(), edges.end());
    
    for(int i = 0;i < edges.size();i++)
    {
        int cost = edges[i].first;
        int a = edges[i].second.first;
        int b = edges[i].second.second;
        
        // 사이클이 안생기면 union 연산을 함
        if (findParent(a) != findParent(b))
        {
            unionParent(a, b);
            result += cost;
        }
    }
    
    cout<<result<<endl;
    
    return 0;
}

