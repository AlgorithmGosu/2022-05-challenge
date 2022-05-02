#include <queue>
#include <vector>
#include <iostream>
using namespace std;

// 개선된 다익스트라 알고리즘: 우선순위 큐

// N(no. of node), M(no. of edge), start(시작 node)
int N, M, start;

// node에 연결된 node 정보를 저장
vector<pair<int, int>> graph[100001];

// 최단 거리 1차원 테이블
int d[100001];

void dijkstra(int start)
{
    // 우선 순위 큐
    priority_queue<pair<int, int>> pq;
    
    pq.push({0, start});
    d[start] = 0;
    
    while(!pq.empty())
    {
        // 가장 짧은 거리의 node가 나옴
        int dist = pq.top().first * -1; // 거리
        int now = pq.top().second;      // node
        
        pq.pop();
        
        // 이전에 처리 된 적 있는 노드인 경우 무시: 왜냐면 거리가 짧다는 것은 이미 갱신되었다는 것이므로
        if (d[now] < dist)
            continue;
        
        // 연결된 node를 확인
        for(int i = 0;i < graph[now].size();i++)
        {
            // 현재까지의 거리 + 연결된 node의 edge 가중치
            int cost = dist + graph[now][i].second;
            
            if (cost < d[graph[now][i].first])
            {
                d[graph[now][i].first] = cost;
                pq.push({cost * -1, graph[now][i].first});
            }
        }
    }
    
}

int main()
{
    cin>>N>>M>>start;
    
    for(int i = 0;i < M;i++)
    {
        // a(node), b(연결된 node), c(edge)
        int a, b, c;
        cin>>a>>b>>c;
        
        //a에서 b로 가는 길은 연결되어 있고, weight는 c
        graph[a].push_back({b, c});
    }
    
    fill_n(d, 100001, 1e9);
    
    dijkstra(start);
    
    for(int i = 1;i <= N;i++)
    {
        // 갈 수 없는 경우
        if (d[i] == 1e9)
            cout<<"INFINITY"<<endl;
        
        else
            cout<<d[i]<<endl;
    }
    
    return 0;
}

