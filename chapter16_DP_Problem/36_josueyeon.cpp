#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// 36 편집 거리
int main()
{
    string str1, str2;
    cin>>str1>>str2;
    
    vector<vector<int>> dp(str1.size() + 1, vector<int>(str2.size() + 1, 0));
    
    for(int i = 1;i <= str1.size();i++)
        dp[i][0] = i;
    for(int j = 1;j <= str2.size();j++)
        dp[0][j] = j;
    
    for(int i = 1;i <= str1.size();i++)
    {
        for(int j = 1;j <= str2.size();j++)
        {
            // 문자가 같으면 대각선 위에 있는 수 대입
            if (str1[i - 1] == str2[j - 1])
                dp[i][j] = dp[i - 1][j - 1];
            
            // 다르면 최소 값 + 1 해서 넣기
            else
                dp[i][j] = min(dp[i][j - 1], min(dp[i - 1][j], dp[i - 1][j - 1])) + 1;
        }
    }
    cout<<dp[str1.size()][str2.size()]<<endl;
    
    return 0;
}

