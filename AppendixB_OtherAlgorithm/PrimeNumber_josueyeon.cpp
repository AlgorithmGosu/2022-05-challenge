#include <iostream>
#include <cmath>
using namespace std;

bool isPrimeNumber(int x)
{
    // 제곱근까지 확인하면 됨
    for(int i = 2;i <= (int)sqrt(x);i++)
    {
        if (x % i == 0)
            return false;
    }
    return true;
}

