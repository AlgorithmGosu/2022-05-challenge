# N: data개수
# M: 덧셈 횟수
# K: 연속 반복 가능 횟수
# 내 코드
# N,M,K = map(int,input().split(' '))
# data = list(map(int,input().split(' ')))
# data.sort(reverse=True)
# sum = 0
# turn = 0
# while(M>0):
#     if turn == 0:
#         if M // K >0:
#             sum += (data[0]*K)
#             M -= K
#         else:
#             sum += data[0]*M
#             M = 0 
#         turn = 1
#     else:
#         sum += data[1]
#         M -=1
#         turn = 0
# print(sum)

# 답지 코드
N,M,K = map(int,input().split(' '))
data = list(map(int,input().split(' ')))
data.sort(reverse=True)
first = data[0]
second = data[1]

result = 0

while True:
    for i in range(K): # K번 반복하는 것을 반복문으로 + 0되면 break
        if M == 0:
            break
        result += first
        M -=1
    if M == 0:
        break
    result += second
    M -= 1
print(result)