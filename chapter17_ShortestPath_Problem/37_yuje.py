n = int(input())
m = int(input())
distance = [[1e9]*(n+1) for _ in range(n+1)]
# data = [[] for _ in range(n+1)]
for _ in range(m):
    a,b,c = map(int,input().split())
    # data[a]=b
    distance[a][b]=min(distance[a][b],c)
for i in range(1,n+1):
    distance[i][i]=0

for k in range(1,n+1):
    for i in range(1,n+1):
        for j in range(1,n+1):
            distance[i][j]=min(distance[i][j],distance[i][k]+distance[k][j])
for i in range(1,n+1):
    for j in range(1,n+1):
        distance[i][j]=0 if distance[i][j]==1e9 else distance[i][j]

for d in distance[1:]:
    for dist in d[1:]:
        print(dist,end=' ')
    print()