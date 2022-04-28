vector<int> v[9];
bool visited[9];

void BFS(int start)
{
    queue<int> q;
    
    q.push(start);
    visited[start] = true;
    
    while(q.empty() == false)
    {
        int x = q.front();
        q.pop();
        
        for(int i = 0;i < v[x].size();i++)
        {
            int y = v[x][i];
            if(visited[y] == false)
            {
                q.push(y);
                visited[y] = true;
            }
            
        }
    }
}
