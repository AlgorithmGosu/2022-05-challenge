#include <vector>
#include <iostream>
using namespace std;

int main()
{
    // N(배열 원소 수), K(최대 바꿔치기 횟수)
    int N, K;
    cin>>N>>K;
    
    vector<int> A(N);
    vector<int> B(N);
    
    for(int i = 0;i < 2;i++)
    {
        for(int j = 0;j < N;j++)
        {
            if (i == 0)
                cin>>A[j];
            else
                cin>>B[j];
        }
    }
    
    //A는 오름차순, B는 내림차순
    sort(A.begin(), A.end());
    sort(B.begin(), B.end(), greater<>());
    
    for(int i = 0;i < K;i++)
    {
		// 더 이상 교체할 게 없으면 종료
        if (A[0] >= B[0])
            break;
        else
        {
			// 교체하고 나면 다시 정렬해야함
            swap(A[0], B[0]);
            
            sort(A.begin(), A.end());
            sort(B.begin(), B.end(), greater<>());
        }
    }
    
	// 오버플로우 처리를 위해 long type으로 계산
    long sum = 0;
    
    for(int i = 0;i < N;i++)
        sum += A[i];
    
    cout<<sum<<endl;
    
    return 0;
}

// 답지

int n, k;
vector<int> a, b;

bool compare(int x, int y) {
    return x > y;
}

int main(void) {
    // N과 K를 입력받기
    cin >> n >> k;
    // 배열 A의 모든 원소를 입력받기
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        a.push_back(x);
    }
    // 배열 B의 모든 원소를 입력받기
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        b.push_back(x);
    }
    // 배열 A는 오름차순 정렬 수행
    sort(a.begin(), a.end());
    // 배열 B는 내림차순 정렬 수행
    sort(b.begin(), b.end(), compare);

    // 첫 번째 인덱스부터 확인하며, 두 배열의 원소를 최대 K번 비교
    for (int i = 0; i < k; i++) {
        // A의 원소가 B의 원소보다 작은 경우
        if (a[i] < b[i]) swap(a[i], b[i]); // 두 원소를 교체
        // A의 원소가 B의 원소보다 크거나 같을 때, 반복문을 탈출
        else break;
    }

    // 배열 A의 모든 원소의 합을 출력
    long long result = 0;
    for (int i = 0; i < n; i++) {
        result += a[i];
    }
    cout << result << '\n';
}
