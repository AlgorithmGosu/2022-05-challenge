#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int indegree[501];

int topology(int v, vector<int> graph[501], vector<int> &result)
{
    queue<int> q;
    int limit = 0;
    
    for(int i = 1;i <= v;i++)
    {
        if (indegree[i] == 0)
        {
            q.push(i);
        }
    }
    
    while (!q.empty())
    {
        limit += 1;
        
        // queue의 사이즈가 2 이상인 경우
        // -> 즉 indegree가 0인게 2개라면 1등인 노드가 여러개라는 것이므로 순위를 알 수 없다. 즉 "?"인 경우임
        if (q.size() >= 2)
            return 2;
        
        int now = q.front();
        q.pop();
        
        result.push_back(now);
    
        for(int i = 0;i < graph[now].size();i++)
        {
            indegree[graph[now][i]] -= 1;
            
            if (indegree[graph[now][i]] == 0)
            {
                q.push(graph[now][i]);
            }
        }
    }
    // 성공
    if (limit == v)
        return 0;
    
    // 사이클이 생기면 impossible
    else
        return 1;
}
int main()
{
    // 테스트 케이스
    int T;
    cin>>T;
    
    while (T-- > 0)
    {
        // 연결 정보
        vector<int> graph[501];
        fill_n(indegree, 501, 0);
        
        // 팀의 수
        int n;
        cin>>n;
        
        vector<int> team;
        for(int i = 0;i < n;i++)
        {
            int temp;
            cin>>temp;
            
            team.push_back(temp);
        }
        
        
        for(int i = 0;i < team.size();i++)
        {
            for(int j = i + 1;j < team.size();j++)
            {
                graph[team[i]].push_back(team[j]);
                // 진입 차수 증가
                indegree[team[j]] += 1;
            }
        }

        // 변경된 수
        int m;
        cin>>m;
        
        vector<pair<int, int>> v;
        //bool stop = false;
        for(int i = 0;i < m;i++)
        {
            int a, b;
            cin>>a>>b;
            
            v.push_back({a, b});
        }

        for(int i = 0;i < v.size();i++)
        {
            // 올해가 a > b 라는 뜻
            int a = v[i].first;
            int b = v[i].second;
            
            // 순서 변경하고 넣기
            bool flag = false;
            for(int j = 0;j < graph[a].size();j++)
            {
                if (graph[a][j] == b)
                {
                    flag = true;
                    graph[a].erase(graph[a].begin() + j);
                    indegree[b] -= 1;
                }
            }
            if (flag == true)
            {
                graph[b].push_back(a);
                indegree[a] += 1;
            }
            else
            {
                for(int j = 0;j < graph[b].size();j++)
                {
                    if (graph[b][j] == a)
                    {
                        graph[b].erase(graph[b].begin() + j);
                        indegree[a] -= 1;
                    }
                }
                
                graph[a].push_back(b);
                indegree[b] += 1;
            }
        }


        vector<int> ans;
        
        int result = topology(n, graph, ans);
        
        // 실패 -> impossible(사이클 생성)
        if (result == 1 || result == 2)
            cout<<"IMPOSSIBLE"<<endl;
        
        else if (result == 2)
            cout<<"?"<<endl;
        
        // 성공
        else
        {
            for(int i = 0;i < ans.size();i++)
                cout<<ans[i]<<" ";
            cout<<endl;
        }
    }
    return 0;
}

