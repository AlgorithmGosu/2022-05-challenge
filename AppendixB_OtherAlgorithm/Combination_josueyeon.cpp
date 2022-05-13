#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// 조합은 next_permutation을 응용해서 쓰면 됨
// 결국 조합은 원소를 선택할건지(1), 선택하지 않을것인지(0) 나열하는 것이다.
// 즉 0과 1을 순열로 나열하고 1인 부분의 원소만 뽑으면 그게 바로 조합이라는 것
int main()
{
    // 6C3 만들기
    vector<int> v = {1, 2, 3, 4, 5, 6};
    vector<int> check = {0, 0, 0, 1, 1, 1};
    
    int count = 0;
    do
    {
        count++;
        for(int i = 0;i < check.size();i++)
        {
            if (check[i] == 1)
                cout<<v[i]<<" ";
        }
        cout<<endl;
    } while(next_permutation(check.begin(), check.end()));
    
    cout<<"총 조합의 개수: "<<count<<endl;
    return 0;
}

