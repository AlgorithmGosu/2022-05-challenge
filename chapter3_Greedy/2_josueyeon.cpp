#include <iostream>
#include <queue>
using namespace std;

int main()
{
    priority_queue<int> pq;
    // N(배열 크기), M(더하는 횟수), K(제한 횟수)
    int N, M, K;
    int sum = 0, temp;
    
    cin>>N>>M>>K;
    
    for(int i = 0;i < N;i++)
    {
        cin>>temp;
        pq.push(temp);
    }
    
    int i = 0;
    while (i < M)
    {
        for(int j = 0;j < K;j++)
        {
            sum += pq.top();
            i++;
            if (i == M)
                break;
        }
        temp = pq.top();
        pq.pop();
        sum += pq.top();
        pq.push(temp);
        i++;
        if (i == M)
            break;
    }
    
    cout<<sum;
    
    return 0;
}

// 수열의 반복을 활용한 버전
void greedy_2()
{
    priority_queue<int> pq;
    int N, M, K;
    int sum = 0, temp;
    
    cin>>N>>M>>K;
    
    for(int i = 0;i < N;i++)
    {
        cin>>temp;
        pq.push(temp);
    }
    
    int first = pq.top();
    pq.pop();
    int second = pq.top();
    
    // 가장 큰 수를 더해야 하는 횟수
    temp = (M / (K + 1)) * K  + (M % (K + 1));
    sum += temp * first;
    
    // 남은 횟수 만큼 두번째로 큰 수 더하기
    int count = (M - temp);
    sum += count * second;
    
    cout<<sum;
}

