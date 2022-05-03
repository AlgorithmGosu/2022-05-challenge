#include <queue>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

// 모든 노드에 대한 진입 차수를 0으로 초기화
int indegree[501];
// 강의 시간
int courseTime[501];
// 각 노드에 연결된 간선 정보를 담기 위한 연결 리스트
vector<int> graph[501];

void TopologySort(int N)
{
    vector<int> result(501);
    queue<int> q;
    
    for(int i = 1;i <= N;i++)
        result[i] = courseTime[i];
    
    for(int i = 1; i<= N;i++)
    {
        if (indegree[i] == 0)
            q.push(i);
    }
    
    while (!q.empty())
    {
        int temp = q.front();
        q.pop();
        
        for(int i = 0;i < graph[temp].size();i++)
        {
            // 연결된 강의 시간이 더 크면 저장
            result[graph[temp][i]] = max(result[graph[temp][i]], result[temp] + courseTime[graph[temp][i]]);
            
            indegree[graph[temp][i]] -= 1;
            
            // 진입 차수가 0이 되면 새롭게 넣기
            if (indegree[graph[temp][i]] == 0)
                q.push(graph[temp][i]);
        }
    }
    for(int i = 1;i <= N;i++)
        cout<<result[i]<<endl;
}

int main()
{
    // N(강의 수), result(결과)
    int N;
    cin>>N;
    
    for(int i = 1;i <= N;i++)
    {
        int node;
        cin>>node;
        
        courseTime[i] = node;
        
        while(1)
        {
            int temp;
            cin>>temp;
            
            if (temp == -1)
                break;
            
            graph[temp].push_back(i);
            indegree[i] += 1;
        }
    }
    
    TopologySort(N);
    
    return 0;
}
/*
 5
 10 -1
 10 1 -1
 4 1 -1
 4 3 1 -1
 3 3 -1
 */

