from collections import deque

dx = [-1,0,1,0]
dy = [0,1,0,-1]
def solution(board):
    def turn(robot):
        lx,ly = min(robot)
        rx,ry = max(robot)
        turned = []
        if lx==rx: # 가로로 누워있음.
            for i in [-1,1]:
                if 0<=lx+i<=n-1 and board[lx+i][ly] == 0 and board[lx+i][ry]==0:
                    turned.append([[lx+i,ly],[lx,ly]])
                    turned.append([[rx,ry],[rx+i,ry]])
        else: # 세로
            for i in [-1,1]:
                if 0<=ly+i<=n-1 and board[lx][ly+i] == 0 and board[rx][ry+i]==0:
                    turned.append([[lx,ly+i],[lx,ly]])
                    turned.append([[rx,ry+i],[rx,ry]])
        return turned
    moved = []
    n = len(board)
    que = deque([[[0,0],[0,1],0]])
    answer = -1
    while que:
        b1,b2,cnt= que.popleft()
        if b1 == [n-1,n-1] or b2 == [n-1,n-1]:
            answer = cnt
            break
        moves = []
        for i in range(4):
            nb1 = [b1[0]+dx[i],b1[1]+dy[i]]
            nb2 = [b2[0]+dx[i],b2[1]+dy[i]]
            moves.append([nb1,nb2])
        moves.extend(turn([b1,b2]))
        for m in moves:
            b1x,b1y= m[0]
            b2x,b2y=m[1]
            if 0<=b1x<=n-1 and 0<=b1y<=n-1 and 0<=b2x<=n-1 and 0<=b2y<=n-1 and board[b1x][b1y] == 0 and board[b2x][b2y] == 0 and not ([[b1x,b1y],[b2x,b2y]] in moved or [[b2x,b2y],[b1x,b1y]] in moved):
                que.append([[b1x,b1y],[b2x,b2y],cnt+1])
                moved.append([[b1x,b1y],[b2x,b2y]])
    
    return answer


# 답지 코드
# 집합 자료형으로 처리하면 ((1,1),(1,2))와 (1,2),(1,1)을 같은것으로 처리한다.
