#include <vector>
#include <iostream>
using namespace std;

void BFS(vector<vector<int>> &v, vector<vector<bool>> &visited, int i, int j, int &result);
// N(가로), M(세로)
int N,M;

int main()
{
    cin>>N>>M;
    int result = 0;
    
    vector<vector<int>> v(N, vector<int>(M,0));              // 미로 맵
    vector<vector<bool>> visited(N, vector<bool>(M, false)); // 방문 기록
    
    // 2차원 벡터에 입력 받기
    for(int i = 0;i < N;i++)
    {
        for(int j = 0;j < M;j++)
        {
            int temp;
            cin>>temp;
            
            v[i][j] = temp;
        }
    }
    
    // 시작 지점부터 BFS 실행
    BFS(v, visited, 0, 0, result);
    
    cout<<result<<endl;
    
    return 0;
}

void BFS(vector<vector<int>> &v, vector<vector<bool>> &visited, int i, int j, int &result)
{
    // 바운더리 체크
    if (i >= N || j >= M)
        return;
    
    // 방문하지 않았고, 괴물이 없으면 방문하고 결과값++ 하기
    if (v[i][j] == 1 && visited[i][j] == false)
    {
        result++;
        visited[i][j] = true;
        
        // 최단 거리이므로 오른쪽과 하단 방향에 대해서만 진행
        BFS(v, visited, i, j - 1, result);
        BFS(v, visited, i - 1, j, result);
        BFS(v, visited, i, j + 1, result);
        BFS(v, visited, i + 1, j, result);
    }
}

// 정답 코드
int n, m;
int graph[201][201];

// 방향 정의: 상 하 좌 우
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, 1, -1};

int bfs(int x, int y)
{
    // 좌표 저장하기 위한 pair queue 생성
    queue<pair<int, int>> q;
    
    q.push({x, y});
    
    while(q.empty() == false)
    {
        // pair의 첫번째 요소: first, 두번째 요소: second
        int x = q.front().first;
        int y = q.front().second;
        
        q.pop();
        
        for(int i = 0;i < 4;i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];
            
            // 바운더리 체크
            if (nx < 0 || ny < 0 || nx >= N || ny >= M)
                continue;
            
            // 괴물이 있으면 갈 수 없음
            if(graph[nx][ny] == 0)
                continue;
            
            // 그래프 자체의 값을 (이전 노드의 값 + 1)로 변경함
            if(graph[nx][ny] == 1)
            {
                graph[nx][ny] = graph[x][y] + 1;
                q.push({nx, ny});
            }
        }
    }
    return graph[n - 1][m - 1];
}

void maze_runner()
{
    cin>>n>>m;
    
    for(int i = 0;i < n;i++)
    {
        for(int j = 0;j < m;j++)
        {
            scanf("%1d", &graph[i][j]);
        }
    }
    
    cout<<bfs(0, 0)<<endl;
}
