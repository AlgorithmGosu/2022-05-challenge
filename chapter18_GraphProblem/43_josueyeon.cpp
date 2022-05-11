// 아이디어: 가로등의 간선이 제일 낮은 MST를 만들면 됨 -> kruskal algorithm

#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

// 부모 노드 테이블
int parent[200001];

int findParent(int a)
{
    return (parent[a] == a ? a : parent[a] = findParent(parent[a]));
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
    // N(집), M(도로)
    int N, M;
    cin>>N>>M;
    
    // 부모 노드를 자기 자신으로 초기화
    for(int i = 0;i < N;i++)
        parent[i] = i;
    
    vector<pair<int, pair<int ,int>>> v;
    
    // 총 비용
    int sum = 0;
    
    for(int i = 0;i < M;i++)
    {
        int x, y, z;
        cin>>x>>y>>z;
        
        v.push_back({z, {x, y}});
        sum += z;
    }
    
    sort(v.begin(), v.end());
    
    // 최소로 드는 비용
    int result = 0;
    for(int i = 0;i < v.size();i++)
    {
        int cost = v[i].first;
        int x = v[i].second.first;
        int y = v[i].second.second;
        
        if (findParent(x) != findParent(y))
        {
            result += cost;
            unionParent(x, y);
        }
    }
    cout<<sum - result<<endl;
    
    return 0;
}

