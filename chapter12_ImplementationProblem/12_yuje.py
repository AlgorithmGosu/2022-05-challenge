# def solution(n, build_frame):
#     # 설치할 때
#     result = []
#     for build in build_frame:
#         #가로, 세로, 재료, 오퍼레이터
#         x,y,mat,opt = build
#         # print('build oper:',build)
#         # print(result)
#         if opt == 1: # 설치
#             if mat == 0: # 기둥 설치
#                 if y == 0: # 바닥이면
#                     result.append([x,y,mat])
#                     continue
#                 else: # 바닥이 아니면
#                     # x,y-1에 기둥이 있거나,  x,y에 보가 있거나, x-1,y에 보가 있으면 된다.
#                     if [x,y-1,0] in result or [x,y,1] in result or [x-1,y,1] in result:
#                         result.append([x,y,mat])
#                         continue
#             if mat == 1: # 보 설치
#                 # 기둥
#                 if [x-1,y,1] in result and [x+1,y,1] in result:
#                     result.append([x,y,mat])
#                     continue
#                 # 
#                 elif [x,y-1,0] in result or [x+1,y-1,0] in result:
#                     result.append([x,y,mat])
#                     continue
#         elif opt==0: # 삭제
#             canDelete = True
#             if mat == 0: # 기둥 삭제
#                 if [x,y+1,0] in result:
#                     if not ([x-1,y,1] in result or [x,y,1] in result):
#                         canDelete = False
#                 # 왼쪽 위에 보가 있다면
#                 if [x-1,y+1,1] in result:
#                     if not (([x-1,y,0] in result) or ([x-2,y+1,1] in result and [x,y+1,1] in result)):
#                         canDelete = False
#                 # 오른쪽 위에 보가 있다면
#                 if [x,y+1,1] in result:
#                     if not (([x+1,y,0]in result) or ([x-1,y+1,1] in result and [x+1,y+1,1]in result)):
#                         canDelete = False
#                 if canDelete:
#                     result.remove([x,y,mat])
#             if mat == 1: # 보 삭제  
#                 # 보 위에 기둥이 있으면
#                 if [x,y,0] in result:
#                     if not ([x,y-1,0] in result or [x-1,y,1] in result):
#                         canDelete = False
#                 if [x+1,y,0] in result:
#                     if not ([x+1,y-1,0] in result or [x+1,y,1] in result):
#                         canDelete = False
#                 # 보 옆에 보가 있다면
#                 if [x-1,y,1] in result:
#                     if not ([x-1,y-1,0] in result or [x,y-1,0] in result):
#                         canDelete = False
#                 if [x+1,y,1] in result:
#                     if not ([x+1,y-1,0] in result or [x+2,y-1,0] in result):
#                         canDelete = False
#                 if canDelete:
#                     result.remove([x,y,mat])
#     result.sort()
#     return result

def possible(answer):
    for x,y, stuff in answer:
        if stuff == 0:
            if y== 0 or [x-1,y,1] in answer or [x,y,1] in answer or [x,y-1,0] in answer:
                continue
            return False
        elif stuff == 1:
            if [x,y-1,0] in answer or [x+1,y-1,0] in answer or ([x-1,y,1] in answer and [x+1,y,1] in answer):
                continue
            return False
        return True

def solution(n,build_frame):
    answer = []
    for frame in build_frame:
        x,y,stuff,operate = frame
        if operate == 0:
            answer.remove([x,y,stuff])
            if not possible(answer):
                answer.append([x,y,stuff])
        if operate == 1:
            answer.append([x,y,stuff])
            if not possible(answer):
                answer.remove([x,y,stuff])
    return sorted(answer)