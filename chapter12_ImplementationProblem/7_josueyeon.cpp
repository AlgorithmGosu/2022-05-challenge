#include <iostream>
#include <string>
using namespace std;

int main()
{
    // N(숫자)
    int N;
    int left_sum = 0, right_sum = 0;
    string str;
    
    cin>>N;
    
	// string으로 변환해서 계산
    str = to_string(N);
    for(int i = 0;i < str.size();i++)
    {
        if (i < str.size() / 2)
            left_sum += str[i] - 48;
        else
            right_sum += str[i] - 48;
    }

    if (left_sum == right_sum)
        cout<<"LUCKY"<<endl;
    else
        cout<<"READY"<<endl;
    
    return 0;
}

