#include <iostream>
#include <vector>
#include <string>
#include <algorithm>	// sort() STL
using namespace std;

// 이진 탐색(recursive version)
int binary_search(string target, vector<string> arr, int start, int end)
{
    // 재귀 함수 종료 조건
    if (start > end)
        return -1;

    int mid = (start + end) / 2;

    if (arr[mid] == target)
        return mid + 1;

    else if (arr[mid] > target)
        return binary_search(target, arr, start, mid - 1);

    else
        return binary_search(target, arr, mid + 1, end);
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

    sort(v.begin(), v.end());
    cout<<binary_search(target, v, 0, v.size()-1)<<endl;

    return 0;
}

