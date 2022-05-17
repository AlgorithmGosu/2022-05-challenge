// 46: 아기 상어 (삼성 기출)
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

// 북 서 남 동
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};

// n(공간의 크기)
int n;
int weight = 2;

// 거리 테이블
int dist[20][20];

void BFS(vector<vector<int>> &v, int i, int j)
{
    queue<pair<int, int>> q;
    dist[i][j] = 0;
    q.push({i, j});
    
    while (!q.empty())
    {
        int x = q.front().first;
        int y = q.front().second;
        
        q.pop();

        for(int dir = 0;dir < 4;dir++)
        {
            int tempX = x + dx[dir];
            int tempY = y + dy[dir];
            
            if (tempX < 0 || tempY < 0 || tempX >= n || tempY >= n)
                continue;
            
            // 방문한적 없고 자신보다 무게가 작을 때 지나가기
            if (dist[tempX][tempY] == -1 && v[tempX][tempY] <= weight)
            {
                // 이전까지의 거리 + 1
                dist[tempX][tempY] = dist[x][y] + 1;
                q.push({tempX, tempY});
            }
        }
    }
}

pair<int, int> findFish(vector<vector<int>> v)
{
    int x, y;
    int minDist = 1e9;
    
    for(int i = 0;i < n;i++)
    {
        for(int j = 0;j < n;j++)
        {
            // 방문한적 없고 물고기를 먹을 수 있는 무게라면
            if (dist[i][j] != -1 && (1 <= v[i][j] && v[i][j] < weight))
            {
                // 그 중에서도 가장 거리가 가까운 물고기의 위치 좌표 저장
                if (dist[i][j] < minDist)
                {
                    x = i;
                    y = j;
                    minDist = dist[i][j];
                }
            }
        }
    }
    if (minDist == 1e9)
        return {-1, -1};
    else
        return {x, y};
}
int main()
{
    cin>>n;
    
    // 상어 시작 좌표
    int x = 0, y = 0;
    
    vector<vector<int>> v(20, vector<int>(20, 0));
    
    for(int i = 0;i < n;i++)
    {
        for(int j = 0;j < n;j++)
        {
            cin>>v[i][j];
            
            // 물고기의 좌표를 저장
            if (v[i][j] == 9)
            {
                x = i;
                y = j;
                v[i][j] = 0;
            }
        }
    }
    
    int result = 0;
    int count = 0;
    while (1)
    {
        // 방문 거리는 -1로 초기화
        for(int i = 0;i < 20;i++)
            fill(dist[i], dist[i] + 20, -1);

        // 최단 거리 구하기
        BFS(v, x, y);
        
        // 구한 거리 중 가장 가까운 물고기
        auto temp = findFish(v);
        
        x = temp.first;
        y = temp.second;
        
        // 먹을 수 있는 고기가 없으면 종료
        if (x == -1)
        {
            cout<<result<<endl;
            return 0;
        }
        
        // 거리값에 물고기까지의 최단 거리를 넣고 물고기 값을 0으로 초기화
        result += dist[x][y];
        v[x][y] = 0;
        count++;
        
        // 물고기를 먹은 갯수와 무게가 같을 때 무게를 증가시킴
        if (count >= weight)
        {
            weight++;
            count = 0;
        }
    }
    
    return 0;
}

