#include <iostream>
#include <vector>
#include <queue>
using namespace std;

void BFS(vector<int> v[], vector<int> &dist, int start)
{
    queue<int> q;
    
    q.push(start);
    dist[start] = 0;
    
    while (!q.empty())
    {
        int temp = q.front();
        q.pop();
        
        for(int i = 0;i < v[temp].size();i++)
        {
            if (dist[v[temp][i]] == -1)
            {
                dist[v[temp][i]] = dist[temp] + 1;
                q.push(v[temp][i]);
            }
        }
    }
}

int main()
{
    // N(도시 수), M(도로 수), K(목표 거리), X(출발 노드)
    int N, M, K, X;
    
    cin>>N>>M>>K>>X;
    
    vector<int> v[N + 1];
    vector<int> dist(N + 1, -1);
    
    for(int i = 0;i < M;i++)
    {
        int a, b;
        cin>>a>>b;
        
        v[a].push_back(b);
    }
    
    BFS(v, dist, X);
    
    vector<int> result;
    for(int i = 1;i <= N;i++)
    {
        if (dist[i] == K)
            result.push_back(i);
    }
    
    // 해당되는 거리가 없는 경우
    if (result.empty())
        cout<<-1<<endl;
    
    // 해당하는 거리가 있으면 정렬해서 오름차순으로 출력
    else
    {
        for(int iter: result)
            cout<<iter<<endl;
    }
    return 0;
    
}
