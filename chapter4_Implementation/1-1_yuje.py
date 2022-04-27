# 내 코드
# N = int(input())
# data = map(str,input().split())
# dir = {
# 'L':(0,-1),
# 'R':(0,1),
# 'U':(-1,0),
# 'D':(1,0)
# }

# def ifmove(cur,dir):
#     return(cur[0]+dir[0],cur[1]+dir[1])

# now = (1,1)
# for d in data:
#     move = dir[d]
#     ud,lr = ifmove(now,move) # x,y와 2차원 사용하면 좌우위아래 헷갈림. 그냥 x,y 대신 ud(up down) & lr(left right)쓰는게 맘편할듯?
#     if  not (0<ud<N+1 and 0<lr<N+1) : # x<1 or x>N => not (1<x<N) 아님; not(1<=x<=N) 임. 
#         continue
#     now = (ud,lr) # 답(now) 변수를 선언해두고, 실질적으로 변경될때만 업데이트 해주는게 나에게 맞는듯
# print(now[0],now[1])

N = int(input())
lr, ud = 1,1
plans = input().split()

# L R U D
dlr = [0,0,-1,1]
dud = [-1,1,0,0]
move_types = ['L','R','U','D']

for plan in plans:
    for i in range(len(move_types)): # 리스트는 for문을 돌아야 함. dictionary는 해시테이블을 사용해서 웬만하면 O(1)따라서 딕셔너리가 이득
        if plan == move_types[i]:
            nlr = lr + dlr[i]
            nud = ud + dud[i]

    if nlr <1 or nud < 1 or nlr>N or nud>N:
        continue
    lr,ud = nlr,nud 
print(lr,ud)        