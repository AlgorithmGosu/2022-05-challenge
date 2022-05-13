#include <vector>
#include <cmath>
#include <stdio.h>
using namespace std;

// 시간초과 되지 않도록 scanf, printf 사용하고 
// 안쪽 loop 돌때는 long으로 바꿔서 연산해서 오버플로우 방지
int main()
{
    vector<bool> v(1000001, true);
    
    // M~N 사이의 소수
    int M = 1, N = 1;
    scanf("%d %d", &M, &N);
    
    v[0] = false;
    v[1] = false;
    
    for(long i = 2;i <= sqrt(N);i++)
    {
        if (v[i] == true)
        {
            long j = 2;
            while (i * j <= N)
            {
                v[i * j] = false;
                j++;
            }
        }
    }
    
    for(int i = M;i <= N;i++)
        if (v[i] == true)
            printf("%d\n", i);
    
    return 0;
}

