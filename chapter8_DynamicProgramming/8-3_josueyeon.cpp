#include <iostream>
using namespace std;

long long d[100];

int main()
{
	d[1] = 1;
	d[2] = 1;

	int n = 50;
	
	// 반복문으로 구현한 bottom-up 방식
	for(int i = 0;i < n;i++)
		d[i] = d[i - 1] + d[i - 2];
	
	cout<<d[n];
}

