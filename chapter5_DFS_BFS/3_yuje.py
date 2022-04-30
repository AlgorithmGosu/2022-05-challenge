from collections import deque
# BFS로 할 시에 내 코드
# N,M = map(int,input().split())
# data = []
# for _ in range(N):
#     # data.append(list(map(int,input().split()))) # 띄어쓰기 없으면 split안해주면됨.
#     data.append(list(map(int,input())))
# visited = [[False]*M for _ in range(N)]
#     # 위 왼 아 오
# dud = [-1,0,1,0]
# dlr = [0,-1,0,1]
# def bfs(data,visited,ud,lr):
#     # 첫 노드 처리
#     print("start:",ud,lr)
#     que = deque([(ud,lr)])
#     visited[ud][lr] = True
#     while que:
#         ud,lr = que.popleft()
#         # visited[ud][lr] = True  # visited를 어디에 설정하느냐에 다라서 중복이 될수도 있다.
#                                   # 이곳에 visited를 하게되면(노드가 큐에서 나올때 visited 처리를 하게 되면),
#                                   #  노드(1,1)이 (1,0),(0,1)에 모두 인접해서 두번 반복하게 된다.
#         print(ud,lr)
#         for i in range(4):
#             nud,nlr = ud+dud[i],lr+dlr[i]
#             if (0<=nud<=N-1 and 0<=nlr<=M-1) and data[nud][nlr] == 0 and visited[nud][nlr] == False:
#                 que.append((nud,nlr))
#                 visited[nud][nlr]=True # 그래서 해당 노드가 큐에 들어갈때 visited처리를 해주면 중복이 발생하지 않는다.
# count = 0
# for i in range(N):
#     for j in range(M):
#         if data[i][j] == 0 and visited[i][j] == False:
#             bfs(data,visited,i,j)
#             count +=1
# print(count)

N,M = map(int,input().split())
data = []
for _ in range(N):
    # data.append(list(map(int,input().split()))) # 띄어쓰기 없으면 split안해주면됨.
    data.append(list(map(int,input())))

def dfs(x,y):
    # 주어진 범위를 벗어나는 경우에는 종료
    if x<=-1 or x>=N or y<=-1 or y>=M:
        return False
    if data[x][y]==0:
        print(x,y)
        data[x][y]=1
        dfs(x-1,y)
        dfs(x,y-1)
        dfs(x+1,y)
        dfs(x,y+1)
        print(True)
        return True
    print(False)
    return False
    # 걍 가장 처음이 data[x][y]==0이면 True 아니면 False

# print(dfs(0,0))
result = 0
for i in range(N):
    for j in range(M):
        if dfs(i,j)==True:
            result+=1

print(result)