#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

int main()
{
    // N(숫자 카드 묶음의 수)
    int N;
    cin>>N;
    
    int sum = 0;
    vector<int> v;
    vector<int> result;
    
    
    for(int i = 0;i < N;i++)
    {
        int temp;
        cin>>temp;
        
        result.push_back(temp);
    }
    
    sort(result.begin(), result.end());
   
   // 두개씩 묶어서 계산	
    while (result.size() >= 2)
    {
        sum += result[0] + result[1];
        
        result.erase(result.begin() + 0);
        result.erase(result.begin() + 0);
        
        result.insert(result.begin(), sum);
        
        sort(result.begin(), result.end());
    }
    
    cout<<sum<<endl;
    
    return 0;
}

// 우선순위 큐를 사용한 버전
int main()
{
    priority_queue<int> pq;
    int N, result = 0;
    
    cin>>N;
    for(int i = 0;i < N;i++)
    {
        int temp;
        cin>>temp;
        
        pq.push(temp * -1);
    }
    
    while (pq.size() != 1)
    {
        int temp1 = pq.top() * -1;
        pq.pop();
        
        int temp2 = pq.top() * -1;
        pq.pop();
        
        int sum = temp1 + temp2;
        result += sum;
        pq.push(sum * -1);
    }
    
    cout<<result<<endl;
    
    return 0;
}

