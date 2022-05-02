#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;


// 플로이드 워셜
int graph[30001][30001];
int d[30001];

int main()
{
    // N(도시의 개수), M(통로의 개수), C(시작 도시)
    int N, M, C;
    cin>>N>>M>>C;
    
    for(int i = 0;i < 30001;i++)
    {
        for(int j = 0;j < 30001;j++)
        {
            if (i == j)
                graph[i][j] = 0;
            else
                graph[i][j] = 1e9;
        }
    }
    
    for(int i = 0;i < M;i++)
    {
        int a, b, c;
        cin>>a>>b>>c;
        
        graph[a][b] = c;
    }
    
    for(int i = 1;i <= N;i++)
    {
        for(int a = 1;a <= N;a++)
        {
            for(int b = 1;b <= N;b++)
                graph[a][b] = min(graph[a][b], graph[a][i] + graph[i][b]);
        }
    }
    int result = 0;
    int sum = 0;
    
    for(int a = 1; a <= N;a++)
    {
        for(int b = 1;b <= N;b++)
        {
            if (graph[a][b] != 1e9)
            {
                result++;
                sum += graph[a][b];
            }
            else
                continue;
        }
    }
    
    cout<<result<<" "<<sum<<endl;
    return 0;
}

// 다익스트라 알고리즘
vector<pair<int, int>> graph[30001];
int d[30001];

void dijkstra(int start)
{
    priority_queue<pair<int, int>> pq;

    pq.push({0, start});
    d[start] = 0;

    while(!pq.empty())
    {
        int edge = pq.top().first * -1;
        int node = pq.top().second;

        pq.pop();

        if (d[node] < edge)
            continue;

        for(int i = 0;i < graph[node].size();i++)
        {
            int cost = edge + graph[node][i].second;

            if (cost < d[graph[node][i].first])
            {
                d[graph[node][i].first] = cost;
                pq.push({cost * -1, graph[node][i].first});
            }
        }
    }

}

int main()
{
    int N, M, start;

    cin>>N>>M>>start;
    for(int i = 0;i < M;i++)
    {
        int a, b, c;
        cin>>a>>b>>c;

        graph[a].push_back({b, c});
    }

    fill(d, d+30001, 1e9);

    dijkstra(start);

    int result = 0;
    int maxD = 0;

    for(int i = 1;i <= N;i++)
    {
        if(d[i] != 1e9)
        {
            result++;
            maxD = max(maxD, d[i]);
        }
    }
    cout<<result - 1<<" "<<maxD<<endl;

    return 0;
}

