#include <vector>
#include <algorithm>
#include <queue>
#include <iostream>
using namespace std;

// 동 서 남 북
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

int L, R;

void process(vector<vector<int>> &v, vector<vector<int>> &unions, int x, int y, int index)
{
    // 연결된 연합 도시 정보
    vector<pair<int, int>> united;
    united.push_back({x, y});
    
    // BFS queue
    queue<pair<int, int>> q;
    q.push({x, y});
    
    unions[x][y] = index;
    int sum = v[x][y];  // 인구 수 총합
    int count = 1;  // 현재 연합 안에 있는 도시의 수
    
    while (!q.empty())
    {
        auto temp = q.front();
        q.pop();
        
        int i = temp.first;
        int j = temp.second;
        
        for(int dir = 0;dir < 4;dir++)
        {
            int tempR = i + dx[dir];
            int tempC = j + dy[dir];
            
            // 바운더리 체크
            if (tempR < 0 || tempC < 0 || tempR >= v.size() || tempC >= v.size())
                continue;
            
            // 인구 차이가 범위에 있으면
            if (unions[tempR][tempC] == -1
                &&abs(v[i][j] - v[tempR][tempC]) >= L && abs(v[i][j] - v[tempR][tempC]) <= R)
            {
                // queue에 넣어서 다시 BFS
                q.push({tempR, tempC});
                // 연합 도시 수 증가
                count++;
                // 연합 정보 갱신
                unions[tempR][tempC] = index;
                // 연합 도시에 좌표 넣기
                united.push_back({tempR, tempC});
                // 인구 총합에 인구 수 더하기
                sum += v[tempR][tempC];
            }
        }
    }
    
    // 연합 도시의 도시들은 다시 인구 이동시키기
    for(int idx = 0;idx < united.size();idx++)
    {
        int r = united[idx].first;
        int c = united[idx].second;
        
        v[r][c] = sum / count;
    }
}

int main()
{
    // N(땅 크기), L(인구 차이 L 이상), R(인구 차이 R 이하)
    int N;
    int result = 0;
    
    cin>>N>>L>>R;
    
    vector<vector<int>> v(N, vector<int>(N, 0));
    vector<vector<int>> unions(N, vector<int>(N, -1));
    
    for(int i = 0;i < N;i++)
    {
        for(int j = 0;j < N;j++)
        {
            cin>>v[i][j];
        }
    }
    
    while(1)
    {
        // 연합 정보를 초기화
        for(int i = 0;i < N;i++)
        {
            for(int j = 0;j < N;j++)
            {
                unions[i][j] = -1;
            }
        }
        
        int index = 0;
        for(int i = 0;i < N;i++)
        {
            for(int j = 0;j < N;j++)
            {
                // 처리 되지 않은 경우
                if (unions[i][j] == -1)
                {
                    process(v, unions, i, j, index);
                    index++;
                }
            }
        }
        
        // 인구 이동이 다 끝나면 종료
        if (index == N * N)
            break;
        
        result++;
    }
    cout<<result<<endl;
    
    return 0;
}

