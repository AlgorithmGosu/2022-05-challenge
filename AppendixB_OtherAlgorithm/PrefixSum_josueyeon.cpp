#include <iostream>
 #include <vector>
 using namespace std;

int main()
{
    // 수열
    vector<int> v = {10, 20, 30, 40, 50};
    // prefix sum
    int prefixSum[6];
    
    int sum = 0;
    for(int i = 0;i < v.size();i++)
    {
        sum += v[i];
        prefixSum[i + 1] = sum;
    }
    
    int left = 3;
    int right = 4;
    
    cout<<prefixSum[right] - prefixSum[left - 1]<<endl;
    
    return 0;
}

