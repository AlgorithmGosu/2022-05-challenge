from collections import deque
n,k = map(int,input().split())
data = []
for _ in range(n):
    data.append(list(map(int,input().split())))
s,tx,ty = map(int,input().split())
tx-=1
ty-=1
#    위 왼 아 오
dx = [-1,0,1,0]
dy = [0,-1,0,1]

que = deque()
# [virus_num,[x,y]]
start_virus = []
for i in range(n):
    for j in range(n):
        if data[i][j]!=0:
            start_virus.append([data[i][j],[i,j]])
start_virus.sort()
t = 0
# que => [virus_num,time,[x,y]]
for st in start_virus:
    que.append([st[0],t,st[1]])

while que:
    num,t,[x,y] = que.popleft()
    if t+1 > s:
        break
    for i in range(4):
        nx,ny = x+dx[i],y+dy[i]
        if 0<=nx<=n-1 and 0<=ny<=n-1 and data[nx][ny]==0:
            data[nx][ny]=num
            que.append([num,t+1,[nx,ny]])
print(data[tx][ty])