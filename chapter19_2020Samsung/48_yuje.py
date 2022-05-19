n,m,k = map(int,input().split())
board = []
for _ in range(n):
    board.append(list(map(int,input().split())))
# bfs여서 방향 리스트 따로 만들어도 될듯? 만약 dfs였으면 board에 방향 추가했을듯?
temp = list(map(int,input().split()))
direction = [0]
for t in temp:
    direction.append(t-1)
#  0   1  2  3
# 위 아래 왼 오
dx = [-1,1,0,0]
dy = [0,0,-1,1]
priority = [[]]
for s in range(1,m+1):
    # 이런식으로 저장해도 괜찮음.
    # 얕은복사아님.
    dir = []
    for _ in range(4):
        temp=list(map(int,input().split()))
        dir.append([t-1 for t in temp]) 
    priority.append(dir)
# priority[i번째 상어][j번째 움직임에서의][우선순위]
smell = [[[None,0] for _ in range(n)] for _ in range(n)]
# print(smell)
def smelled():
    for i in range(n):
        for j in range(n):
            if smell[i][j][1] !=0:
                smell[i][j][1]-=1
time = 0 
while True:
    # 자기 위치 냄새 뿌림.
    for i in range(n):
        for j in range(n):
            if board[i][j]!=0:
                smell[i][j]=[board[i][j],k]
    # 각 상어 움직임.
    visited = [False]*(m+1)
    for x in range(n):
        for y in range(n):
            # print(len(visited))
            # print(board[x][y])
            if board[x][y]!=0 and visited[board[x][y]]==False:
                #만약 냄새없는 칸이 있다면
                shark = board[x][y]
                visited[shark] = True
                didMove = False
                for p in priority[shark][direction[shark]]:
                    nx = x + dx[p]
                    ny = y + dy[p]

                    if 0<=nx<=n-1 and 0<=ny<=n-1 and smell[nx][ny][1]==0:
                        # 냄새가 없다면 글로 옮겨
                        board[x][y] = 0
                        if board[nx][ny]!=0:
                            board[nx][ny] = min(board[nx][ny],shark)
                        else:
                            board[nx][ny]=shark
                        direction[shark] = p
                        didMove = True
                        break
                if didMove:
                    continue
                # 여기에 왔다는 건 모든 곳에 냄새가 있는 거임.
                for p in priority[shark][direction[shark]]:
                    nx = x + dx[p]
                    ny = y + dy[p]

                    if 0<=nx<=n-1 and 0<=ny<=n-1 and smell[nx][ny][0]==shark:
                        # 자기 냄새라면 걸로 옮겨.
                        board[x][y] = 0
                        if board[nx][ny]!=0:
                            board[nx][ny] = min(board[nx][ny],shark)
                        else:
                            board[nx][ny]=shark
                        direction[shark] = p
                        didMove = True
                        break
    smelled()
    runMore = False
    for i in range(n):
        for j in range(n):
            if board[i][j]>1:
                runMore = True
                break
    # for d in board:
    #     print(d)
    # exit()
    time+=1
    if runMore == False:
        break
    if time == 1000:
        break
if time == 1000 and runMore ==True:
    print(-1)
else:
    print(time)