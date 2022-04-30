#include <iostream>
#include <vector>
#include <string>
#include <algorithm>	// sort() STL
using namespace std;

// 이진 탐색(no recursive version)
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

    sort(v.begin(), v.end());

	// 이진 탐색을 위한 변수들	
    int result = -1;
    int start = 0;
    int end = v.size() - 1;

	// 반복문으로 구현한 이진 탐색
    while(start <= end)
    {
        int mid = (start + end) / 2;

        if(v[mid] == target)
        {
            result = mid + 1;
            break;
        }

        else if (v[mid] > target)
            end = mid - 1;

        else
            start = mid + 1;
    }

    cout<<result<<endl;

    return 0;
}

