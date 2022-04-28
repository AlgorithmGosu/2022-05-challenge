#include <iostream>
#include <string>
using namespace std;

int main()
{
    // N(N시 59분 59초, 0 <= N <= 23)
    int N;
    int temp, result = 0;
    
    cin>>N;
    
    // brute force
    for(int i = 0;i <= N;i++)
    {
        for(int j = 0;j <= 59;j++)
        {
            for(int k = 0;k <= 59;k++)
            {
                temp = i * 10000 + j * 100 + k;
                string str = to_string(temp);   // string으로 만들어서 계산
                
                for(int m = 0;m < str.size();m++)
                {
                    if (str[m] == '3')
                    {
                        result++;
                        break;
                    }
                }

            }
        }
    }
    cout<<result<<endl;
    
    return 0;
}

