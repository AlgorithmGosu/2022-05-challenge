#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

// union-find 알고리즘: 서로소 집합 자료구조

// 부모 테이블
int parent[100001];

int findParent(int x)
{
    // 루트 노드는 node 넘버와 parent table의 값이 같음
    // 루트 노드를 찾을 때까지 재귀적으로 호출
    if (x == parent[x])
        return x;
    else
        return findParent(parent[x]);
}

void unionParent(int a, int b)
{
    a = findParent(a);
    b = findParent(b);

    // node 번호가 낮은 곳에 부모 노드로 연결
    if(a < b)
        parent[b] = a;
    else
        parent[a] = b;
}

int main()
{
    // v(노드의 개수), e(간선의 개수 == Union 연산 횟수)
    int v, e;
    cin>>v>>e;

    // 맨 처음에는 모든 노드의 부모는 자기 자신으로 초기화
    for(int i = 1;i <= v;i++)
        parent[i] = i;

    // union 연산을 입력받음 -> 부모 테이블을 수정
    for(int i = 0;i < e;i++)
    {
        int a, b;
        cin>>a>>b;

        unionParent(a, b);
    }

    cout<<"각 원소가 속한 집합: ";
    for(int i = 1;i <= v;i++)
        cout<<findParent(i)<<" ";
    cout<<endl;

    cout<<"부모 테이블 : ";
    for(int i = 1;i <= v;i++)
        cout<<parent[i]<<" ";
    cout<<endl;

    return 0;
}

