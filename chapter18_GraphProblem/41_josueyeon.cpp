#include <vector>
#include <iostream>
using namespace std;

// 부모 테이블
int parent[501];

int findParent(int a)
{
    return (parent[a] == a ? a : parent[a] = findParent(parent[a]));
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
    // N(여행지의 수), M(도시의 수)
    int N, M;
    cin>>N>>M;
    
    vector<int> tour;
    
    // node 부모를 자기 자신으로 초기화
    for(int i = 1;i <= N;i++)
        parent[i] = i;
    
    for(int i = 1;i <= N;i++)
    {
        for(int j = 1;j <= N;j++)
        {
            int temp;
            cin>>temp;
            
            if (temp == 1)
                unionParent(i, j);
        }
    }
    
    for(int i = 0;i < M;i++)
    {
        int temp;
        cin>>temp;
        
        tour.push_back(temp);
    }
    
    bool flag = true;
    int ans = -1;
    for(int i = 0;i < M;i++)
    {
        int city = tour[i];
        
        if (ans == -1)
            ans = parent[city];
        
        else if (ans != parent[city])
        {
            flag = false;
            break;
        }
    }
	// 여행지 도시의 부모 node가 다르면 실패
    if (flag == true)
        cout<<"YES"<<endl;
    else
        cout<<"NO"<<endl;
    
    return 0;
}

