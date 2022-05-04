import sys
input = sys.stdin.readline

n = int(input())
data = list(map(int,input().split()))

data.sort()

# 내 코드
# now = 0
# count = 0
# while(True):
#     team_len = data[now]
#     next = now+team_len
#     if next<len(data):
#         count+=1
#         now = next
#         continue
#     break
# print(count)

# 답지 코드: 모험가의 수가 10만이하라 그냥 하나씩 탐색한듯
result = 0
count = 0

for i in data:
    count +=1
    if count>=i:
        result+=1
        count=0
print(result)