#include <iostream>
#include <string>
using namespace std;

int main()
{
    string s;
    int result = 0;
    
    cin>>s;
    for(int i = 0;i < s.size() - 1;i++)
    {
		// 같지 않으면 +1 하고 같지 않을 때까지 진행
        if (s[i] != s[i + 1])
        {
            result++;
            i++;
            while(s[i] == s[i + 1])
                i++;
        }
    }
    cout<<result<<endl;
    
    return 0;
}
