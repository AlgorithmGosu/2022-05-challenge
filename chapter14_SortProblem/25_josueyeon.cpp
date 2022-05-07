#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(pair<double, int> a, pair<double, int> b)
{
    if (a.first == b.first)
        return a.second < b.second;
    
    return a.first > b.first;
}

vector<int> solution(int N, vector<int> stages) {
    vector<int> answer;
    
    vector<pair<double, int>> people(N + 1);
    
    for(int i = 1;i <= N;i++)
    {
        double count = 0;
        double sum = 0;
        
        for(int j = 0;j < stages.size();j++)
        {
            if (stages[j] >= i)
            {
                sum++;
                if (stages[j] == i)
                    count++;
            }
        }
		// 예외 처리		
		if (sum == 0)
            people[i] = {0.0, i};
        else
            people[i] = {count / sum, i};
    }
        
    sort(people.begin() + 1, people.end(), compare);
    
    for(int i = 1;i <= N;i++)
        answer.push_back(people[i].second);

    return answer;
}
