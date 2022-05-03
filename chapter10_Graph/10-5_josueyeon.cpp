#include <queue>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

// 모든 노드에 대한 진입 차수를 0으로 초기화
int indegree[100001];

// 각 노드에 연결된 간선 정보를 담기 위한 연결 리스트
vector<int> graph[100001];

// 위상 정렬
void topologySort(int v)
{
    vector<int> result; // 알고리즘 수행 결과 -> 정렬 순서
    queue<int> q;
    
    for(int i = 1;i <= v;i++)
    {
        // 진입 차수가 0이면 queue에 넣음
        if (indegree[i] == 0)
            q.push(i);
    }
    
    while (!q.empty())
    {
        int now = q.front();
        q.pop();
        
        result.push_back(now);
        
        for(int i = 0;i < graph[now].size();i++)
        {
            // 해당 원소와 연결된 노드들의 진입차수를 1 빼기
            indegree[graph[now][i]] -= 1;
            
            // 새롭게 진입 차수가 0이 되는 노드들을 큐에 넣기
            if (indegree[graph[now][i]] == 0)
                q.push(graph[now][i]);
        }
    }
    
    for(int i = 0;i < result.size();i++)
        cout<<result[i]<<" ";
    cout<<endl;
}
int main()
{
    // v(node), e(edge)
    int v, e;
    cin>>v>>e;
    
    // 연결된 간선 정보 입력받기
    for(int i = 0;i < e;i++)
    {
        int a, b;
        cin>>a>>b;
        
        graph[a].push_back(b);
        // 진입 차수 증가시키기
        indegree[b] += 1;
    }
    topologySort(v);
    
    return 0;
}

