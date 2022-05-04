#include <iostream>
#include <string>
#include <vector>
using namespace std;

// 내가 푼 것
int solution(vector<int> food_times, long long k) {
    int answer = 0;

    int len = food_times.size();
    int limit;

    while(k-- >= 0)
    {
        limit = 0;
        while (food_times[answer] == 0)
        {
            limit++;
            if (limit == len)
                return -1;
            answer++;
        }

        food_times[answer] = food_times[answer] - 1;
        answer = (answer + 1) % len;
    }


    return answer;
}

// 답
int solution(vector<int> food_times, long long k)
{
    long long summary = 0;
    for(int i = 0;i < food_times.size();i++)
        summary += food_times[i];

    if (summary <= k)
        return -1;

    priority_queue<pair<int, int>> pq;
    for(int i = 0;i < food_times.size();i++)
        pq.push({food_times[i] * -1, i + 1});

    summary = 0;
    long long prev = 0;
    long long len = food_times.size();

    while (summary + (((pq.top().first * -1) - prev) * len) <= k)
    {
        int now = pq.top().first * -1;
        pq.pop();

        summary += (now - prev) * len;
        len -= 1;
        prev = now;
    }

    vector<pair<int, int>> result;
    while(!pq.empty())
    {
        int food_times = pq.top().first * -1;
        int num = pq.top().second;

        pq.pop();
        result.push_back({food_times, num});
    }
    sort(result.begin(), result.end(), greater<>());

    return result[(k - summary) % len].second;
}

