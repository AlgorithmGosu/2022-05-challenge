


# n = int(input())
# k = int(input())
# apples = []
# for _ in range(k):
#     apples.append(list(map(int,input().split())))
# moves = []
# l = int(input())
# for _ in range(l):
#     x,d = input().split()
#     moves.append([int(x),d])

# board = [[0]*(n+1) for _ in range(n+1)]
# for a in apples:
#     ax,ay= a
#     board[ax][ay]=1
# snake = [[1,1]]
#     # 위 왼 아 오
# dx = [-1,0,1,0]
# dy = [0,-1,0,1]

# def hit_wall():
#     x,y = snake[0]
#     if 1<=x<=n and 1<=y<=n:
#         return False
#     return True

# def hit_body():
#     x,y = snake[0]
#     for bx,by in snake[1:]:
#         if bx == x and by == y:
#             return True
#     return False
# d = 3
# t = 0
# canGo = True
# for move in moves:
#     time, str_d = move
#     while t < time:
#         hx,hy = snake[0]
#         nhx,nhy = hx + dx[d],hy+dy[d]
#         snake = [[nhx,nhy]]+snake
#         t +=1
#         if hit_body() or hit_wall():
#             print(t)
#             canGo = False
#             break
#         if board[nhx][nhy] != 1:
#             snake.pop(-1)
#     if str_d == 'L':
#         d = (d+1)%4
#     else:
#         d = (d+3)%4
#     if canGo == False:
#         break
# if canGo:
#     # print(hit_body())
#     # print(hit_wall())
#     while not hit_body() and not hit_wall():
#         hx,hy = snake[0]
#         nhx,nhy = hx + dx[d],hy+dy[d]
#         snake = [[nhx,nhy]]+snake
#         t +=1
#     print(t)

n = int(input())
k = int(input())
data = [[0]*(n+1) for _ in range(n+1)]
info = []

for _ in range(k):
    a,b=map(int,input().split())
    data[a][b]=1

l = int(input())
for _ in range(l):
    x,c=input()