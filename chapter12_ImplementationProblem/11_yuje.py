n = int(input())
k = int(input()) # 사과 개수
apples = []
for _ in range(k):
    a,b = map(int,input().split())
    apples.append([a-1,b-1])
l = int(input())
moves = []
for _ in range(l):
    a,b = input().split()
    moves.append([int(a),b])

time = 0
# 위 오 아 왼
dx = [-1,0,1,0]
dy = [0,1,0,-1]
d = 1
# D: +1 / L:-1
snake = [[0,0]]
m = 0
while True:
    if m<len(moves) and time == moves[m][0]:
        if moves[m][1] == 'D':
            d = (d+1)%4
        else:
            d = (d-1)%4
        m+=1
    x,y = snake[0]
    nx,ny = x+dx[d],y+dy[d]
    time+=1
    if ([nx,ny] in snake) or not (0<=nx<=n-1) or not (0<=ny<=n-1):
        # print(nx,ny)
        break
    snake = [[nx,ny]] + snake
    if  not ([nx,ny]  in apples):
        snake.pop(-1)
    else:
        apples.remove([nx,ny])
print(time)
