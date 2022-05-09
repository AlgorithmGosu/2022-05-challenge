n = int(input())
data = [[None,None]]

for _ in range(n):
    t,p = map(int,input().split())
    data.append([t,p])

money =[0]*(n+2)

for i in range(1,n+2):
    maxV = 0
    if i != 1:
        maxV = money[i-1]

    for j in range(1,i):
        if j + data[j][0]==i:
            maxV = max(maxV,money[j]+data[j][1])
    money[i]=maxV
print(money[n+1])