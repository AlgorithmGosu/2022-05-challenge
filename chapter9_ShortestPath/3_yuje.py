import heapq
n,m,c = map(int,input().split())
INF = int(1e9)
distance = [INF]*(n+1)
graph = [[] for _ in range(n+1)]
for _ in range(m):
    x,y,z= map(int,input().split())
    # x노드에서 y노드까지 z시간 걸림.
    graph[x].append((y,z))

def dijkstra(start):
    que = []
    distance[start] = 0
    heapq.heappush(que,(0,start))
    while que:
        # 시간 , 현재 노드
        dist, now = heapq.heappop(que)
        if distance[now] <dist:
            continue
        # i[0]: 도착 노드 i[1]:시간
        for i in graph[now]:
            cost = dist + i[1]
            if distance[i[0]] > cost:
                distance[i[0]] = cost
                heapq.heappush(que,(cost,i[0]))
dijkstra(c)
count = 0
for i in range(len(distance)):
    if distance[i] == INF or distance[i]== 0:
        distance[i] = -1
    else:
        count +=1
print(count,max(distance))

