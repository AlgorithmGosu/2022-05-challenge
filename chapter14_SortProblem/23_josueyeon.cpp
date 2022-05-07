#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <tuple>
using namespace std;

bool compare(tuple<string, int, int, int> v1, tuple<string, int, int, int> v2)
{
    // 국어가 같으면
    if(get<1>(v1) == get<1>(v2))
    {
        // 영어가 같으면
        if (get<2>(v1) == get<2>(v2))
        {
            // 모든 점수가 같으면
            if (get<3>(v1) == get<3>(v2))
            {
                // 이름
                return get<0>(v1) < get<0>(v2);
            }
            else
                return get<3>(v1) > get<3>(v2);
        }
        else
            return get<2>(v1) < get<2>(v2);
    }
    else
        return get<1>(v1) > get<1>(v2);
}

int main()
{
    // 학생 수 N
    int N;
    cin>>N;
    
    vector<tuple<string, int, int, int>> v;
    
    for(int i = 0 ;i < N;i++)
    {
        // 이름, 국어, 영어, 수학
        string name;
        int a, b, c;
        cin>>name>>a>>b>>c;
   
        v.push_back({name, a, b, c});
    }
    
    sort(v.begin(), v.end(), compare);
    
    for(auto iter: v)
        cout<<get<0>(iter)<<endl;
    
    return 0;
}

