#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

// disjoint-set으로 사이클 판별하기

// 부모 테이블 초기화
int graph[100001];

int findParent(int x)
{
    return graph[x] = (x == graph[x] ? x : findParent(graph[x]));
}

void unionParent(int a,int b)
{
    a = findParent(a);
    b = findParent(b);
    
    if (a < b)
        graph[b] = a;
    else
        graph[a] = b;
}
int main()
{
    // v(node), e(edge)
    int v, e;
    bool cycle = false;
    cin>>v>>e;
    
    for(int i = 1;i <= v;i++)
        graph[i] = i;
    
    // union 연산
    for(int i = 0;i < e;i++)
    {
        int a, b;
        cin>>a>>b;
        
        // node의 부모가 같은 경우 cycle이 발생한 것임
        if (findParent(a) != findParent(b))
        {
            cycle = true;
            break;
        }
        
        // 아니면 union-find 연산을 진행하면 됨
        else
            unionParent(a, b);
    }
    
    if (cycle)
        cout<<"사이클이 발생했습니다."<<endl;
    else
        cout<<"사이클이 발생하지 않았습니다."<<endl;
    
    return 0;
}

