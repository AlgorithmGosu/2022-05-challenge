#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int n;
	vector<int>	result;
	int d[101];	// dp 테이블

	cin >> n;

    for (int i = 0; i < n; i++) {
        int temp;
        cin >> temp;

        result.push_back(x);
    }

    d[0] = arr[0];
    d[1] = max(result[0], result[1]);

    for (int i = 2; i < n; i++) {
        d[i] = max(d[i - 1], d[i - 2] + result[i]);
    }

    cout << d[n - 1];

	return 0;
}
