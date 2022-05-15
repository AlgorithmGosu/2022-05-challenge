#include <vector>
#include <iostream>
using namespace std;

// 모두와 연결되어 있으면 순위를 알 수 있고 아닌 경우는 알 수 없음
// 그래서 플로이드 알고리즘 써서 연결되어 있는지 확인

int main()
{
    // N(학생 수), M(비교 횟수)
    int N, M;
    int graph[501][501];
    
    cin>>N>>M;
    
    for(int i = 0;i < 501;i++)
    {
        for(int j = 0;j < 501;j++)
        {
            if (i == j)
                graph[i][j] = 0;
            else
                graph[i][j] = 1e9;
        }
    }
    
    for(int i = 0;i < M;i++)
    {
        int a, b;
        cin>>a>>b;
        
        graph[a][b] = 1;
    }
    
    for(int k = 1;k <= N;k++)
    {
        for(int i = 1;i <= N;i++)
        {
            for(int j = 1;j <= N;j++)
            {
                graph[i][j] = min(graph[i][j], graph[i][k] + graph[k][j]);
            }
        }
    }
    
    int result = 0;

	for(int i = 1;i <= N;i++)
    {
        bool flag = true;

        for(int j = 1;j <= N;j++)
        {
			// 둘 다 1e9 면 연결이 없으니까 값을 증가하지 않음
            if (graph[i][j] == 1e9 && graph[j][i] == 1e9)
            {
                flag = false;
                break;
            }
        }

        if (flag == true)
            result++;
    }

    cout<<result<<endl;
    
    return 0;
}

