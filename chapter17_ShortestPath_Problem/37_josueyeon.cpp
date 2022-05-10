#include <vector>
#include <iostream>
using namespace std;

int main()
{
    // n(도시의 개수), m(버스의 개수)
    int n, m;
    int graph[101][101];
    
    cin>>n>>m;
    
    for(int i = 0;i < 101;i++)
    {
        for(int j = 0;j < 101;j++)
        {
            if (i == j)
                graph[i][j] = 0;
            else
                graph[i][j] = 1e9;
        }
    }
    
    for(int i = 0;i < m;i++)
    {
        int a, b, c;
        cin>>a>>b>>c;
        
        if (c < graph[a][b])
            graph[a][b] = c;
    }
    
    // i 번째 노드를 거쳐가는 길이 바로 가는 길보다 짧은지 비교해서 갱신
    // 이 작업을 모든 노드에 대해서 진행한다.
    for(int i = 1;i <= n;i++)
    {
        for(int a = 1; a <= n;a++)
        {
            for(int b = 1;b <= n;b++)
                graph[a][b] = min(graph[a][b], graph[a][i] + graph[i][b]);
        }
    }
    
    for(int a = 1; a <= n;a++)
    {
        for(int b = 1;b <= n;b++)
        {
            if (graph[a][b] == 1e9)
                cout<<0<<" ";
            else
                cout<<graph[a][b]<<" ";
        }
        cout<<endl;
    }
    return 0;
}
