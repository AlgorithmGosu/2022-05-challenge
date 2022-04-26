# 내 코드
# N,M = map(int,input().split())
# data = []
# for _ in range(N):
#     data.append(list(map(int,input().split())))
# max = -1e8
# for line in data:
#     line_min = min(line)
#     if max < line_min:
#         max = line_min
# print(max)

# 답지
N,M = map(int,input().split())

result = 0
for i in range(N):
    data = list(map(int,input().split()))
    min_value = min(data)
    result = max(result,min_value) # 내가 직접 구현한 것을 max(A,B)로 구현할 수 있음.
print(result)