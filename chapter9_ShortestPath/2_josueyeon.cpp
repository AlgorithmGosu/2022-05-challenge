#include <iostream>
#include <queue>
#include <vector>
using namespace std;

vector<pair<int, int>> graph[101];
int d[101];

void dijkstra(int start)
{
    // edge, node
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
                pq.push({-1 * cost, graph[node][i].first});
            }

        }
    }

}

int main()
{
    // N(회사의 개수), M(경로의 개수) 최대 100
    int N, M;
    cin>>N>>M;

    // X(목표 회사), K(소개팅 장소) 최대 100: 1->K->X
    int X, K;

    for(int i = 0;i < M;i++)
    {
        int a, b;
        cin>>a>>b;

        graph[a].push_back({b, 1});
        graph[b].push_back({a, 1});
    }
    cin>>X>>K;

    // 다익스트라 알고리즘을 나눠서 사용함: K 까지 + X 까지
    fill_n(d, 101, 1e9);
    dijkstra(1);

    int result = d[K];

    fill_n(d, 101, 1e9);
    dijkstra(K);

    result += d[X];

    cout<<result<<endl;

    return 0;
}

