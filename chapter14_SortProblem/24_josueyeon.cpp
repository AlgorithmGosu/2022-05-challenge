#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

int main()
{
    // 집의 수
    int N;
    cin>>N;
    
    vector<int> v;
    for(int i = 0;i < N;i++)
    {
        int temp;
        cin>>temp;
        
        v.push_back(temp);
    }
    
    sort(v.begin(), v.end());
    
    cout<<v[(v.size() - 1) / 2]<<endl;
    
    return 0;
}

