import heapq
import sys
input = sys.stdin.readline
INF = int(1e9)

n,m = map(int,input().split())
start = int(input())
graph = [[]for i in range(n+1)]
distance = [INF]*(n+1)

for _ in range(m):
    a,b,c=map(int,input().split())
    graph[a].append((b,c))
def dijkstra(start):
    que = []
    heapq.heappush(que,(0,start))
    distance[start]=0
    while que:
        dist,now = heapq.heappop(que)
        if distance[now]<dist:
            print(now)
            print(distance[now],dist)
            continue
        for node in graph[now]:
            node_go,node_dist = node
            if distance[node_go] > node_dist + dist:
                distance[node_go]=node_dist+dist
                heapq.heappush(que,(node_dist+dist,node_go))
dijkstra(start)

for i in range(1,n+1):
    if distance[i]==INF:
        print("INFINITY")
    else:
        print(distance[i])
    