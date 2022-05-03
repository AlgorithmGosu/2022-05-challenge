#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

// 부모 테이블 초기화
int parent[100001];

// 경로 압축 사용
int findParent(int x)
{
    return parent[x] = (x == parent[x] ? x : findParent(parent[x]));
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
    // N(0~N 까지의 번호), M(연산 개수)
    int N, M;
    cin>>N>>M;

	// 결과 저장 vector
    vector<string> result;
    
    for(int i = 1;i <= N;i++)
        parent[i] = i;
    
    for(int i = 0;i < M;i++)
    {
        int a, b, c;
        cin>>a>>b>>c;
        
        // union 연산
        if (a == 0)
        {
            unionParent(b, c);
        }
        
        // 같은 팀 여부 확인
        else if (a == 1)
        {
            if (findParent(b) == findParent(c))
                result.push_back("YES");
            else
                result.push_back("NO");
        }
    }
    
    for(string iter: result)
        cout<<iter<<endl;
    
    return 0;
}
