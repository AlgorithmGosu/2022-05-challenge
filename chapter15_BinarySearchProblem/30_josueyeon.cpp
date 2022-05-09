#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<string> words, vector<string> queries) {
    vector<int> answer;
    
    for(int i = 0;i < queries.size();i++)
    {
        string target = queries[i];
        
        int result = 0;
        for(int j = 0;j < words.size();j++)
        {
            string str = words[j];
            
            if (target.size() == str.size())
            {
                bool flag = true;
                
                for(int idx = 0;idx < target.size();idx++)
                {
                    if (target[idx] != '?' && str[idx] != target[idx])
                    {
                        flag = false;
                        break;
                    }
                }
                if (flag == true)
                    result++;
            }
        }
        
        answer.push_back(result);
    }
    
    return answer;
}

// 이진 탐색 활용 버전
vector<string> arr[10001];
vector<string> arr_reverse[10001];
int result = 0;

int BinarySearch(vector<string> v, string target, int len)
{
    int start = 0;
    int end = v.size() - 1;

    while (start <= end)
    {
        int mid = (start + end) / 2;
        bool flag = false;

        for(int i = 0;i < len;i++)
        {
            if (v[mid][i] > target[i])
            {
                flag = true;
                end = mid - 1;
            }
            else if (v[mid][i] < target[i])
            {
                flag = true;
                start = mid + 1;
            }
        }

        if (flag == false)
            return mid;
    }
    return -1;
}

void countX(vector<string> v, string target, int index, int len, int offset)
{
    if (index < 0 || index >= v.size())
        return;

    bool flag = false;

    for(int i = 0;i < len;i++)
    {
        if (v[index][i] > target[i])
        {
            flag = true;
            break;
        }

        else if (v[index][i] < target[i])
        {
            flag = true;
            break;
        }
    }

    if (flag == false)
    {
        result++;
        if (offset == 0)
        {
            countX(v, target, index + 1, len, 1);
            countX(v, target, index - 1, len, 2);
        }

        if (offset == 1)
            countX(v, target, index + 1, len, 1);

        else if (offset == 2)
            countX(v, target, index - 1, len, 2);
    }
}

vector<int> solution(vector<string> words, vector<string> queries)
{
    vector<int> answer;

    for(int i = 0;i < words.size();i++)
    {
        string temp = words[i];

        arr[temp.size()].push_back(temp);

        reverse(temp.begin(), temp.end());
        arr_reverse[temp.size()].push_back(temp);
    }

    // 정렬
    for(int i = 0;i < 10001;i++)
    {
        sort(arr[i].begin(), arr[i].end());
        sort(arr_reverse[i].begin(), arr_reverse[i].end());
    }

    for(int i = 0;i < queries.size();i++)
    {
        string temp = queries[i];


        if (temp[0] == '?')
        {
            reverse(temp.begin(), temp.end());

            int len = 0;
            while (len < temp.size())
            {
                if (temp[len] == '?')
                    break;
                len++;
            }

            int idx = BinarySearch(arr_reverse[temp.size()], temp, len);

            if (idx == -1)
                answer.push_back(0);

            else
            {
                result = 0;
                countX(arr_reverse[temp.size()], temp, idx, len, 0);
                answer.push_back(result);
            }
        }

        else
        {
            int len = 0;
            while (len < temp.size())
            {
                if (temp[len] == '?')
                    break;
                len++;
            }

            int idx = BinarySearch(arr[temp.size()], temp, len);

            if (idx == -1)
                answer.push_back(0);

            else
            {
                result = 0;
                countX(arr[temp.size()], temp, idx, len, 0);
                answer.push_back(result);
            }
        }

    }
    return answer;
}
