#include <vector>
#include <algorithm>
#include <queue>
#include <iostream>
using namespace std;

class Position
{
public:
    int x1, x2, y1, y2;
    
    Position(int _x1, int _y1, int _x2, int _y2)
    {
        this->x1 = _x1;
        this->y1 = _y1;
        this->x2 = _x2;
        this->y2 = _y2;
    }
};

vector<Position> getNextPos(Position pos, vector<vector<int>> v)
{
    vector<Position> result;
    
    // 방향 전환 : 동 서 남 북
    int dx[4] = {0, 0, 1, -1};
    int dy[4] = {1, -1, 0, 0};
    
    for(int i = 0;i < 4;i++)
    {
        int tempX1 = pos.x1 + dx[i];
        int tempY1 = pos.y1 + dy[i];
        
        int tempX2 = pos.x2 + dx[i];
        int tempY2 = pos.y2 + dy[i];
        
        if (v[tempX1][tempY1] == 0 && v[tempX2][tempY2] == 0)
            result.push_back(Position(tempX1, tempY1, tempX2, tempY2));
    }
    
    // 방향 전환 확인
    int temp[2] = {-1, 1};
    
    // 가로
    if (pos.x1 == pos.x2)
    {
        for(int i = 0;i < 2;i++)
        {
            // 회전 가능한 경우
            if(v[pos.x1 + temp[i]][pos.y1] == 0 && v[pos.x2 + temp[i]][pos.y2] == 0)
            {
                result.push_back(Position(pos.x1, pos.y1, pos.x1 + temp[i], pos.y1));
                result.push_back(Position(pos.x2, pos.y2, pos.x2 + temp[i], pos.y2));
            }
        }
    }
    // 세로
    if (pos.y1 == pos.y2)
    {
        for(int i = 0;i < 2;i++)
        {
            // 회전 가능한 경우
            if(v[pos.x1][pos.y1 + temp[i]] == 0 && v[pos.x2][pos.y2 + temp[i]] == 0)
            {
                result.push_back(Position(pos.x1, pos.y1, pos.x1, pos.y1 + temp[i]));
                result.push_back(Position(pos.x2, pos.y2, pos.x2, pos.y2 + temp[i]));
            }
        }
    }
    
    return result;
}

int solution(vector<vector<int>> board) {
    int answer = 0;
    
    int size = board.size();
    vector<vector<int>> v(size + 2, vector<int>(size + 2, 1));
    
    for(int i = 0;i < size;i++)
    {
        for(int j = 0;j < size;j++)
        {
            v[i + 1][j + 1] = board[i][j];
        }
    }
    queue<pair<Position, int>> q;
    // 방문 체크
    vector<Position> visited;
    
    // 시작 위치
    q.push({Position(1, 1, 1, 2), 0});
    // 방문 체크
    visited.push_back(Position(1, 1, 1, 2));
    
    while (!q.empty())
    {
        auto pos = q.front().first;
        int cost = q.front().second;
        
        q.pop();
        
        // 로봇이 (n,n) 위치에 도달했으면 종료
        if ((pos.x1 == size && pos.y1 == size) || (pos.x2 == size && pos.y2 == size))
            return cost;
        
        // 가능한 다음 위치 계산
        vector<Position> nextPos = getNextPos(pos, v);
        
        for(int i = 0;i < nextPos.size();i++)
        {
            bool check = true;
            Position now = nextPos[i];
            for(int j = 0;j < visited.size();j++)
            {
                // 방문 한적 있는지 체크
                if (now.x1 == visited[j].x1 && now.y1 == visited[j].y1 && now.x2 == visited[j].x2 && now.y2 == visited[j].y2)
                {
                    check = false;
                    break;
                }
            }
            if (check == true)
            {
                q.push({now, cost + 1});
                visited.push_back(now);
            }
                
        }
        
        
        
    }
    
    return answer;
}

