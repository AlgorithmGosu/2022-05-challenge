#include <vector>
#include <iostream>
using namespace std;

// 간단한 다익스트라

// N(no. of node), M(no. of edge), start(시작 node)
int N, M, start;

// node에 연결된 node 정보를 저장
vector<pair<int, int>> graph[100001];

// 방문 이력 저장
bool visited[100001];

// 최단 거리 1차원 테이블
int d[100001];

// 최단 거리 테이블 중 방문하지 않은 노드 중에서 가장 거리가 짧은 노드 반환
int getSmallestNode()
{
    int min = 1e9;
    int result = 0;

    for(int i = 1;i <= N;i++)
    {
        if(d[i] < min && visited[i] == false)
        {
            min = d[i];
            result = i;
        }
    }
    return result;
}

// 다익스트라 알고리즘
void dijkstra(int start)
{
    d[start] = 0;
    visited[start] = true;

    for(int i = 0;i < graph[start].size();i++)
        d[graph[start][i].first] = graph[start][i].second;

    for(int i = 0;i < N - 1;i++)
    {
        int now = getSmallestNode();
        visited[now] = true;

        // 현재 노드 graph[now] 와 연결된 노드 확인
        for(int j = 0;j < graph[now].size();j++)
        {
            // 현재 노드까지의 거리 (d[now]) + 현재 노드에서 연결된 노드 사이의 가중치 (graph[now][j].second)
            int cost = d[now] + graph[now][j].second;

            // 짧은 경우 최단 거리 테이블을 갱신
            // d[graph[now][j]].first는 현재 노드를 거치지 않았을 때의 최단 거리
            if (cost < d[graph[now][j].first])
                d[graph[now][j].first] = cost;
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
    fill_n(visited, 100001, false);

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

