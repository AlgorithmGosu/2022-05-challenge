#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int dp[16];
    
    int N;
    cin>>N;
    
    fill_n(dp, 16, 0);
    
    vector<int> time;
    vector<int> value;
    
    for(int i = 0;i < N;i++)
    {
        int a, b;
        cin>>a>>b;
        
        time.push_back(a);
        value.push_back(b);
    }
    
    int maxV = 0;
    for(int i = N - 1;i >= 0;i--)
    {
        // 현재 날짜와 상담에 걸리는 시간을 더해서 총 언제 끝나는지 계산
        int temp = time[i] + i;
        
        // 기간 안에 상담이 끝나는 경우
        if(temp <= N)
        {
            // 상담을 하면 받는 돈 + 그때까지 이익과 최고 이익 비교
            dp[i] = max(value[i] + dp[temp], maxV);
            maxV = dp[i];
        }
        else
            dp[i] = maxV;
    }
    cout<<maxV<<"\n";
    
    return 0;
}

