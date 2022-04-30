#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int binary_search(int target, vector<int> v, int start, int end, int &value)
{
    int result = 0;
    
	// 종료 조건
    if (start > end)
        return value;
    
    int mid = (start + end) / 2;
    
	// 절단된 이후의 값을 계산
    for(int i = 0;i < v.size();i++)
    {
        if (v[i] <= v[mid])
            continue;
        
        result += v[i] - v[mid];
    }

	// target 이상이면 값을 이전 값보다 큰지 계산해서 넣기
    if (result >= target)
    {
        if (value <= v[mid])
            value = v[mid];
        return binary_search(target, v, mid + 1, end, value);
    }

	// 아니라면 중간보다 작은 곳에서 탐색 시작
    else
    {
        return binary_search(target, v, start, mid - 1, value);
    }
}
int main()
{
    // N(떡의 갯수), M(목표 값)
    int N, M, result = 0;
    // 떡의 길이 저장 벡터
    vector<int> v;
    
    cin>>N>>M;
    for(int i = 0;i < N;i++)
    {
        int temp;
        cin>>temp;
        
        v.push_back(temp);
    }
    
    sort(v.begin(), v.end());

    binary_search(M, v, 0, v.size() - 1, result);
    
    cout<<result<<endl;
    
    return 0;
}
