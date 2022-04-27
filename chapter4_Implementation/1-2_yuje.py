# 내 코드
# Q: 완전 탐색 가능한가?
# 답: 일반적으로 탐색해야할 데이터의 전체 수가 100만개 이하일때 완전 탐색을 사용하면 적절하다.
# def tictok(time):
#     h,m,s = time[0],time[1],time[2]
#     s += 1
#     if s==60:
#         m+=1
#         s=0
#     if m == 60:
#         h += 1
#         m = 0
#     return [h,m,s]

# N = int(input())
# now = [0,0,0]
# finish_time = [N,59,59]
# count = 0
# while(now != finish_time):
#     now = tictok(now)
#     now_str = str(now[0])+str(now[1])+str(now[2])
#     if '3' in now_str:
#         count +=1
# print(count)

# 답안 코드
h = int(input())
count = 0

for i in range(h+1): # 실제로 구현안하고 간단하게 이런식으로 표현할 수있는지 생각해볼 것.
    for j in range(60):
        for k in range(60):
            if '3' in str(i)+str(j)+str(k):
                count+=1
print(count)