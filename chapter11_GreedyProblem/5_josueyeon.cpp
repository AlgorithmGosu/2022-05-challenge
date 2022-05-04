#include <iostream>
using namespace std;

int main()
{
    // N(볼링공 개수), M(공의 최대 무게)
    int N, M, result = 0;
    vector<int> v;

    cin>>N>>M;
    for(int i = 0;i < N;i++)
    {
        int temp;
        cin>>temp;

        v.push_back(temp);
    }

	// 값이 같지 않은 경우에만 결과+1
    for(int i = 0;i < N;i++)
    {
        for(int j = i + 1;j < N;j++)
        {
            if (v[i] != v[j])
                result++;
        }
    }
    cout<<result<<endl;

    return 0;
}

