# # 내 코드
# n = int(input())
# data = [[None,None]]

# for _ in range(n):
#     t,p = map(int,input().split())
#     data.append([t,p])

# money =[0]*(n+2)

# for i in range(1,n+2):
#     maxV = 0
#     if i != 1:
#         maxV = money[i-1]

#     for j in range(1,i):
#         if j + data[j][0]==i:
#             maxV = max(maxV,money[j]+data[j][1])
#     money[i]=maxV
# print(money[n+1])

# 답지 코드
n = int(input())
t = []
p = []
dp = [0]*(n+1)
max_value = 0

for _ in range(n):
    x,y= map(int,input().split())
    t.append(x)
    p.append(y)

for i in range(n-1,-1,-1):
    time = t[i]+i
    if time<=n:
        dp[i]= max(p[i]+dp[time],max_value)
        max_value = dp[i]
    else:
        dp[i]= max_value
print(dp)
print(max_value)