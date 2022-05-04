#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    // N(동전 개수)
    int N;
    vector<int> v;
    
    cin>>N;
    for(int i = 0;i < N;i++)
    {
        int temp;
        cin>>temp;
        
        v.push_back(temp);
    }
    
    sort(v.begin(), v.end());
    
    int result = 1;
    for(int i = 0;i < N;i++)
    {
        if (result < v[i])
            break;
        result += v[i];
    }
    
    cout<<result<<endl;
    
    return 0;
}
