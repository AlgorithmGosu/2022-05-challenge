from collections import deque
n,m,k,x = map(int,input().split())
graph = [[] for _ in range(n+1)]
for _ in range(m):
    a,b = map(int,input().split())
    graph[a].append(b)

distance = [1e9]*(n+1)
que = deque([[x,0]])
distance[x] = 0
while que:
    node, dist = que.popleft()

    for next_node in graph[node]:
        if distance[next_node] == 1e9:
            que.append([next_node,dist+1])
            distance[next_node] = dist+1
if distance.count(k)==0:
    print(-1)
else:
    for i in range(1,n+1):
        if distance[i] == k:
            print(i)