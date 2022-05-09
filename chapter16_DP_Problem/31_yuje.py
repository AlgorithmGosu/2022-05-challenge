t =int(input())
# 왼 위 / 왼 /왼 아래
dx = [-1,0,1]
dy = [-1,-1,-1]

for _ in range(t):
    n,m = map(int,input().split())
    now = 0
    next = 0
    data =[]
    temp = list(map(int,input().split()))
    while now+m <= len(temp):
        next = now+m
        data.append(temp[now:next])
        now = next

    for y in range(1,m):
        for x in range(0,n):
            maxV = 0
            for d in range(3):
                nx,ny = x + dx[d],y+dy[d]
                if 0<=nx<=n-1 and 0<=ny<=m-1:
                    maxV = max(maxV,data[x][y]+data[nx][ny])
            data[x][y]=maxV
    #         exit()
    # for d in data:
    #     print(d)
    print(max([row[-1] for row in data]))
