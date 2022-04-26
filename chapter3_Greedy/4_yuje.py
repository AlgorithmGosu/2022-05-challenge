# K가 2 이상일 때, 나눌 수 있으면 무조건 나누는게 이득이다.
# 내 코드
# N,K = map(int,input().split(' '))
# count = 0
# while(N>1):
#     if N % K == 0:
#         N = N/K
#     else:
#         N -= 1
#     count +=1
# print(count)

# # 답지 코드
# # 매우 높은 수에서도 빠르게 동작할 수 있다.
# # => 1씩 빼는 상황을 한번에 처리할 수 있다. (ex -1을 1000번 반복이 아니라 한번에 -1000 하는 느낌)
N,K = map(int,input().split(' '))
count = 0

while True:
    # -1 case
    target = (N//K)*K # (28//5)*5 = 5*5 = 25
                      # (3//4)*4 = 0*4 = 0 ERROR
                      # (25//5)*5 = 5*5 = 25
                      # 1씩 까는 걸 TARGET을 계산해 한방에 계산하는 방법.
    count += N - target # 3 - 4 ERROR
                       # 25 -25 = 0
    N = target
    if N < K: # 처음에는 N>=K를 만족하는가? => ㅇ
        break
    # 나누기 case
    N = N/K
    count +=1
count += (N-1)
print(int(count))
