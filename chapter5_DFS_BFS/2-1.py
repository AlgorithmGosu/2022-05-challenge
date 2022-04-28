# 각 노드가 연결된 정보를 리스트 자료형으로 표현(2차원 리스트)
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
# 내가 작성한 코드
# def dfs(graph,node,visited):
#     print(node)
#     visited[node] = True
#     for n in graph[node]: # 인접한 노드들
#         if visited[n] == False:
#             dfs(graph,n,visited)
# 답지 코드
def dfs(graph,v,visited):
    visited[v]=True
    print(v,end=' ')
    # 현재 노드와 연결된 다른 노드를 재귀적으로 방문
    for i in graph[v]:
        if not visited[i]:
            dfs(graph,i,visited)

dfs(graph,1,visited)