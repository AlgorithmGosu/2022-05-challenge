from collections import deque
v,e=map(int,input().split())

graph =[[] for _ in range(v+1)]

indegrees = [0 for _ in range(v+1)]
result =[]
for _ in range(e): 
    a,b = map(int,input().split())
    graph[a].append(b)
    indegrees[b]+=1

# que = deque()
# for i in range(1,v+1):
#     if indegrees[i]==0:
#         que.append(i)
#         result.append(i)
#         for k in graph[i]:
#             indegrees[k] -=1
# while que:
#     node =que.popleft()
#     for i in graph[node]:
#         if indegrees[i]==0:
#             que.append(i)
#             indegrees[i]-=1
#             result.append(i)
# print(result)

def topology_sort():
    result = []
    q = deque()

    for i in range(1,v+1):
        if indegrees[i]==0:
            q.append(i)
    while q:
        now = q.popleft()
        result.append(now)
        for i in graph[now]:
            indegrees[i] -=1
            if indegrees[i] == 0:
                q.append(i)

    for i in result:
        print(i, end=' ')   
topology_sort()
