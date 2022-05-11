#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int parent[100001];

int findParent(int x)
{
    return (x == parent[x] ? x : parent[x] = findParent(parent[x]));
}

void unionParent(int a, int b)
{
    a = findParent(a);
    b = findParent(b);
    
    if (a < b)
        parent[b] = a;
    else
        parent[a] = b;
}
int main()
{
    // G(탑승구 수), P(비행기 수)
    int G, P;
    
    cin>>G>>P;
    
    // {gi, i}
    vector<pair<int, int>> input;
    
    for(int i = 1;i <= P;i++)
    {
        int temp;
        cin>>temp;
        
        input.push_back({temp, i});
    }
    
    for(int i = 1;i <= P;i++)
        parent[i] = i;
    
    sort(input.begin(), input.end());
    
    
    for(auto iter : input)
    {
        int temp = iter.first;
        int idx = iter.second;
        
        for(int i = 1;i <= temp;i++)
        {
            if (idx != i)
            {
                if (findParent(idx) != findParent(i))
                    unionParent(idx, i);
            }
        }
    }
     
    vector<int> res;
    int answer = 0;
    
    for(int i = 1;i <= P;i++)
    {
        int test = parent[i];
        
        bool flag = true;
        for(int j = 0;j < res.size();j++)
        {
            if (res[j] == test)
            {
                flag = false;
                break;
            }
        }
        
        if (flag == true)
        {
            res.push_back(test);
            answer++;
        }
    }
    cout<<answer<<endl;
    
    return 0;
    
}
//4
//3
//4
//1
//1

