#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <iostream>
using namespace std;

int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};
int sum = 0;

int safetyRegion(vector<vector<int>> temp)
{
    int result = 0;
    
    for(int i = 0;i < temp.size();i++)
    {
        for(int j = 0;j < temp[0].size();j++)
        {
            if (temp[i][j] == 0)
                result++;
        }
    }
    return result;
}
void virus(vector<vector<int>> &temp, int r, int c)
{
    for(int i = 0;i < 4;i++)
    {
        int tempR = r + dx[i];
        int tempC = c + dy[i];
        
        if (tempR < 0 || tempC < 0 || tempR >= temp.size() || tempC >= temp[0].size())
            continue;
        
        if (temp[tempR][tempC] == 0)
        {
            temp[tempR][tempC] = 2;
            virus(temp, tempR, tempC);
        }
    }
}
void DFS(vector<vector<int>> &v, int count, int N, int M)
{
    // 울타리를 다 만든 경우
    if (count == 3)
    {
        vector<vector<int>> temp(N, vector<int>(M, 0));
        
        for(int i = 0;i < N;i++)
        {
            for(int j = 0;j < M;j++)
            {
                temp[i][j] = v[i][j];
            }
        }
        
        // 울타리를 만들었을 때 바이러스 진행
        for(int i = 0;i < N;i++)
        {
            for(int j = 0;j < M;j++)
            {
                if (temp[i][j] == 2)
                    virus(temp, i, j);
            }
        }
        // 이 울타리가 최대인지 확인
        sum = max(sum, safetyRegion(temp));
        return;
    }
    
    // 빈 공간에 울타리 설치 -> 모든 경우의 수를 다 확인
    for(int i = 0;i < N;i++)
    {
        for(int j = 0;j < M;j++)
        {
            if (v[i][j] == 0)
            {
                v[i][j] = 1;
                count += 1;
                DFS(v, count, N, M);
                v[i][j] = 0;
                count -= 1;
            }
        }
    }
}
int main()
{
    // N(가로), M(세로)
    int N, M;
    
    cin>>N>>M;
    
    vector<vector<int>> v(N, vector<int>(M, 0));
    
    for(int i = 0;i < N;i++)
    {
        for(int j = 0;j < M;j++)
        {
            cin>>v[i][j];
        }
    }
    
    DFS(v, 0, N, M);

    cout<<sum<<endl;
    
    return 0;
}
