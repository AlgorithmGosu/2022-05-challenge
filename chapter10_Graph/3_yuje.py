import sys
input = sys.stdin.readline
n,m = map(int,(input().split()))

parent = [i for i in range(0,n+1)]

def find_parent(parent,x):
    if parent[x]!=x:
        parent[x]=find_parent(parent,parent[x])
    return parent[x]

def union_parent(parent,x,y):
    px = find_parent(parent,x)
    py = find_parent(parent,y)
    if px>py:
        parent[px]=py
    else:
        parent[py]=px

# graph=[[] for _ in range(n+1)]
paths = []
for _ in range(m):
    a,b,c = map(int,input().split())
    # graph[a].append((b,c))
    paths.append((a,b,c))

paths.sort(key=lambda x:x[2])
alive = []
for p in paths:
    a,b,dist = p
    pa,pb=find_parent(parent,a),find_parent(parent,b)
    if pa == pb:
        continue
    else:
        union_parent(parent,a,b)
        alive.append(p)
result = 0
for i in alive[:len(alive)-1]:
    result+=i[2]
print(result)
        


