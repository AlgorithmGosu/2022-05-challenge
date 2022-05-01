#include <iostream>
using namespace std;

// 이전 결과를 저장해서, 같은 연산을 반복하지 않도록 함 : 메모이제이션
long long d[100];

long long fibonacci(int n)
{
	if (n <= 2)
		return 1;

	// 계산 했던 적이 있으면 그 결과를 반환
	if (d[x] != 0)
		return d[x];

	else
	{
		d[x] = fibonacci(n - 1) + fibonacci(n - 2);
		return d[x];
	}
}

int main()
{
	cout<<fibonacci(50);
}
