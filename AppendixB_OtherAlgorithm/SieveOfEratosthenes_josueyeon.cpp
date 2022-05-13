#include <iostream>
#include <cmath>
using namespace std;

// 에라토스테네스의 체 : 작은 수부터 배수를 제거하는 과정 -> 실행 속도 빠르지만 메모리 소모가 큼
bool Sieve_of_Eratosthenes(int x)
{
    // 처음에는 모든 수가 소수인 것으로 초기화
    vector<bool> v(x + 1, true);

    for(int i = 2;i <= (int)sqrt(x);i++)
    {
		// 소수라면 그 수의 배수는 모두 false로 바꿈
        if (v[i] == true)
        {
            int j = 2;
            while (j * i <= x)
            {
                v[j * i] = false;
                j++;
            }
        }
    }

    for(int i = 2;i <= x;i++)
        if(v[i] == true)
            cout<<i<<" ";
    cout<<endl;

    return 0;
}

int main()
{
    Sieve_of_Eratosthenes(26);
}


