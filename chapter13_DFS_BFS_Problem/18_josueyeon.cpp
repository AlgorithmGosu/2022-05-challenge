#include <string>
#include <vector>
#include <stack>

using namespace std;

int separate_balance(string p)
{
    int left = 0;
    int right = 0;

    for(int i = 0;i < p.size();i++)
    {
        if (p[i] == '(')
            left++;
        else if (p[i] == ')')
            right++;

        if (left == right)
            return i;
    }
    return -1;
}

bool check(string u)
{
    stack<char> s;

    for(int i = 0;i < u.size();i++)
    {
        if (u[i] == '(')
            s.push(u[i]);

        else if (u[i] == ')')
            s.pop();
    }

    return s.empty();
}

string solution(string p) {
    string answer = "";

    // 입력이 비어있으면 빈 문자열
    if (p == "")
        return answer;

    // 문자열을 두개의 균형 잡힌 괄호 문자열로 분리한다
    int idx = separate_balance(p);

    string s1 = p.substr(0, idx + 1);
    string s2 = p.substr(idx + 1);

    // 올바른 문자열이면 저장
    if (check(s1))
        answer += s1 + solution(s2);

    // 올바른 문자열이 아닌 경우
    else
    {
        answer = "(";
        answer += solution(s2);
        answer += ")";
        s1 = s1.substr(1, s2.size() - 2);
        for(int i = 0;i < s1.size();i++)
        {
            if (s1[i] == '(')
                s1[i] = ')';
            else
                s1[i] = '(';
        }
        answer += s1;
    }

    return answer;
}

