from collections import deque
n,l,r = map(int,input().split())
data = []
for _ in range(n):
    data.append(list(map(int,input().split())))
dx = [-1,0,1,0]
dy = [0,1,0,-1]

def canTeam():
    for i in range(n):
        for j in range(n):
            for d in range(4):
                nx,ny=i+dx[d],j+dy[d]
                if (0<=nx<=n-1) and (0<=ny<=n-1) and l<=abs(data[nx][ny]-data[i][j])<=r:
                    return True
    return False
days = 0
while canTeam():
    days+=1
    # for d in data:
    #     print(d)
    visited = [[False]*n for _ in range(n)]
    for i in range(n):
        for j in range(n):
            if not visited[i][j]:
                que = deque([[i,j]])
                visited[i][j]=True
                teams = [[i,j]]
                while que:
                    x,y = que.popleft()
                    for d in range(4):
                        nx = x+dx[d]
                        ny = y+dy[d]
                        if (0<=nx<=n-1) and (0<=ny<=n-1) and l<=abs(data[x][y]-data[nx][ny])<=r and not visited[nx][ny]:
                            que.append([nx,ny])
                            teams.append([nx,ny])
                            visited[nx][ny]=True
                pop_sum = 0
                for team in teams:
                    x,y = team
                    pop_sum += data[x][y]
                for team in teams:
                    x,y = team
                    data[x][y] = pop_sum // len(teams)
print(days)
                
