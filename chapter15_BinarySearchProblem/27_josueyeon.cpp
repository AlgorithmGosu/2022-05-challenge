#include <vector>
#include <iostream>
using namespace std;

int result = 0;
int BinarySearch(vector<int> v, int target)
{
    int start = 0;
    int end = v.size() - 1;
    
    while (start <= end)
    {
        int middle = (start + end) / 2;
        
        if (v[middle] == target)
            return middle;
        
        else if (v[middle] > target)
            end = middle - 1;
        else
            start = middle + 1;
    }
    return -1;
}

void countX(vector<int> &v, int target, int index, int offset)
{
    if (index < 0 || index >= v.size())
        return;
    
    if (v[index] == target)
    {
        result++;
        if (offset == 0)
        {
            countX(v, target, index + 1, 1);
            countX(v, target, index - 1, 2);
        }
        
        if (offset == 1)
            countX(v, target, index + 1, 1);
        
        else if (offset == 2)
            countX(v, target, index - 1, 2);
    }
}

int main()
{
    // N(원소 수), X(찾는 수)
    int N, x;
    
    cin>>N>>x;
    
    vector<int> v;
    for(int i = 0;i < N;i++)
    {
        int temp;
        cin>>temp;
        
        v.push_back(temp);
    }
    
    int idx = BinarySearch(v, x);
    
    // 없는 경우
    if (idx == -1)
    {
        cout<<idx<<endl;
        return 0;
    }
    
    // 있는 경우
    countX(v, x, idx, 0);
        
    cout<<result<<endl;
    
    return 0;
    
}

