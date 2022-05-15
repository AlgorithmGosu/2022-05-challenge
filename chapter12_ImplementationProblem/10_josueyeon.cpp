#include <string>
#include <vector>

using namespace std;

vector<vector<int>> rotateVec(vector<vector<int>> v)
{
    int r = v.size();
    int c = v[0].size();
    
    vector<vector<int>> result(r, vector<int>(c, 0));
    
    // 열쇠 회전
    for(int i = 0;i < r;i++)
    {
        for(int j = 0;j < c;j++)
        {
            result[j][r - i - 1] = v[i][j];
        }
    }
    
    return result;
}

bool solution(vector<vector<int>> key, vector<vector<int>> lock) {
    bool answer = true;
    
    int keySize = key.size();
    int lockSize = lock.size();
    
    vector<vector<int>> v(lockSize * 3, vector<int>(lockSize * 3, 0));
    
    for(int i = 0;i < lockSize;i++)
    {
        for(int j = 0;j < lockSize;j++)
        {
            v[i + lockSize][j + lockSize] = lock[i][j];
        }
    }
    
    for(int i = 0;i < 4;i++)
    {
        // 열쇠 회전
        key = rotateVec(key);
        for(int x = 0;x < lockSize * 2;x++)
        {
            for(int y = 0;y < lockSize * 2;y++)
            {
                
                // 열쇠 넣어보기
                for(int a = 0;a < keySize;a++)
                {
                    for(int b = 0;b < keySize;b++)
                    {
                        v[x + a][y + b] += key[a][b];
                    }
                }
                
                // 열쇠가 맞는지 확인
                answer = true;
                for(int a = lockSize;a < lockSize * 2;a++)
                {
                    for(int b = lockSize;b < lockSize * 2;b++)
                    {
                        if (v[a][b] != 1)
                        {
                            answer = false;
                            break;
                        }
                    }
                }
                
                if (answer)
                    return true;
                
                // 초기화
                for(int a = 0;a < keySize;a++)
                {
                    for(int b = 0;b < keySize;b++)
                    {
                        v[x + a][y + b] -= key[a][b];
                    }
                }
            }
        }
        
    }
    
    answer = false;
    return answer;
}

