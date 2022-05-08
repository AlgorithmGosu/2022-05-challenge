#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int BinarySearch(vector<int> v, int C)
{
    int start = 1;
    int end = v[v.size() - 1] - v[0];
    
    int result = 0;
    
    while (start <= end)
    {
        // 가장 가까운 두 공유기 사이의 거리
        int middle = (start + end) / 2;
        
        int value = v[0];
        int count = 1;
        for(int i = 1;i < v.size();i++)
        {
			// 최대면 값 바꾸기
            if (v[i] >= value + middle)
            {
                value = v[i];
                count++;
            }
        }

        // C개 이상 설치 가능하면 거리 증가
        if (count >= C)
        {
            start = middle + 1;
            result = middle;
        }
        else
            end = middle - 1;
    }
    
    return result;
    
}
int main()
{
    // N(집의 개수), C(공유기의 개수)
    int N, C;
    cin>>N>>C;
    
    vector<int> v;
    for(int i = 0;i < N;i++)
    {
        int temp;
        cin>>temp;
        
        v.push_back(temp);
    }
    
    sort(v.begin(), v.end());
    
    int result = BinarySearch(v, C);
    
    cout<<result<<endl;
    
    return 0;
}

