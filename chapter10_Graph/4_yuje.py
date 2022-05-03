from collections import deque
import copy
# n=int(input())
# indegrees=[0]*(n+1)
# times = [0]*(n+1)
# graph = [[] for _ in range(n+1)]
# for i in range(1,n+1):
#     data = list(map(int,input().split()))
#     times[i]=data[0]
#     for x in data[1:-1]:
#         indegrees[i]+=1
#         graph[x].append(i)

# que = deque()
# result = [0]
# count =0
# for i in range(1,n+1):
#     if indegrees[i]==0:
#         que.append((i,times[i]))
# # que 뱉으면 수업 이수한거로 치자.
# need_times = [0]*(n+1)
# while que:

#     now,before = que.popleft()
#     need_times[now]=need_time
#     # count +=1
#     # result.append(result[count-1]+times[now])
#     for cls in graph[now]:
#         indegrees[cls] -=1
#         if indegrees[cls] == 0:
#             que.append((cls,need_time+times[now]))
# for i in need_times[1:]:
#     print(i)

v = int(input())
indegree=[0]*(v+1)
graph=[[]for i in range((v+1))]
time=[0]*(v+1)

for i in range(1,v+1):
    data = list(map(int,input().split()))
    time[i]=data[0]
    for x in data[1:-1]:
        indegree[i]+=1
        graph[x].append(i)
def topology_sort():
    result = copy.deepcopy(time)
    q=deque()

    for i in range(1,v+1):
        if indegree[i]==0:
            q.append(i)
    while q:
        now = q.popleft()
        for i in graph[now]:
            result[i]=max(result[i],result[now]+time[i]) # 내가 생각할 수 있었던 건, now에 대한 값을 어떻게든 얻어내는 거였는데,
                                                         # 정답 코드는, 반대로 해당 노드의 indegree가 줄어들 때, 즉 선행과목을 들었을 때마다,
                                                         # 그 후의 과목들을 차근차근 업데이트해주는 방법을 사용했네? ㄷㄷ
            indegree[i]-=1
            if indegree[i]==0:
                q.append(i)
    for i in range(1,v+1):
        print(result[i])
topology_sort()

