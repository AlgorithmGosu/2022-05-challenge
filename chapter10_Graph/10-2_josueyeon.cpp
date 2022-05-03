#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

// 부모 테이블 초기화
int parent[100001];

// 경로 압축 기법을 사용한 union find
// find 함수를 재귀적으로 호출한 뒤에 부모 테이블을 갱신하는 방법
int findParent(int x)
{
    if (x == parent[x])
        return x;
	// 재귀 연산을 할때 값을 저장해두면 나중에는 한번만에 찾을 수 있음
    else
        return parent[x] = findParent(parent[x]);
}

/*
 경로 압축이 없으면 그냥 재귀 연산만 함
 int findParent(int x)
 {
     if (x == parent[x])
         return x;
     else
         return findParent(parent[x]);
 }
 */

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
    // v(node 수), e(edge 수 == union 연산 횟수)
    int v, e;
    cin>>v>>e;

    // 처음에는 node의 부모를 node 자기 자신으로 설정
    for(int i = 1;i <= v;i++)
        parent[i] = i;

    // union 연산 진행
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

