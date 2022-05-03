n,m = map(int,input().split())
data = []

INF = int(1e9)
graph = [[INF]*(n+1) for _ in range(n+1)]
for i in range(1,n+1):
    for j in range(1,n+1):
        if i == j:
            graph[i][j]=0
for _ in range(m):
    s,e = map(int,input().split())
    graph[s][e]=1
    graph[e][s]=1
x,k = map(int,input().split())
for k in range(1,n+1):
    for i in range(1,n+1):
        for j in range(1,n+1):
            graph[i][j] = min(graph[i][j],graph[i][k]+graph[k][j])
cost = graph[1][k]+graph[k][x]
if cost>=INF:
    print(-1)
else:
    print(cost)