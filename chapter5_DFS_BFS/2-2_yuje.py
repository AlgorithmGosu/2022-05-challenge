graph=[
    [],
    [2,3,8],
    [1,7],
    [1,4,5],
    [3,5],
    [3,4],
    [7],
    [2,6,8],
    [1,7]
]
visited = [False]*9
# 내 코드 
from collections import deque
que = deque() 
# def bfs(graph,node,visited):
#     visited[node] = True
#     print(node,end=' ')
#     for n in graph[node]:
#         if not visited[n]:
#             que.append(n)
#     if len(que) == 0:
#         return
#     n = que.popleft()
#     bfs(graph,n,visited)

def bfs(graph,start,visited):
    que= deque([start]) # queue는 첫 element가 들어가고 시작해야한다.
    visited[start] = True
    while que: # queue가 빌때까지
        v = que.popleft()
        print(v,end=' ')
        for i in graph[v]:
            if not visited[i]:
                que.append(i)
                visited[i] = True
bfs(graph,1,visited)