vector<int> v[9];
bool visited[9];

//DFS
void DFS(int x)
{
    visited[x] = true;
    
    for(int i = 0;i < v[x].size();i++)
    {
        int y = v[x][i];
        if (visited[y] == false)
            DFS(y);
    }
}
