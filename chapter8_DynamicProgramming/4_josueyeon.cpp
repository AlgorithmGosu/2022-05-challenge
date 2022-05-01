#include <iostream>
using namespace std;

int main()
{
    // N(가로 길이)
    int N;
    cin>>N;

    // dp 테이블
    int d[1001];

    d[1] = 1;
    d[2] = 3;

    for(int i = 3;i <= N;i++)
    {
        d[i] = (d[i - 1] + 2 * d[i - 2]) % 796796;
    }

    cout<<d[N]<<endl;

    return 0;
}


