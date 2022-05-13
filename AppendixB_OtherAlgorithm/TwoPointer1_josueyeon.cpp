#include <iostream>
#include <vector>
using namespace std;
 
int main()
{
    // 수열
    vector<int> v = {1, 2, 3, 2, 5};
    int target = 5;
    int count = 0;
    
    int end = 0;
    int sum = 0;
    
    for(int start = 0;start < v.size();start++)
    {
        // 합이 목표보다 작을 때 end 증가
        while (sum < target && end < v.size())
        {
            sum += v[end];
            end++;
        }
        
        if (sum == target)
            count++;
        
        // 합이 목표보다 크거나 수열을 찾았으면 start를 증가
        sum -= v[start];
    }
    cout<<count<<endl;
    
    return 0;
}

