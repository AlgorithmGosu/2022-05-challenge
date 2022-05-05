from numpy import True_


n = int(input())
k = int(input())
apples = []
for _ in range(k):
    apples.append(list(map(int,input().split())))
moves = []
l = int(input())
for _ in range(l):
    x,d = input().split()
    moves.append([int(x),d])

board = [[0]*(n+1) for _ in range(n+1)]
for a in apples:
    ax,ay= a
    board[ax][ay]=1
snake = [[1,1]]
    # 위 왼 아 오
dx = [-1,0,1,0]
dy = [0,-1,0,1]

def hit_wall():
    x,y = snake[0]
    if 1<=x<=n and 1<=y<=n:
        return False
    return True

def hit_body():
    x,y = snake[0]
    for bx,by in snake[1:]:
        if bx == x and by == y:
            return True
    return False
direction={
    "U":0,
    "L":1,
    "D":2,
    "R":3,
}
d = 3
count = 0
canGo = True
for move in moves:
    if not canGo:
        break
    times, dir = move
    while count <times:
        # print(snake)
        hx,hy = snake[0]
        nhx,nhy = hx+dx[d],hy+dy[d]
        snake = [[nhx,nhy]]+snake
        count+=1
        # print(snake)
        if hit_wall() or hit_body():
            print(count)
            canGo = False
            break
        if board[nhx][nhy]==1:
            continue
        else:
            snake.pop(-1)
    d = direction[dir]
if canGo:
    print(count)
    # print("direction",d)
