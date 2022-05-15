#include <iostream>
#include <vector>
using namespace std;

// BFS 안쓰고 그냥 구현한 버전

// 동 서 남 북
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

int main()
{
    // N(시험관 크기), K(바이러스 종류)
    int N, K;

    cin>>N>>K;
    vector<vector<int>> v(200, vector<int>(200, 0));
    vector<pair<int, int>> virus[1001];

    for(int i = 0;i < N;i++)
    {
        for(int j = 0;j < N;j++)
        {
            int temp;
            cin>>temp;

            v[i][j] = temp;
            if (temp != 0)
                virus[temp].push_back({i ,j});

        }
    }

    // S초 후에 (X, Y) 좌표에 있는 바이러스 종류
    int S, X, Y;

    cin>>S>>X>>Y;

    while(S-- > 0)
    {
        for(int vs = 1;vs <= K;vs++)
        {
            int len = virus[vs].size();

            for(int idx = 0;idx < len;idx++)
            {
                int i = virus[vs][idx].first;
                int j = virus[vs][idx].second;

                for(int dir = 0;dir < 4;dir++)
                {
                    int tempR = i + dx[dir];
                    int tempC = j + dy[dir];

                    if (tempR < 0 || tempC < 0 || tempR >= N || tempC >= N)
                        continue;

                    else if (v[tempR][tempC] != 0)
                        continue;

                    else
                    {
                        v[tempR][tempC] = vs;
                        virus[vs].push_back({tempR, tempC});
                    }
                }
            }
        }
    }
    cout<<v[X - 1][Y - 1]<<endl;

    return 0;
}

// BFS 사용한 버전
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

int main()
{
    // N(시험관 크기), K(바이러스 종류)
    int N, K;

    cin>>N>>K;
    vector<vector<int>> v(200, vector<int>(200, 0));
    vector<pair<int, int>> virus[1001];

    for(int i = 0;i < N;i++)
    {
        for(int j = 0;j < N;j++)
        {
            int temp;
            cin>>temp;

            v[i][j] = temp;
            if (temp != 0)
                virus[temp].push_back({i ,j});

        }
    }

    // S초 후에 (X, Y) 좌표에 있는 바이러스 종류
    int S, X, Y;

    cin>>S>>X>>Y;


    queue<pair<pair<int, int>, pair<int, int>>> q;
    for(int i = 1;i <= K;i++)
    {
        for(int j = 0;j < virus[i].size();j++)
        {
            q.push({{virus[i][j].first, virus[i][j].second}, {i, 0}});
        }
    }

    while (!q.empty())
    {
        auto item = q.front();
        q.pop();

        int r = item.first.first;
        int c = item.first.second;
        int vs = item.second.first;
        int time = item.second.second;

        if (time == S)
            break;

        for(int dir = 0;dir < 4;dir++)
        {
            int tempR = r + dx[dir];
            int tempC = c + dy[dir];

            if (tempR < 0 || tempC < 0 || tempR >= N || tempC >= N)
                continue;

            if (v[tempR][tempC] == 0)
            {
                v[tempR][tempC] = vs;
                q.push({{tempR, tempC}, {vs, time + 1}});
            }
        }

    }

    cout<<v[X - 1][Y - 1]<<endl;

    return 0;
}

