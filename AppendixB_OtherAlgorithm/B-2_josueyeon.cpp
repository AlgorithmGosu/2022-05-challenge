#include <vector>
#include <algorithm>
#include <stdio.h>
using namespace std;

bool IsValid(vector<char> str)
{
    int countM = 0;
    int countZ = 0;
    
    for(int i = 0;i < str.size();i++)
    {
        if (str[i] == 'a' || str[i] == 'e'
            || str[i] == 'i' || str[i] == 'o' || str[i] == 'u')
            countM++;
        else
            countZ++;
    }
    
    if (countM >= 1 && countZ >= 2)
        return true;
    else
        return false;
}
int main()
{
    // C개 중 L개 선택해서 sort
    int L, C;
    scanf("%d %d", &L, &C);
    
    vector<vector<char>> ans;
    vector<char> v;
    
    for(int i = 0;i < C;i++)
    {
        char temp;
        scanf(" %c", &temp);

        v.push_back(temp);
    }

    vector<int> check;
    for(int i = 0;i < C;i++)
    {
        if (i < C - L)
            check.push_back(0);
        else
            check.push_back(1);
    }
    
	// 조합을 선택해서 정렬한 다음, 가능한 조합인지 체크해서 가능하면 넣기
    do
    {
        vector<char> str;
        
        for(int i = 0;i < check.size();i++)
            if (check[i] == 1)
                str.push_back(v[i]);
       
	   // 유효한지 체크	
        if (IsValid(str) == true)
        {
            sort(str.begin(), str.end());
            ans.push_back(str);
        }
        
    } while(next_permutation(check.begin(), check.end()));
    
    sort(ans.begin(), ans.end());
    
    for(int i = 0;i < ans.size();i++)
    {
        for(int j = 0;j < ans[i].size();j++)
        {
            printf("%c", ans[i][j]);
        }
        printf("\n");
    }
    return 0;
}

