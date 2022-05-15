#include <vector>
#include <algorithm>
#include <stdio.h>
using namespace std;


// 반시계 방향 45도
int dx[8] = {-1, -1, 0, 1, 1, 1, 0, -1};
int dy[8] = {0, -1, -1, -1, 0, 1, 1, 1};

int answer = 0;
// 청소년 상어
void DFS(vector<vector<pair<int, int>>> &v, int X, int Y, int sharkDir, int result)
{
    int res = result + v[X][Y].first;
    v[X][Y].first = 0;
    
    // 물고기 방향 전환 시작
    for(int i = 1;i <= 16;i++)
    {
        for(int x = 0;x < 4;x++)
        {
            for(int y = 0;y < 4;y++)
            {
                // 방향 전환할 물고기라면
                if (v[x][y].first == i)
                {
                    int dir = v[x][y].second - 1;
                    for(int count = 0;count < 8;count++)
                    {
                        int tempX = x + dx[dir];
                        int tempY = y + dy[dir];
                        
                        // 바운더리 체크
                        if (tempX < 0 || tempY < 0 || tempX >= 4 || tempY >= 4)
                        {
                            dir = (dir + 1) % 8;
                            continue;
                        }
                        // 상어가 있는 칸이라면
                        else if (tempX == X && tempY == Y)
                        {
                            dir = (dir + 1) % 8;
                            continue;
                        }
                        // 이동 가능하면 이동하고 종료
                        else
                        {
                            // 방향 바꿔주고 바꾸기
                            v[x][y].second = dir + 1;
                            swap(v[x][y], v[tempX][tempY]);
                            break;
                        }
                    }
                }
            }
        }
    } // 물고기 이동 종료
    
    // 가능한 방향에 있는 물고기를 먹는 모든 경우를 다 체크 -> DFS
    vector<pair<int, int>> available;
    
    int tempX = X;
    int tempY = Y;
    for(int idx = 0;idx < 4;idx++)
    {
        // 상어 이동 시작
        tempX = tempX + dx[sharkDir - 1];
        tempY = tempY + dy[sharkDir - 1];
        
        // 바운더리 체크
        if (tempX < 0 || tempY < 0 || tempX >= 4 || tempY >= 4)
            break;
        
        // 물고기가 있는 경우
        else if (v[tempX][tempY].first != 0)
            available.push_back({tempX, tempY});
    }
    
    // 더 이상 먹을 수 없으면 종료
    if (available.empty() == true)
    {
        answer = max(answer, res);
        return;
    }
    
    for(auto iter : available)
    {
        int tempX = iter.first;
        int tempY = iter.second;
        
        DFS(v, tempX, tempY, v[tempX][tempY].second, res);
    }
}

int main()
{
    vector<vector<pair<int, int>>> v(4, vector<pair<int, int>>(4));
    
    for(int i = 0;i < 4;i++)
    {
        for(int j = 0;j < 4;j++)
        {
            int a, b;
            scanf(" %d %d", &a, &b);
            
            // {물고기 무게, 방향}
            v[i][j] = {a, b};
        }
    }
    
    answer = 0;
    DFS(v, 0, 0, v[0][0].second, 0);
    
    printf("%d\n", answer);
    
    return 0;
}

