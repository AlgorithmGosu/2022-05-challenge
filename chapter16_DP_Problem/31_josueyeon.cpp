#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

int dx[3] = {-1, 0, 1};
int dy[3] = {-1, -1, -1};

int main()
{
    // 테스트 케이스 수
    int T;
    // n x m
    int n, m;
    // 결과 저장 벡터
    vector<int> result;
    
    cin>>T;
    
    while(T-- > 0)
    {
        cin>>n>>m;
        
        vector<vector<int>> v(n, vector<int>(m, 0));
        for(int i = 0;i < n;i++)
        {
            for(int j = 0;j < m;j++)
            {
                cin>>v[i][j];
            }
        }
        
        // 열
        for(int c = 1;c < m;c++)
        {
            // 행
            for(int r = 0;r < n;r++)
            {
                int temp = v[r][c];
                
                for(int dir = 0;dir < 3;dir++)
                {
					// 가능한 방향 확인
                    int tempR = r + dx[dir];
                    int tempC = c + dy[dir];
                    
                    if (tempR < 0 || tempC < 0 || tempR >= n || tempC >= m)
                        continue;
                    
                    v[r][c] = max(v[r][c], temp + v[tempR][tempC]);
                }
            }
        }
        
        int answer = 0;
        for(int i = 0;i < n;i++)
            answer = max(answer, v[i][m - 1]);
        
        result.push_back(answer);
    }
    
    for(auto iter: result)
        cout<<iter<<endl;
    
    return 0;
}

