#include <iostream>
#include <vector>
using namespace std;

int main()
{
    vector<int> v1 = {1, 3, 5};
    vector<int> v2 = {2, 4, 6, 8};
    
    vector<int> result;
    
    int i = 0;  // v1
    int j = 0;  // v2
    
    while (i < v1.size() && j < v2.size())
    {
        if (v1[i] < v2[j])
        {
            result.push_back(v1[i]);
            i++;
        }
        else
        {
            result.push_back(v2[j]);
            j++;
        }
    }
    while (i < v1.size())
    {
        result.push_back(v1[i]);
        i++;
    }
    while (j < v2.size())
    {
        result.push_back(v2[j]);
        j++;
    }
    
    for(int iter: result)
        cout<<iter<<" ";
    cout<<endl;
    
    return 0;
}

