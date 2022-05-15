#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

int getDistance(vector<vector<int>> v, vector<pair<int, int>> chicken)
{
    int sum = 0;
    int minValue = 1e9;
    
    for(int i = 0;i < v.size();i++)
    {
        for(int j = 0;j < v.size();j++)
        {
            if (v[i][j] == 1)
            {
                minValue = 1e9;
                for(int a = 0;a < chicken.size();a++)
                {
                    int x = chicken[a].first;
                    int y = chicken[a].second;
                    
                    minValue = min(minValue, abs(x - i) + abs(y - j));
                }
                sum += minValue;
            }
        }
    }
    return sum;
    
}

int main()
{
    // N(도시 크기), M(최대 치킨집 수)
    int N, M;
    int count = 0;  // 현재 치킨집의 수
    
    cin>>N>>M;
    
    vector<vector<int>> v(N, vector<int>(N, 0));
    vector<pair<int, int>> chicken;
    
    for(int i = 0;i < N;i++)
    {
        for(int j = 0;j < N;j++)
        {
            int temp;
            cin>>temp;
            
            v[i][j] = temp;
            if (temp == 2)
            {
                chicken.push_back({i, j});
                count++;
            }
        }
    }
    
    while (count-- > M)
    {
        // 가장 거리가 컸던거 제거하기
        int tempR = 0;
        int tempC = 0;
        int sum = -1;
        
        int idx = 0;
        int maxV = chicken.size();
        
        while (idx++ < maxV)
        {
            int x = chicken[0].first;
            int y = chicken[0].second;
            
            chicken.erase(chicken.begin() + 0);
            
            int temp = getDistance(v, chicken);
            
            cout<<"x: "<<x<<", y: "<<y<<", temp: "<<temp<<endl;
            
            if (sum < temp)
            {
                tempR = x;
                tempC = y;
                sum = temp;
            }
            chicken.push_back({x, y});
        }
        
        cout<<"count: "<<count<<", x: "<<tempR<<", y: "<<tempC<<endl;
        
        v[tempR][tempC] = 0;
        for(int i = 0;i < chicken.size();i++)
        {
            if (tempR == chicken[i].first && tempC == chicken[i].second)
            {
                chicken.erase(chicken.begin() + i);
                break;
            }
        }
    }
    
    cout<<getDistance(v, chicken)<<endl;
    
    return 0;
    
}

