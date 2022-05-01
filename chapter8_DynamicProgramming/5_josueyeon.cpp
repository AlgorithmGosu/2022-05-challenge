#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	// N(화폐 종류), M(합)
	int N, M;
	cin>>N>>M;

	vector<int> result;

	for(int i = 0;i < N;i++)
	{
		int temp;
		cin>>temp;

		result.push_back(temp);
	}

	vector<int> d(M + 1, 10001);

	d[0] = 0;
	for(int i = 0;i < N;i++)
	{
		for(int j = result[i];j <= M;j++)
		{
			// 이미 계산 했던 경우
			if (d[j - result[i]] != 10001)
				d[j] = min(d[j], d[j - arr[i]] + 1);
		}
	}

	// 계산 할 수 없는 경우 -1 출력
	if (d[M] == 10001)
		cout<<-1<<endl;

	else
		cout<<d[M]<<endl;

	return 0;
}


