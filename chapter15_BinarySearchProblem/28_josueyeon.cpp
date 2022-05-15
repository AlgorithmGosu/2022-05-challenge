#include <vector>
#include <iostream>
using namespace std;

int BinarySearch(vector<int> v)
{
    int start = 0;
    int end = v.size() - 1;
    
    while (start <= end)
    {
        int middle = (start + end) / 2;
        
        if (v[middle] == middle)
            return middle;
        
        // 배열의 값이 크면 앞에서 찾아야함
        else if (v[middle] > middle)
            end = middle - 1;
        
        // 배열의 값이 작으면 뒤에서 찾아야함
        else
            start = middle + 1;
    }
    // 없는 경우
    return -1;
}
int main()
{
    // N(원소의 수)
    int N;
    cin>>N;
    
    vector<int> v;
    for(int i = 0;i < N;i++)
    {
        int temp;
        cin>>temp;
        
        v.push_back(temp);
    }
    
    int result = BinarySearch(v);
    
    cout<<result<<endl;
    
    return 0;
}

