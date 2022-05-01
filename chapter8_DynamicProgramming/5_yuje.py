# from collections import deque
# n,m =map(int,input().split())
# coins = []
# for _ in range(n):
#     coins.append(int(input()))
# dp_table=[1e8]*(m+1)
# que = deque()
# for c in coins:
#     dp_table[c]=1
#     que.append(c)
# flag = True
# while(flag):
#     print(dp_table)
#     node = que.popleft()
#     for c in coins:
#         if node + c > m:
#             flag = False
#             break
#         dp_table[node+c] = min(dp_table[node+c],dp_table[node]+1)
#         que.append(node+c)
# if dp_table[m] == 1e8:
#     print(-1)
# else:
#     print(dp_table[m])

n,m = map(int,input().split())
coins = []
for _ in range(n):
    coins.append(int(input()))

dp_table =[10001]*(m+1)
dp_table[0]=0
for i in range(n):
    for j in range(coins[i],m+1):
        if dp_table[j-coins[i]] != 10001:
            dp_table[j]=min(dp_table[j],dp_table[j-coins[i]]+1)
if dp_table[m]==10001:
    print(-1)
else:
    print(dp_table[m])