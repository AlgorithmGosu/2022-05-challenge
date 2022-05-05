#include <string>
#include <vector>

using namespace std;

int solution(string s) {
    int answer = 0;
    
    int minValue = s.size();
    int ratio = 1;
    
    string result = "";
    while (ratio < minValue)
    {
        result = "";
        
        int count = 0;
        string str = s.substr(0, ratio);
        
        for(int j = 0;j < s.size();j += ratio)
        {
            if (str == s.substr(j, ratio))
                count++;
            else
            {
                if (count == 1)
                {
                    result += str;
                }
                else
                {
                    result += to_string(count);
                    result += str;
                }
                str = s.substr(j, ratio);
                j -= ratio;
                count = 0;
            }
        }
        if (count == 1)
        {
            result += str;
        }
        else
        {
            result += to_string(count);
            result += str;
        }
        if (result.size() < minValue)
            minValue = result.size();
        ratio++;
    }
    answer = minValue;
    return answer;
}
