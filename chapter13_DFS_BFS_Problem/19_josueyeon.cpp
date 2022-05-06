#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

int main()
{
    // N(수의 개수)
    int N;
    cin>>N;
    
    vector<int> num;
    for(int i = 0;i < N;i++)
    {
        int temp;
        cin>>temp;
        
        num.push_back(temp);
    }
    
    // 더하기, 빼기, 곱하기, 나누기
    vector<int> oper;
    for(int i = 0;i < 4;i++)
    {
        int temp;
        cin>>temp;
        
        for(int j = 0;j < temp;j++)
            oper.push_back(i);
    }
    
    int minV = 1e9;
    int maxV= -1e9;
    
	// 연산자를 순열로 만들어서 계산
    do
    {
        int sum = num[0];
        for(int i = 0;i < N - 1;i++)
        {
            if (oper[i] == 0)
                sum += num[i + 1];

            else if (oper[i] == 1)
                sum -= num[i + 1];
            
            else if (oper[i] == 2)
                sum *= num[i + 1];
            
            else if (oper[i] == 3)
                sum /= num[i + 1];
            
        }
        minV= min(minV, sum);
        maxV = max(maxV, sum);
    } while(next_permutation(oper.begin(), oper.end()));
    
    cout<<maxV<<endl<<minV<<endl;
    
    return 0;
}
    

