# # 나는 양방향을 sort해줌으로써, 인덱스 낮은게 항상 앞에 오게해서 처리해주었다.
# import heapq
# n,m = map(int,input().split())
# distance = [1e9]*(n+1)
# data = []
# for _ in range(m):
#     x,y = map(int,input().split())
#     if x<y:
#         data.append([x,y])
#     else:
#         data.append([y,x])
# que = []
# distance[1] = 0
# heapq.heappush(que,[0,1])
# while que:
#     dist,node = heapq.heappop(que)
#     for d in data:
#         x,y = d
#         if x == node:
#             # print(d)
#             # data.remove(d)
#             if distance[y] < dist + 1:
#                 continue
#             else:
#                 distance[y]=dist+1
#                 heapq.heappush(que,[distance[y],y])
# for i in range(len(distance)):
#     if distance[i]==1e9:
#         distance[i]=0
# maxD = max(distance)
# print(distance.index(maxD),maxD,distance.count(maxD))

# 답지 코드
# 내 코드가 틀렸다.: 나는 dist를 1씩만 더해주었지만, 2 + 3 = 5 인 경우도 있을 것이다.
# 내 코드가 답과 같았던 이유는 해당 문제의 최대 길이가 2였기 때문에
import heapq
import sys
input = sys.stdin.readline
INF = int(1e9)

n,m = map(int,input().split())
start =1
graph = [[ ] for i in range(n+1)]
distance = [INF]*(n+1)

for _ in range(m):
    a,b = map(int,input().split())
    graph[a].append((b,1))
    graph[b].append((a,1))

def dijkstra(start):
    q = []
    heapq.heappush(q,(0,start))
    distance[start]=0
    while q:
        dist,now = heapq.heappop(q)
        if distance[now]<dist:
            continue
        for i in graph[now]:
            cost = dist + i[1]
            
            if cost<distance[i[0]]:
                distance[i[0]] = cost
                heapq.heappush(q,(cost,i[0]))
dijkstra(start)
max_node = 0
max_distance= 0

result = []
# print(distance)
for i in range(1,n+1):
    if max_distance <distance[i]:
        max_node=i
        max_distance=distance[i]
        result = [max_node]
    elif max_distance == distance[i]:
        result.append(i)
print(max_node,max_distance,len(result))
