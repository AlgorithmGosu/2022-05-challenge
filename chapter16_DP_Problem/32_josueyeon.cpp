#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

int dx[2] = {-1, -1};
int dy[2] = {0, -1};

int main()
{
    // 삼각형 크기
    int N;
    
    cin>>N;
    
    vector<vector<int>> v(N, vector<int>(N, 0));
    for(int i = 0;i < N;i++)
    {
        for(int j = 0;j < i + 1;j++)
        {
            cin>>v[i][j];
        }
    }
    
    for(int i = 1;i < N;i++)
    {
        for(int j = 0;j < i + 1;j++)
        {
            int temp = v[i][j];
            
			// 가능한 방향에 대해서 계산
            for(int dir = 0;dir < 2;dir++)
            {
                int tempR = i + dx[dir];
                int tempC = j + dy[dir];
                
                if (tempR < 0 || tempC < 0 || tempR >= N || tempC >= i)
                    continue;
                
				// 최대인 값 저장
                v[i][j] = max(v[i][j], temp + v[tempR][tempC]);
            }
        }
    }
    
    int result = 0;
    for(int i = 0;i < N;i++)
        result = max(result, v[N - 1][i]);
    
    cout<<result<<endl;
    
    return 0;
}


