#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    // N(모험가 수)
    int N, index = 0;
    int result = 0;
    vector<int> v;

    cin>>N;
    for(int i = 0;i < N;i++)
    {
        int temp;
        cin>>temp;

        v.push_back(temp);
    }

    sort(v.begin(), v.end(), greater<>());

    while(index < N)
    {
        index += v[index];
        result++;
    }
    cout<<result<<endl;

    return 0;
}

// 답안 코드

int n;
vector<int> arr;

int main()
{
	cin>>n;

	for(int i = 0;i < n;i++)
	{
		int x;
		cin>>x;

		arr.push_back(x);
	}

	// 정렬해서 공포도를 낮은 것부터 확인
	sort(arr.begin(), arr.end());

	int result = 0;
	int count = 0;

	for(int i = 0;i < n;i++)
	{
		// 현재 그룹에 모험가를 포함하고 그룹 결성
		count++;
		if(count >= arr[i])
		{
			result++;
			count = 0;
		}
	}

	cout<<result<<endl;

	return 0;
}
