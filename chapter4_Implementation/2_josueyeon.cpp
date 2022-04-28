#include <string>
#include <iostream>
using namespace std;

// 원래 풀던 것처럼 풀어보기
int main()
{
    string point;
    int row, col;
    int result = 0;

    getline(cin, point); // a1 이렇게 '열행'으로 받음
    // 행, 열 인덱스를 ascii 코드로 변환
    row = point[1] - 48;     // 행
    col = point[0] - 96;    // 열

	// 가능한 방향에 대해서 boundary check하고 result update
    if (1 <= row - 2 && row - 2 <= 8 && 1 <= col + 1 && col + 1 <= 8)
        result++;
    if (1 <= row - 2 && row - 2 <= 8 && 1 <= col - 1 && col - 1 <= 8)
        result++;

    if (1 <= row + 2 && row + 2 <= 8 && 1 <= col + 1 && col + 1 <= 8)
        result++;
    if (1 <= row + 2 && row + 2 <= 8 && 1 <= col - 1 && col - 1 <= 8)
        result++;

    if (1 <= col - 2 && col - 2 <= 8 && 1 <= row + 1 && row + 1 <= 8)
        result++;
    if (1 <= col - 2 && col - 2 <= 8 && 1 <= row - 1 && row - 1 <= 8)
        result++;

    if (1 <= col + 2 && col + 2 <= 8 && 1 <= row + 1 && row + 1 <= 8)
        result++;
    if (1 <= col + 2 && col + 2 <= 8 && 1 <= row - 1 && row - 1 <= 8)
        result++;

    cout<<result<<endl;

    return 0;

}

// 예시 코드처럼 풀어보기
void knight()
{
    string point;
    int row, col;
    int result = 0;

    // 가능한 방향 정의
    int dx[] = {-2, -1, 1, 2, 2, 1, -1, -2};
    int dy[] = {-1, -2, -2, -1, 1, 2, 2, 1};

    getline(cin, point);

    row = point[1] - 48;
    col = point[0] - 96;

    for(int i = 0;i < 8;i++)
    {
        int tempRow = row + dx[i];
        int tempCol = col + dy[i];

        if (tempRow >= 1 && tempRow <= 8 && tempCol >= 1 && tempCol <= 8)
            result++;
    }
    cout<<result<<endl;
}

