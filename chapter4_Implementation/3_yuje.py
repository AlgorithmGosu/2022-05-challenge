# 내 코드
# 세로 x 가로
N,M = map(int,input().split(' '))
# map은 (0,0)부터 시작
ud,lr,dir = map(int,input().split(' '))
data = []
for _ in range(N):
    data.append(list(map(int,input().split(' '))))

# 반시계 방향으로 돌면 동 => 북 => 서 => 남
dir_types = [1,0,3,2]
# 해당 방향에서 바라보려는 칸: now(ud,lr) + see(ud,lr)
see = [(0,1),(-1,0),(0,-1),(1,0)]
dir = dir_types.index(dir)

# 멈춤 조건: 네방향 다 가본칸 or 바다 + 뒤에 바다

# 0:육지 1:바다 2:가본 육지
# now = (ud,lr)
count = 1
turn_count = 0
data[ud][lr]=2
# turn / see / go / can't go 처럼 행동 명칭을 정해준 후, 간단하게 주석을 달아주면 쉽게 눈에 와닿는 것 같다.
while(True):
    dir = (dir+1)%4 # turn
    nud,nlr = ud+see[dir][0],lr+see[dir][1] # see
    if data[nud][nlr] == 0: # go
        ud,lr = nud,nlr
        data[nud][nlr]=2
        turn_count = 0 
        count+=1
    elif data[nud][nlr] !=0 and turn_count <4: # can't go
        turn_count += 1 # turn_count가 어떤식으로 이루어지는지 제대로 파악하고 구현해야 한다.
                        # 이번 문제의 경우 go인 상황이면 실제적으로 turn이 이루어지긴 한다.
                        # 하지만, turn_count를 하는 이유가 go하지 못하는 상황에서 4번 can't go했는지를 확인하기 위한 도구로 사용된다.
                        # 따라서 can't go인 상황에서 turn_count += 1을 해주고, go(움직인) 상황에서는 turn_count = 0으로 초기화해주어야한다.

        continue # continue를 할 때에는 하위 조건을 모두 건너뛰어도 되는지 확인해야 한다. 
                 # 이번 문제의 경우 can't go 상황이더라도 4번 can't go된 상태이면 뒤로 가야 한다.
                 # 따라서 can't go가 4가 아닐 경우에만 continue해야 한다.
    if turn_count ==4:
        nud,nlr = ud-see[dir][0],lr-see[dir][1]
        if data[nud][nlr]==1:
            break
        ud,lr = nud,nlr
        turn_count = 0


print(count)

# # 답지 코드
# N,M = map(int,input().split())
# # 방문한 위치 저장
# d = [[0]*M for _ in range(N)] # 2차원 리스트 초기화할땐 이런식으로 해야됨.
# x,y,direction = map(int,input().split())
# d[x][y] = 1 # 현재 좌표 방문 처리

# # 전체 맵 정보
# array = []
# for i in range(N):
#     array.append(list(map(int,input().split())))
# # 북 동 남 서 방향 정의
# dx = [-1,0,1,0]
# dy = [0,1,0,-1]

# #왼쪽으로 회전
# def turn_left(): 
#     global direction
#     direction -= 1
#     if direction == -1:
#         direction = 3
#     # 이건 direction = (direction-1)%4 로 계산하면 된다.

# # 시뮬레이션
# count = 1
# turn_time = 0
# while(True):
#     turn_left()
#     nx = x + dx[direction]
#     ny = y + dy[direction]

#     if d[nx][ny]==0 and array[nx][ny] == 0:
#         d[nx][ny] =1
#         x=nx
#         y=ny
#         count +=1
#         turn_time = 0
#         continue
#     else:
#         turn_time +=1
#     # 네 방향 모두 갈 수 없는 경우
#     if turn_time == 4:
#         nx = x - dx[direction]
#         ny = y - dy[direction]
#         if array[nx][ny] == 0:
#             x,y=nx,ny
#         else:
#             break
#         turn_time = 0
# print(count)