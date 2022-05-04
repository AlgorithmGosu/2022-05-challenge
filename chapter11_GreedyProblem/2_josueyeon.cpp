#include <iostream>
using namespace std;

int main()
{
    int result = 0;
    string s;
    
    cin>>s;
    for(int i = 0;i < s.size();i++)
    {
		// 1, 0 인 경우에는 더해줌
		// 결과가 1보다 작거나 같은 경우에는 더해줌
        if (s[i] == '1' || s[i] == '0' || result <= 1)
            result += s[i] - 48;
        else
            result = result * (s[i] - 48);
    }
    cout<<result<<endl;
    
    return 0;
}

