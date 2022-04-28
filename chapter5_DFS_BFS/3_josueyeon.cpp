#include <vector>
#include <iostream>
using namespace std;

void DFS(vector<vector<int>> &v, vector<vector<bool>> &visited, int i, int j);

// N(가로 길이), M(세로 길이), 바운더리 체크를 위해서 전역변수로 설정
int N,M;

int main()
{
    int result = 0;
    cin>>N>>M;

    vector<vector<int>> v(N, vector<int>(M,0));              // 얼음 맵
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

    // 2차원 벡터를 돌면서 방문하지 않았고 값이 0인 공간에 대해서 DFS를 실행하여 연결된 곳은 모두 방문
    // DFS가 종료되면 연결된 부분이 끝났다는 뜻이므로 result++
    for(int i = 0;i < N;i++)
    {
        for(int j = 0;j < M;j++)
        {
            if(visited[i][j] == false && v[i][j] == 0)
            {
                DFS(v, visited, i ,j);
                result++;
            }
        }
    }
    cout<<result<<endl;

    return 0;
}
void DFS(vector<vector<int>> &v, vector<vector<bool>> &visited, int i, int j)
{
    // 바운더리 체크
    if (i >= N || j >= M)
        return;

    else if (v[i][j] == 0 && visited[i][j] == false)
    {
        visited[i][j] = true;

	// 값의 진행이 왼쪽 상단에서 오른쪽 하단으로 이어지므로 상, 좌 를 볼 필요 없음.
        MBFS(v, visited, i, j + 1);
        MBFS(v, visited, i + 1, j);
    }
}


// 답지 풀이

int n,m;
int graph[1000][1000];

bool dfs(int x, int y)
{
    if (x <= 1 || y <= 1 || x >= n || y >= m)
        return false;

    if (graph[x][y] == 0)
    {
        graph[x][y] = 1;

        dfs(x - 1, y);
        dfs(x, y - 1);
        dfs(x + 1, y);
        dfs(x, y + 1);

        return true;
    }

    return false;
}

void ice_cream()
{
    cin>>n>>m;

    for(int i = 0;i < n;i++)
    {
        for(int j = 0;j < m;j++)
        {
            scanf("%1d", &graph[i][j]);
        }
    }

    int result = 0;
    for(int i = 0;i < n;i++)
    {
        for(int j = 0;j < m;j++)
        {
            if(dfs(i, j))
                result++;
        }
    }
    cout<<result<<endl;
}

