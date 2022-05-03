#include <iostream>
#include <algorithm>
using namespace std;

// 플로이드 워셜 알고리즘

// N(no. of node), M(no. of edge)
int N, M;

// node 최대를 500개라고 해서 N+1 한 걸로 인덱스를 바로 쓸 수 있도록
int graph[501][501];

int main()
{
    cin>>N>>M;

    // 자기 자신으로 가는 경로 제외하고 무한으로 초기화
    for(int i = 0;i < 501;i++)
    {
        for(int j = 0;j < 501;j++)
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

        // a -> b : c
        graph[a][b] = c;
    }

    // i 번째 노드를 거쳐가는 길이 바로 가는 길보다 짧은지 비교해서 갱신
    // 이 작업을 모든 노드에 대해서 진행한다.
    for(int i = 1;i <= N;i++)
    {
        for(int a = 1; a <= N;a++)
        {
            for(int b = 1;b <= N;b++)
                graph[a][b] = min(graph[a][b], graph[a][i] + graph[i][b]);
        }
    }

    for(int a = 1; a <= N;a++)
    {
        for(int b = 1;b <= N;b++)
        {
            if (graph[a][b] != 1e9)
                cout<<"INFINITY"<<endl;
            else
                cout<<graph[a][b]<<endl;
        }
    }

    return 0;

}

