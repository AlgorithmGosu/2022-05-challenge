from collections import deque
from itertools import combinations
n,m = map(int,input().split())
data = []
for _ in range(n):
    data.append(list(map(int,input().split())))
dx=[-1,0,1,0]
dy=[0,1,0,-1]
def bfs(test,visited,virus):
    que = deque([virus])
    x,y = virus
    visited[x][y]= True
    while(que):
        node = que.popleft()
        x,y = node
        for i in range(4):
            nx,ny=x+dx[i],y+dy[i]
            if 0<=nx<=n-1 and 0<=ny<=m-1 and test[nx][ny]!=1 and visited[nx][ny]==False:
                visited[nx][ny]=True
                test[nx][ny]=2
                que.append((nx,ny))

def spread(test,viruses):
    visited = [[False]*m for _ in range(n)]
    for virus in viruses:
        bfs(test,visited,virus)

comb = []
viruses=[]
for i in range(n):
    for j in range(m):
        comb.append((i,j))
        if data[i][j]==2:
            viruses.append((i,j))
answer=0
for blocks in combinations(comb,3):
    test = [row[:] for row in data[:]]
    canBlock = True
    for b in blocks:
        x,y=b
        if data[x][y]!=0:
            canBlock=False
        test[x][y]=1
    if not canBlock:
        continue


    spread(test,viruses)
    count =0
    for i in range(n):
        for j in range(m):
            if test[i][j]==0:
                count+=1
    # for r in test:
    #     print(r)
    # exit()
    answer = max(answer,count)
print(answer)