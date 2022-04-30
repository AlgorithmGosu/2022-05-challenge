# count를 같이 넘기면 될듯
N,M = map(int,input().split())
data = []
for _ in range(N):
    data.append(list(map(int,input())))
visited = [[False]*M for _ in range(N)]
from collections import deque
que = deque([(0,0,1)])
visited[0][0]=True
# 오 아 왼 위
dud=[1,0,-1,0]
dlr=[0,1,0,1]

while que:
    node = que.popleft()
    print(node)
    ud,lr,node_count = node
    if ud == N-1 and lr == M-1:
        print(node_count)
        break
    for i in range(4):
        nud = ud + dud[i]
        nlr = lr + dlr[i]
        if (0<=nud<=N-1 and 0<=nlr<=M-1) and visited[nud][nlr] == False and data[nud][nlr]==1:
            visited[nud][nlr]=True
            que.append((nud,nlr,node_count+1))
