#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

int solution(int n, vector<int> weak, vector<int> dist) {
    int length = weak.size();
    for (int i = 0; i < length; i++) {
        weak.push_back(weak[i] + n);
    }
    int answer = dist.size() + 1;
    for (int start = 0; start < length; start++) {
        do {
            int cnt = 1; // 투입할 친구의 수
            int position = weak[start] + dist[cnt - 1];
            
			// 시작점부터 모든 취약한 지점을 확인
            for (int index = start; index < start + length; index++) {
                
                if (position < weak[index]) {
                    cnt += 1; // 새로운 친구를 투입
                    if (cnt > dist.size()) { // 더 투입이 불가능하다면 종료
                        break;
                    }
                    position = weak[index] + dist[cnt - 1];
                }
            }
            answer = min(answer, cnt); // 최솟값 계산
        } while(next_permutation(dist.begin(), dist.end()));
    }
    if (answer > dist.size()) {
        return -1;
    }
    return answer;
}
