import heapq
t = int(input())
dx = [-1,0,1,0]
dy= [0,1,0,-1]
for _ in range(t):
    n = int(input())
    data = []
    for _ in range(n):
        data.append(list(map(int,input().split())))
    que = []
    visited = [[False]*n for _ in range(n)]
    distance = [[1e9]*n for _ in range(n)]
    heapq.heappush(que,[data[0][0],0,0])
    visited[0][0]= True
    distance[0][0] = data[0][0]
    while que:
        dist,x,y = heapq.heappop(que)
        for d in range(4):
            nx,ny = x+dx[d],y+dy[d]
            if 0<=nx<=n-1 and 0<=ny<=n-1:
                if not visited[nx][ny]:
                    distance[nx][ny] = data[nx][ny]+dist
                    visited[nx][ny]=True
                    heapq.heappush(que,[data[nx][ny]+dist,nx,ny])
                else: # 방문했따면
                    if distance[nx][ny] < data[nx][ny] + dist:
                        continue
                    else:
                        distance[nx][ny]=data[nx][ny]+dist
                        heapq.heappush(que,[data[nx][ny]+dist,nx,ny])
    print(distance[n-1][n-1])


    # for k in range(n):
    #     for i in range(n):
    #         for j in range(n):
    #             data[i][j] = min(data[i][j],data[i][k]+data[k][j])
    # print(data[n-1][n-1])
    # for i in range(1,n):
    #     data[i][0] += data[i-1][0]
    # for j in range(1,n):
    #     data[0][j] += data[0][j-1]
    
    # for i in range(1,n):
    #     for j in range(1,n):
    #         data[i][j] += min(data[i-1][j],data[i][j-1])
    # print(data[n-1][n-1])