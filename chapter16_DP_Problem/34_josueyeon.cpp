#include <vector>
#include <iostream>
using namespace std;

int main()
{
    // N(병사의 수)
    int N;
    vector<int> v;
    
    cin>>N;
    for(int i = 0;i < N;i++)
    {
        int temp;
        cin>>temp;
        
        v.push_back(temp);
    }
    
    int result = 0;
    for(int i = 0;i < v.size() - 1;i++)
    {
        if (v[i] < v[i + 1])
        {
            result++;
            v.erase(v.begin() + i);
            i = 0;
        }
    }
    
    cout<<result<<endl;
    
    return 0;
}

