# 파이썬은 1초에 10^7의 연산이 가능하다.
# 내가 아래처럼 구현하면 복잡도는 n^2logn(sort()의 복잡도는 nlogn) => 데이터가 10^5개이니 10^10log(10^5)로 불가능.
# 우선순위 큐는 넣고 뺄때 각각 복잡도: logn 
# 따라서 우선순위 큐로 구현하면 복잡도: nlogn 가능
# import sys
# input = sys.stdin.readline
# n = int(input())
# data = []
# for _ in range(n):
#     data.append(int(input()))

# data.sort()
# if n==1:
#     print(data[0])
# else:
#     result =0
#     while len(data)>1:
#         a,b = data[0],data[1]
#         data = data[2:]
#         data.append(a+b)
#         result += a+b
#         data.sort()
#     print(result)
import heapq
n = int(input())
data = []
for _ in range(n):
    data.append(int(input()))

if n==1:
    print(0)

else:
    que = []
    for d in data:
        heapq.heappush(que,d)
    result = 0
    while len(que) >=2:
        a = heapq.heappop(que)
        b = heapq.heappop(que)
        result += a+b
        heapq.heappush(que,a+b)
    print(result)
