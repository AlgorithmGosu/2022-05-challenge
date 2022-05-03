INF=int(1e9)

n=int(input())
m=int(input())
graph = [[INF]*(n+1) for _ in range(n+1)]
for a in range(1,n+1):
    for b in range(1,n+1):
        if a==b:
            graph[a][b]=0

for _ in range(m):
    a,b,c = map(int,input().split())
    graph[a][b]=c
    #start end dist

    # A -> node -> B에 대한 모든 경우의 수 계산
    # Distance(A->B)= min Distance(A->B) vs Distance(A->node->B)
    for k in range(1,n+1):
        for i in range(1,n+1):
            for j in range(1,n+1):
                graph[i][j]=min(graph[i][j],graph[i][k]+graph[k][j])
for a in range(1,n+1):
    for b in range(1,n+1):
        if graph[a][b]==INF:
            print("INFINITY",end=" ")
        else:
            print(graph[a][b],end=' ')
    print()