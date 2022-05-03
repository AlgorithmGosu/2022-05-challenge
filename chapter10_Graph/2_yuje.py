n,m = map(int,input().split())
team = [i for i in range(n+1)] # team[student id] = team number

def find_parent(parent,x):
    if parent[x]!=x:
        parent[x]=find_parent(parent,parent[x])
    return parent[x]
def union(parent,x,y):
    px = find_parent(parent,x)
    py = find_parent(parent,y)
    if px < py:
        parent[py]=px
    else:
        parent[px]=py
for _ in range(m):
    x,a,b = map(int,input().split())
    if x == 0:
        union(team,a,b)
    else:
        ta = find_parent(team,a)
        tb = find_parent(team,b)
        if ta == tb:
            print("YES")
        else:
            print("NO")
    