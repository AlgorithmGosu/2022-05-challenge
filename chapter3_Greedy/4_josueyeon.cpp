#include <iostream>
using namespace std;

int main()
{
    // N(어떠한 수), K(목표 값)
    int N, K;
    int result = 0;
    
    cin>>N>>K;
    
    while(1)
    {
        if (N == 0)
            break;
        
        if (N % K != 0)
        {
            result++;
            N -= 1;
        }
        
        else
        {
            result++;
            N /= K;
            if (N == 1)
                break;
        }
    }
    cout<<result<<endl;;
    return 0;
}
