#include <iostream>
#include <vector>
using namespace std;

int main()
{
    // N(세로), M(가로)
    int N, M;
    // 위치 좌표: row(행), col(열), dir(방향)
    int row, col, dir;
    // 결과
    int result = 1;
    
    // 북 서 남 동 (반시계 방향이니까)		
    int dx[4] = {-1, 0, 1, 0};
    int dy[4] = {0, -1, 0, 1};
    
    cin>>N>>M;
    cin>>row>>col>>dir;
    
    vector<vector<int>> v(N, vector<int>(M, 0));
    
    for(int i = 0;i < N;i++)
    {
        for(int j = 0;j < M;j++)
        {
            int temp;
            cin>>temp;
            
            v[i][j] = temp;
        }
    }

    v[row][col] = -1;
    
    // 몇번 돌았는지
    int limit = 0;
    
    while(1)
    {
        // 왼쪽으로 회전
        dir = (dir + 1) % 4;
        
        int tempRow = row + dx[dir];
        int tempCol = col + dy[dir];
        
        if (v[tempRow][tempCol] == 0)
        {
            v[tempRow][tempCol] = -1;
            row = tempRow;
            col = tempCol;
            result++;
            limit = 0;
            continue;
        }
        
        // 방문 했으면 그냥 회전만 하면 되니까 회전 수 증가
        else
        {
            limit++;
        }
        
        // 360도 돌았는데 갈 곳이 없으면 뒤로 가기
        if (limit == 4)
        {
            tempRow = row - dx[dir];
            tempCol = col - dy[dir];
            
            // 바다면 루프 종료
            if (v[tempRow][tempCol] == 1)
                break;
            
            else
            {
                row = tempRow;
                col = tempCol;
                limit = 0;
            }
        }
    }
    cout<<result<<endl;
    
    return 0;
}

