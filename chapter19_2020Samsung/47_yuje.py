# data = [[] for _ in range(4)]
# for line in range(4):
#     temp = list(map(int,input().split()))
#     for i in range(0,len(temp)-1,2):
#         data[line].append([temp[i],temp[i+1]-1])
# for d in data:
#     print(d)
# dx = [-1,-1,0,1,1,1,0,-1]
# dy = [0,-1,-1,-1,0,1,1,1]
# # 첫번째 상어[17] 들어감.
# SHARK = 17
# EMPTY = 18
# sx=sy=0
# SHARKSIZE = 0


# fishes = [None for _ in range(17)]
# for i in range(4):
#     for j in range(4):
#         fishes[data[i][j][0]]=[i,j]

# SHARKSIZE += data[0][0][0]
# # 상어에게 먹히면 None으로 변경
# fishes[data[0][0][0]] = None
# data[0][0][0] = SHARK

# def fish_move(data,fishes):
#     for i,f in enumerate(fishes):
#         if f == None:
#             continue
#         x,y=f
#         d = data[x][y][1]
#         turn = 0
#         while turn < 8:
#             nx=x+dx[d]
#             ny=y+dy[d]
#             if 0<=nx<=3 and 0<=ny<=3:
#                 # 만약 비어있는 곳이라면 물고기만 이동
#                 if data[nx][ny][0]==EMPTY:
#                     data[x][y][1]=d
#                     data[nx][ny],data[x][y]=data[x][y],data[nx][ny]
#                     fishes[i] = [nx,ny]
#                     break
#                 # 다른 물고기가 있다면
#                 elif data[nx][ny][0]<=16:
#                     data[x][y][1]=d
#                     nf = data[nx][ny][0]
#                     data[nx][ny],data[x][y] = data[x][y],data[nx][ny]
#                     fishes[i],fishes[nf]=fishes[nf],fishes[i]
#                     break
#                 # 그렇지 않다면 (상어)
#             turn+=1
#             d = (d+1)%8
#     return data,fishes
    
# def shark(sea,fishes,size):
#     global sx,sy,SHARKSIZE
#     data,fishes =fish_move(sea,fishes)
#     x,y = sx,sy
#     d = data[x][y][1]
#     nx = x+dx[d]
#     ny = y+dy[d]
#     canEat = FALSE
#     while 0<=nx<=3 and 0<=ny<=3:
#         print(size,nx,ny)
#         # 해당 위치에 물고기가 있다면
#         if data[nx][ny][0]<=16: 
#             # 물고기를 먹고
#             eaten_fish = data[nx][ny][0]
#             print(size,eaten_fish)
#             size = size+eaten_fish
#             SHARKSIZE = max(size,SHARKSIZE)
#             # 해당 물고기의 좌표를 None 변경
#             fishes[eaten_fish]=None
#             data[nx][ny][0]=SHARK
#             data[x][y][0]=EMPTY
#             sx,sy=nx,ny
#             shark(data,fishes,size)
#             sx,sy=x,y
#             data[x][y][0]=SHARK
#             data[nx][ny][0]=eaten_fish
#             fishes[eaten_fish]=[nx,ny]
#             size = size - eaten_fish            
#             canEat=True
#         nx = nx + dx[d]
#         ny = ny + dy[d]
#     if canEat == False:
#         return
# shark(data,fishes,SHARKSIZE)
# print(SHARKSIZE)

# dfs로 구현할 때, 최대한 모든 정보를 하나의 리스트안에 담는 것이 이상적인것 같다.
# 왜냐하면 나는 fish_move를 하기 위해서 fishes라는 새로운 리스트를 만들어서 사용하다 보니 나중에 빼고 다시 넣는과정(stack)에서 헷갈리거나,
# 건들여야할 변수들이 너무 많아지기 때문이다.
# 따라서 복잡도가 커도 되면, 그냥 변수를 최소화하는 쪽으로 구현해보자.(내가 복잡하지 않게)
# 구현 문제는 내가 복잡하면 안됨.

# https://developer-ellen.tistory.com/68
# 이 코드가 잘 구현한듯

import copy
data = [[] for _ in range(4)]
for line in range(4):
    temp = list(map(int,input().split()))
    for i in range(0,len(temp)-1,2):
        data[line].append([temp[i],temp[i+1]-1])
dx = [-1,-1,0,1,1,1,0,-1]
dy = [0,-1,-1,-1,0,1,1,1]
maxsize = 0

# 여러 정보를 dfs의 변수로 넘기는 게 또 좋은듯 예를들어 상어의 위치를 다시 찾는게 아니라 현재 위치 변수로 건내주는거지.
# dfs는 어떻게 구현하느냐가 가장 중요한 것 같다.
def dfs(sx,sy,size,board):
    # fish move
    global maxsize
    size += board[sx][sy][0]
    maxsize = max(maxsize,size)
    board[sx][sy][0]=0
    for f in range(1,17):
        fx=fy=-1
        for i in range(4):
            for j in range(4):
                if board[i][j][0] == f:
                    fx=i
                    fy=j
                    break
        if fx==-1 and fy==-1:
            continue
        fd=board[fx][fy][1]

        turn = 0
        while turn <8:
            nx=fx+dx[fd]
            ny=fy+dy[fd]
            if 0<=nx<=3 and 0<=ny<=3 and not (nx == sx and ny==sy):
                board[fx][fy][1]=fd
                board[fx][fy],board[nx][ny]=board[nx][ny],board[fx][fy]
                break
            fd = (fd+1)%8
            turn+=1
    
    sd = board[sx][sy][1]
    for i in range(1,5):
        nx = sx + i*dx[sd]
        ny = sy + i*dy[sd]
        if 0<=nx<=3 and 0<=ny<=3 and board[nx][ny][0]>0:
            dfs(nx,ny,size,copy.deepcopy(board))
dfs(0,0,0,data)
print(maxsize)