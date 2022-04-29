#include <vector>
#include <iostream>
#include <queue>
using namespace std;

// 정렬 안써도 max heap 자료구조 쓰면 정렬해서 넣기 때문에 가장 큰 데이터부터 출력됨
int main()
{
    // 수열의 수
    int N;
    cin>>N;
    
	// max heap은 우선순위 큐로 구현되어 있음
    priority_queue<int> pq;
    
    for(int i = 0;i < N;i++)
    {
        int temp;
        cin>>temp;
        
        pq.push(temp);
    }
    
    for(int i = 0;i < N;i++)
    {
        int temp = pq.top();
        pq.pop();
        cout<<temp<<" ";
    }
    return 0;
}

// sort 라이브러리 이용한 버전

int main()
{
    // 수열의 수
    int N;
    cin>>N;
    
    vector<int> v(N);
    for(int i = 0;i < N;i++)
        cin>>v[i];
    
    // greater<>() 임시 객체를 쓰면 내림차순, less<>()는 오름차순 정렬 가능인데 있으나 마나..
    // 왜냐면 기본이 오름차순이잖슴~
    sort(v.begin(), v.end(), greater<>());
    
    for(int iter:v)
        cout<<iter<<" ";
    
    return 0;
}

// 답지
#include <bits/stdc++.h>

using namespace std;

int n;
vector<int> v;

bool compare(int a, int b) {
    return a > b;
}

int main(void) {
    cin >> n;

    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        v.push_back(x);
    }

    sort(v.begin(), v.end(), compare);

    for(int i = 0; i < n; i++) {
        cout << v[i] << ' ';
    }
}
