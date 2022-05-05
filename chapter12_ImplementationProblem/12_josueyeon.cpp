#include <string>
#include <vector>

using namespace std;

bool possible(vector<vector<int>> answer)
{
    for(int i = 0;i < answer.size();i++)
    {
        // 좌표
        int x = answer[i][0];
        int y = answer[i][1];
        
        // sort(0: 기둥, 1: 보)
        int sort = answer[i][2];
        
        // 기둥의 조건: 바닥 위, 보의 한쪽 끝 부부, 다른 기둥 위
        if (sort == 0)
        {
            bool check = false;
            
            // 바닥인 경우
            if (y == 0)
                check = true;
            
            for(int j = 0;j < answer.size();j++)
            {
                // 보의 왼쪽 끝 부분
                if (x - 1 == answer[j][0] && y == answer[j][1] && answer[j][2] == 1)
                    check = true;
                
                // 보의 오른쪽 끝 부분
                if (x == answer[j][0] && y == answer[j][1] && answer[j][2] == 1)
                    check = true;
                
                // 다른 기둥 위
                if (x == answer[j][0] && y - 1 == answer[j][1] && answer[j][2] == 0)
                    check = true;
            }
            
            if (!check)
                return check;
        }
        
        // 보의 조건: 한쪽 끝이 기둥 위, 양쪽 끝 부분이 다른 보와 동시에 연결
        else
        {
            bool check = false;
            
            bool left = false;
            bool right = false;
            
            for(int j = 0;j < answer.size();j++)
            {
                // 왼쪽 끝이 기둥 위
                if (x == answer[j][0] && y - 1 == answer[j][1] && answer[j][2] == 0)
                    check = true;
                
                // 오른쪽 끝이 기둥 위
                if (x + 1 == answer[j][0] && y - 1 == answer[j][1] && answer[j][2] == 0)
                    check = true;
                
                // 왼쪽이 보와 연결된 경우
                if (x - 1 == answer[j][0] && y == answer[j][1] && answer[j][2] == 1)
                    check = true;
                
                // 오른쪽이 보와 연결된 경우
                if (x + 1 == answer[j][0] && y == answer[j][1] && answer[j][2] == 1)
                    check = true;
            }
            if (left && right)
                check = true;
            
            if (!check)
                return check;
        }
    }
    return true;
}

vector<vector<int>> solution(int n, vector<vector<int>> build_frame) {
    vector<vector<int>> answer;
    
    int len = build_frame.size();
    
    for(int i = 0;i < len;i++)
    {
        // 좌표
        int x = build_frame[i][0];
        int y = build_frame[i][1];
        
        // sort(0: 기둥, 1: 보), job(0: 삭제, 1: 설치)
        int sort = build_frame[i][2];
        int job = build_frame[i][3];
        
        // 삭제
        if (job == 0)
        {
            // 없앨 부분 찾기
            int index = 0;
            for(int j = 0;j < answer.size();j++)
            {
                if (x == answer[j][0] && y == answer[j][1] && sort == answer[j][2])
                    index = j;
            }
            vector<int> temp = answer[index];
            // 없애보고 안되면 취소
            answer.erase(answer.begin() + index);
            if (!possible(answer))
                answer.push_back(temp);
        }
        
        // 설치
        else if (job == 1)
        {
            // 설치 해보고 안되면 취소
            answer.push_back({x, y, sort});
            if (!possible(answer))
                answer.pop_back();
        }
    }
    
    sort(answer.begin(), answer.end());
    
    return answer;
}

