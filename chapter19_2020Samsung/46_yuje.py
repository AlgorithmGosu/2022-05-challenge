from collections import deque
n = int(input())
data = []
for _ in range(n):
    data.append(list(map(int,input().split())))
canEat = []
shark_size = 2

for i in range(n):
    for j in range(n):
        if data[i][j]==9:
            shark = [i,j]
    
dx = [-1,0,1,0]
dy = [0,1,0,-1]
# canEat 재설정 상어의 크기가 변할때마다 해주면 됨.
def bfs(shark,shark_size):
    canEat = []
    visited = [[False]*n for _ in range(n)]
    x,y = shark
    distance = 0
    que = deque([[x,y,distance]])
    visited[x][y]=True
    while que:
        x,y,dist = que.popleft()
        dist +=1
        for i in range(4):
            nx = x+dx[i]
            ny = y+dy[i]
            # 자기와 같은 크기까진 해당 블록으로 움직일 수 있음.
            if 0<=nx<=n-1 and 0<=ny<=n-1 and visited[nx][ny]==False and data[nx][ny] <=shark_size:
                que.append([nx,ny,dist])
                visited[nx][ny]=True
                # 먹을 수 있는 애라면
                if 0<data[nx][ny]< shark_size:
                    canEat.append([dist,nx,ny])
    return canEat

time = 0
food = 0

while True:
    # print(food,shark_size)
    if food == shark_size:
        food = 0
        shark_size +=1

    canEat = bfs(shark,shark_size)

    if len(canEat) == 0:
        break

    else:
        # 먹을 수 있는 물고기를 거리, 위 ,왼쪽 순으로 정렬한다.
        canEat.sort()
        dist,x,y = canEat.pop(0)
        data[shark[0]][shark[1]]=0
        shark = [x,y]
        
        time+= dist
        food+=1
        data[x][y]=9
print(time)

        