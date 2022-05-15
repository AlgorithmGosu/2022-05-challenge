#include <vector>
#include <iostream>
#include <queue>
using namespace std;

vector<pair<int, int>> graph[20001];
int d[20001];

void dijkstra()
{
    // {거리, 노드}
    priority_queue<pair<int, int>> pq;
    
    pq.push({0, 1});
    d[1] = 0;
    
    while (!pq.empty())
    {
        int dist = pq.top().first * -1;
        int now = pq.top().second;
        
        pq.pop();
        
        if (d[now] < dist)
            continue;
        
        for(int i = 0;i < graph[now].size();i++)
        {
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
    // N(헛간 수), M(통로 수)
    int N, M;
    cin>>N>>M;
    
    for(int i = 0;i < M;i++)
    {
        int a, b;
        cin>>a>>b;
        
        graph[a].push_back({b, 1});
        graph[b].push_back({a, 1});
    }
    fill(d, d + N + 1, 1e9);
    
    dijkstra();
    
    int result = 0;
    int maxValue = 0;
    int index = 0;
    
    // 큰 값 고르기
    for(int i = 1;i <= N;i++)
    {
        // 같으면 결과값 증가시키고
        if (maxValue == d[i])
            result++;
        
        // 크면 값 바꾸기
        if (maxValue < d[i])
        {
            result++;
            maxValue = d[i];
            index = i;
        }
    }

    cout<<index<<" "<<maxValue<<" "<<result<<endl;

    return 0;
}

