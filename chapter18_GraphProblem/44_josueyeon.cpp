#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

int parent[100000];

int findParent(int x)
{
    return (parent[x] == x ? x : parent[x] = findParent(parent[x]));
}

void unionParent(int a, int b)
{
    a = findParent(a);
    b = findParent(b);
    
    if (a < b)
        parent[b] = a;
    else
        parent[a] = b;
}

int main()
{
    // N(행성 개수)
    int N;
    cin>>N;
    
    // {행성 번호, {x, y, z 좌표}}
    vector<pair<int, tuple<int, int, int>>> q;
    // {cost, {node1, node2}}
    vector<pair<int, pair<int, int>>> v;
    
    for(int i = 0;i < N;i++)
    {
        int x, y, z;
        cin>>x>>y>>z;
        
        q.push_back({i, {x, y, z}});
    }
    
    for(int i = 0;i < q.size();i++)
    {
        int num = q[i].first;

        int x = get<0>(q[i].second);
        int y = get<1>(q[i].second);
        int z = get<2>(q[i].second);
        
        for(int j = i + 1;j < q.size();j++)
        {
            int num2 = q[j].first;

            int x2 = get<0>(q[j].second);
            int y2 = get<1>(q[j].second);
            int z2 = get<2>(q[j].second);

            v.push_back({min(abs(x2 - x), min(abs(y2 - y), abs(z2 - z))), {num, num2}});
        }
    }
    
    for(int i = 0;i < N;i++)
        parent[i] = i;
    
    sort(v.begin(), v.end());
    
    int result = 0;
    for(int i = 0;i < v.size();i++)
    {
        int cost = v[i].first;
        
        int a = v[i].second.first;
        int b = v[i].second.second;
        
        if (findParent(a) != findParent(b))
        {
            unionParent(a, b);
            result += cost;
        }
    }
    
    cout<<result<<endl;
    
    return 0;
}

// x, y, z 좌표에 대해 따로 vector를 설정하는 구현
int main()
{
    // N(행성 개수)
    int N;
    cin>>N;

    // {cost, {node1, node2}}
    vector<pair<int, pair<int, int>>> v;

    vector<pair<int, int> > x;
    vector<pair<int, int> > y;
    vector<pair<int, int> > z;

    for (int i = 1; i <= N; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        x.push_back({a, i});
        y.push_back({b, i});
        z.push_back({c, i});
    }

    sort(x.begin(), x.end());
    sort(y.begin(), y.end());
    sort(z.begin(), z.end());


    for (int i = 0; i < N - 1; i++) {
        v.push_back({x[i + 1].first - x[i].first, {x[i].second, x[i + 1].second}});
        v.push_back({y[i + 1].first - y[i].first, {y[i].second, y[i + 1].second}});
        v.push_back({z[i + 1].first - z[i].first, {z[i].second, z[i + 1].second}});
    }

    for(int i = 0;i < N;i++)
        parent[i] = i;

    sort(v.begin(), v.end());

    int result = 0;
    for(int i = 0;i < v.size();i++)
    {
        int cost = v[i].first;

        int a = v[i].second.first;
        int b = v[i].second.second;

        if (findParent(a) != findParent(b))
        {
            unionParent(a, b);
            result += cost;
        }
    }

    cout<<result<<endl;

    return 0;
}

