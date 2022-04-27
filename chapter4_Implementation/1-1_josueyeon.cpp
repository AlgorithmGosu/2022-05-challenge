#include <iostream>
using namespace std;

int main()
{
    // 공간 크기
    int N;
    cin>>N;
    
    // i(행), j(열)
    int i = 1, j = 1;

    // 어짜피 좌표만 바꾸는 것이므로 굳이 배열 생성하지 말고 인덱스만 범위 체크하고 변경해서 메모리 절약
    do
    {
        char temp;
        cin>>temp;
        
        if (temp == 'L' && j - 1 > 0)
            j--;
        else if (temp == 'R' && j + 1 <= N)
            j++;
        else if (temp == 'U' && i - 1 > 0)
            i--;
        else if (temp == 'D' && i + 1 <= N)
            i++;
    } while(getc(stdin) == ' ');

    cout<<i<<" "<<j<<endl;
    
    return 0;
}

// 답안 예시 코드 (인데 마음에 안들어)
void LRUD()
{
    int N;
    string plans;
    int x = 1, y = 1;
    
    // 방향 전환하는 인덱스를 따로 배열로 생성
    int dx[4] = {0, 0, -1, 1};
    int dy[4] = {-1, 1, 0, 0};
    
    char Types[4] = {'L', 'R', 'U', 'D'};
    
    cin>>N;
    cin.ignore();
    
    getline(cin, plans);
    
    for(int i = 0;i < plans.size();i++)
    {
        char plan = plans[i];
        
        int nx = -1, ny = -1;
        for(int j = 0;j < 4;j++)
        {
            if (plan == Types[j])
            {
                nx = x + dx[j];
                ny = y + dy[j];
            }
        }
        
        // 바운더리 체크
        if (nx < 1 || nx > N || ny < 1 || ny > N)
            continue;
        x = nx;
        y = ny;
    }
    
    cout<<x<<" "<<y<<endl;
}

