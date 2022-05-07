#include <vector>
#include <algorithm>
#include <queue>
#include <iostream>
using namespace std;

bool watch(int x, int y, int dir, vector<vector<char>> v)
{
    // 왼쪽
    if (dir == 0)
    {
        while (y >= 0)
        {
            if (v[x][y] == 'S')
                return true;
            
            if (v[x][y] == 'O')
                return false;
            y--;
        }
    }
    
    // 오른쪽
    if (dir == 1)
    {
        while (y < v.size())
        {
            if (v[x][y] == 'S')
                return true;
            
            if (v[x][y] == 'O')
                return false;
            y++;
        }
    }
    
    // 위쪽
    if (dir == 2)
    {
        while (x >= 0)
        {
            if (v[x][y] == 'S')
                return true;
            
            if (v[x][y] == 'O')
                return false;
            x--;
        }
    }
    
    // 아래쪽
    if (dir == 3)
    {
        while (y < v.size())
        {
            if (v[x][y] == 'S')
                return true;
            
            if (v[x][y] == 'O')
                return false;
            x++;
        }
    }
    
    return false;
}

bool process(vector<vector<char>> v, vector<pair<int, int>> teacher)
{
    for(int i = 0;i < teacher.size();i++)
    {
        int x = teacher[i].first;
        int y = teacher[i].second;
        
        for(int dir = 0;dir < 4;dir++)
        {
            if (watch(x, y, dir, v))
                return true;
        }
    }
    return false;
}

int main()
{
    // N(복도 크기)
    int N;
    bool found = false;
    
    cin>>N;
    
    vector<vector<char>> v(N, vector<char>(N, ' '));
    vector<pair<int, int>> teacher;
    vector<pair<int, int>> space;
    
    for(int i = 0;i < N;i++)
    {
        for(int j = 0;j < N;j++)
        {
            char temp;
            cin>>temp;
            
            v[i][j] = temp;
            
            // 선생님 공간
            if (temp == 'T')
                teacher.push_back({i, j});
            
            // 장애물을 설치 가능한 공간
            else if (temp == 'X')
                space.push_back({i, j});
        }
    }
    
    vector<bool> binary(space.size());
    fill(binary.end() - 3, binary.end(), true);
    
    do
    {
        for(int i = 0;i < space.size();i++)
        {
            if (binary[i] == true)
            {
                int x = space[i].first;
                int y = space[i].second;
                
                v[x][y] = 'O';
            }
        }
        
        if (!process(v, teacher))
        {
            found = true;
            break;
        }
        
        for(int i = 0;i < space.size();i++)
        {
            if (binary[i] == true)
            {
                int x = space[i].first;
                int y = space[i].second;
                
                v[x][y] = 'X';
            }
        }
    }
    while(next_permutation(binary.begin(), binary.end()));
    
    if (found == true)
        cout<<"YES"<<endl;
    
    else
        cout<<"NO"<<endl;
    
    return 0;
}

