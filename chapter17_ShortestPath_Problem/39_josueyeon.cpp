#include <vector>
#include <iostream>
#include <queue>
using namespace std;

int graph[125][125];
int d[125][125];

// 동 서 남 북
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

void dijkstra(int N)
{
    // 우선 순위 큐
    priority_queue<pair<int, pair<int, int>>> pq;
    
    pq.push({-graph[0][0], {0, 0}});
    d[0][0] = graph[0][0];
    
    while(!pq.empty())
    {
        // 가장 짧은 거리의 node가 나옴
        int dist = pq.top().first * -1; // 거리
        int r = pq.top().second.first;  // node
        int c = pq.top().second.second;  // node
        
        pq.pop();
        
        // 이전에 처리 된 적 있는 노드인 경우 무시: 왜냐면 거리가 짧다는 것은 이미 갱신되었다는 것이므로
        if (d[r][c] < dist)
            continue;
        
        // 연결된 node를 확인
        for(int dir = 0;dir < 4;dir++)
        {
            int tempR = r + dx[dir];
            int tempC = c + dy[dir];
            
            if (tempR < 0 || tempC < 0 || tempR >= N|| tempC >= N)
                continue;
            
            // 현재까지의 거리 + 연결된 node의 edge 가중치
            int cost = dist + graph[tempR][tempC];
            
            if (cost < d[tempR][tempC])
            {
                d[tempR][tempC] = cost;
                pq.push({cost * -1, {tempR, tempC}});
            }
        }
    }
    
}

int main()
{
    // start node 가중치, 테스트 케이스 수, 탐사 공간 크기
    int weight, T, N;
    cin>>T;

    while (T-- > 0)
    {
        cin>>N;
        
        for(int i = 0;i < N;i++)
        {
            for(int j = 0;j < N;j++)
            {
                cin>>graph[i][j];
            }
        }
        
        // 최단 거리 테이블을 무한으로 최대화
        for(int i = 0;i < N;i++)
            fill(d[i], d[i] + 125, 1e9);
        
        dijkstra(N);
        
        cout<<d[N - 1][N - 1]<<endl;
    }
    
    return 0;
}
