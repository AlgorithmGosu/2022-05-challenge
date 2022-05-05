#include <iostream>
#include <string>
#include <vector>
using namespace std;

// 계수 정렬 사용
//	-> 26 크기의 배열 생성해두고 입력이 들어올 때마다 +1하기
//  -> 숫자면 따로 계산해서 마지막에 출력
int main()
{
    string str;
    vector<int> v(26, 0);
    int sum = 0;
    
    cin>>str;
    for(int i = 0;i < str.size();i++)
    {
		// 숫자는 따로 계산
        if (str[i] >= 48 && str[i] <= 57)
            sum += str[i] - 48;
		
		// 계수 정렬
        else
            v[str[i] - 65]++;
    }
    
    for(int i = 0;i < 26;i++)
    {
        for(int j = 0;j < v[i];j++)
        {
            char ch = i + 65;
            cout<<ch;
        }
    }
    cout<<sum<<endl;
    
    return 0;
}


