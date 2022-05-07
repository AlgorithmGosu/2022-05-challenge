from itertools import permutations
def solution(n, weak, dist):
    # 길이를 2배로 늘려서 원형을 일자 형태로 변형 ***
    length = len(weak)
    for i in range(length):
        weak.append(weak[i]+n)
    answer = len(dist)+1
    # 0부터 length -1 까지의 위치를 각각 시작점으로 설정
    for start in range(length):
        for friends in list(permutations(dist,len(dist))): # 순열을 쓰는 방식
            count = 1 # friend num
            position = weak[start]+friends[count-1]
            for index in range(start,start+length):
                if position<weak[index]:
                    count+=1
                    if count > len(dist): # count를 키우는 방식으로 하는게 더 직관적이다.
                        break
                    position = weak[index] + friends[count-1]
            answer = min(answer,count)
    if answer > len(dist):
        return -1
    return answer

print(solution(12, [1, 5, 6, 10], [1, 2, 3, 4]))