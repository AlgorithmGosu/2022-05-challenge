#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    vector<int> v = {1, 2, 3};
    
    // next_permutation은 내부적으로 "<" 연산자를 사용하기 때문에 정렬을 해야 모든 경우를 구할 수 있다.
    do
    {
        for(int iter : v)
            cout<<iter<<" ";
        cout<<endl;
    } while(next_permutation(v.begin(), v.end()));
    
    return 0;
}
