#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    // X(입력 정수)
    int X, result[30001];
    cin>>X;

	// bottom-up 방식
    for(int i = 2;i <= X;i++)
    {
        result[i] = result[i - 1] + 1;

        if (i % 2 == 0)
            result[i] = min(result[i], result[i / 2] + 1);

        if (i % 3 == 0)
            result[i] = min(result[i], result[i / 3] + 1);

        if (i % 5 == 0)
            result[i] = min(result[i], result[i / 5] + 1);
    }

    cout<<result[X]<<endl;

    return 0;
}


