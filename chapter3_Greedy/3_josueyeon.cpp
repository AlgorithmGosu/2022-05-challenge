#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    // N(행), M(열)
    int N, M;
    int value, result = 0;

    cin>>N>>M;

    for(int i = 0;i < N;i++)
    {
        value = 100000;
        for(int j = 0;j < M;j++)
        {
            int temp;
            cin>>temp;

            value = min(value, temp);
        }
        result = max(result, value);
    }
    cout<<result<<endl;

    return 0;
}
