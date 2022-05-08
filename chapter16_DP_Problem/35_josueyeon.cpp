#include <vector>
#include <iostream>
using namespace std;

bool isValid(int n)
{
    for(int i = 2;i <= n;i++)
    {
        if (n % i == 0 && !(i == 3 || i == 5 || i == 2))
            return false;
            
        while (n % i == 0)
        {
            n /= i;
        }
    }
    return true;
}

int main()
{
    // N(몇번째 소인수인지)
    int N;
    cin>>N;
    
    int result = 0;
    int num = 1;
    
    while(1)
    {
        // 유효하면 값을 증가시키기
        if (isValid(num) == true)
            result++;
        
        if (result == N)
            break;
        
        num++;
    }
    cout<<num<<endl;
    
    return 0;
}

