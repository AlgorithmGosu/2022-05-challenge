# combination으로 방해물 위치 정할 수 있긴 하다.
# 그래도 dfs로 구현해보는게 좋을듯?
# bfs로는 설치 불가능 ㅇㅈ?
n = int(input())
data =[]
for _ in range(n):
    data.append(list(map(str,input().split())))
# 위 왼 아 오
dx = [-1,0,1,0]
dy = [0,-1,0,1]
# 학생이 한명이라도 걸리면 False 모두 안걸리면 True
def canHide():
    global n
    for i in range(n):
        for j in range(n):
            if data[i][j]=='T':
                for d in range(4):
                    x,y = i,j
                    while  0<=x<=n-1 and 0<=y<=n-1:
                        if data[x][y] == 'O':
                            break
                        elif data[x][y] =='S':
                            return False
                        x+=dx[d]
                        y+=dy[d]
    return True
comb = []
for i in range(n):
    for j in range(n):
        comb.append([i,j])

hide = False
def dfs(cnt,idx):
    global hide
    # 처음에 이렇게 했다가 계속 시간초과가 떴다.
    # dfs의 탈출 조건(return 조건이 없었기 때문이다.)
    # dfs에선 dfs 탈출조건 잘 구현하자.
    # if cnt == 3:
    #     if canHide():
    #         hide = True
    if cnt == 3:
        hide =hide or canHide()
        return 

    for i in range(idx,len(comb)):
        # if i == len(comb)-(3-cnt):
        #     return
        x,y = comb[i]
        if data[x][y] == 'X':
            data[x][y] = 'O'
            dfs(cnt+1,i)
            data[x][y]='X'
dfs(0,0)
if hide:
    print("YES")
else:
    print("NO")