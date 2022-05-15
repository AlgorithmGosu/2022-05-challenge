#include <iostream>
#include <string>
#include <vector>
using namespace std;

int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

int main()
{
    // N(보드 크기), K(사과 수), L(뱀 회전 수)
    int N, K, L;
    int result = 0;
    
    cin>>N;
    vector<vector<int>> v(N, vector<int>(N, 0));
    
    cin>>K;
    for(int i = 0;i < K;i++)
    {
        int a, b;
        cin>>a>>b;
        
        v[a - 1][b - 1] = 1;
    }
    
    vector<pair<int, char>> snake;
    cin>>L;
    for(int i = 0;i < L;i++)
    {
        int a;
        char b;
        cin>>a>>b;
        
        snake.push_back({a, b});
    }
    
    // 위치 좌표
    int i = 0;
    int j = 0;

    // snake가 방향을 전환할지 결정
    int index = 0;
    
    // 방향 전환 인덱스
    int dir = 0;
    
    // 꼬리 인덱스
    vector<pair<int, int>> tail;
    
    while(1)
    {
        result++;
        
        v[i][j] = -1;
        tail.push_back({i, j});
        
        if (result == snake[index].first + 1)
        {
            // 오른쪽 회전
            if (snake[index].second == 'D')
            {
                dir = (dir + 1) % 4;
            }
            // 왼쪽 회전
            else
            {
                dir--;
                if (dir < 0)
                    dir = 3;
            }
            
            index++;
        }
        
        int tempR = i + dx[dir];
        int tempC = j + dy[dir];
        
        // 벽인 경우는 종료
        if (tempR < 0 || tempC < 0 || tempR >= N || tempC >= N)
            break;
        
        // 이미 뱀이 있는 경우는 종료
        else if (v[tempR][tempC] == -1)
            break;
        
        // 사과가 있는 경우 몸의 길이를 늘림
        else if (v[tempR][tempC] == 1)
        {
            // nothing
        }
        
        // 사과가 없으면 꼬리를 잘라
        else if (v[tempR][tempC] == 0)
        {
            if (tail.size() >= 1)
            {
                int tailR = tail[0].first;
                int tailC = tail[0].second;
                
                v[tailR][tailC] = 0;

                tail.erase(tail.begin() + 0);
            }
        }
        
        i = tempR;
        j = tempC;
    }
    cout<<result<<endl;
    
    return 0;
}

