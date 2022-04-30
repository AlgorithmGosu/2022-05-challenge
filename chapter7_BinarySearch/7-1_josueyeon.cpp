#include <iostream>
#include <vector>
#include <string>
using namespace std;

// 순차 탐색
int sequential_search(string target, vector<string> arr)
{
	// vector를 돌면서 같은지 비교
    for(int i = 0;i < arr.size();i++)
    {
        if (arr[i] == target)
            return i + 1;
    }

	// 없는 경우
    return -1;
}

int main(void)
{
    cout<<"생성할 원소 개수를 입력한 다음 한 칸 띄고 찾을 문자열을 입력하세요.\n";

    int n;
    string target;
    cin>>n>>target;

    vector<string> v;

    cout<<"앞서 적은 원소 개수만큼 문자열을 입력하세요. 구분은 띄어쓰기 입니다.\n";
    for(int i = 0;i < n;i++)
    {
        string temp;
        cin>>temp;

        v.push_back(temp);
    }

    cout<<sequential_search(target, v)<<endl;

    return 0;
}

