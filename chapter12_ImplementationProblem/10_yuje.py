def turn_clock(block):
    n = len(block)
    turned = [[0]*(n) for _ in range(n)]
    for i in range(n):
        for j in range(n):
            turned[j][n-i-1] = block[i][j]
    return turned
def solution(key, lock):
    m = len(key)
    n = len(lock)
    b = 2*m+n-2
    board = [[0]*b for _ in range(b)]
    for i in range(n):
        for j in range(n):
            if lock[i][j]==1:
                board[m+i-1][m+j-1]=1
    for _ in range(4):
        key = turn_clock(key)
        for i in range(0,m+n-1):
            for j in range(0,m+n-1):
                temp_board = [row[:] for row in board[:]]
                for a in range(0,m):
                    for b in range(0,m):
                        if key[a][b] == 1 and temp_board[i+a][j+b] == 1:
                            break
                        elif key[a][b] == 1:
                            temp_board[i+a][j+b] = key[a][b]
                isKey = True
                for c in range(m-1,m+n-1):
                    for d in range(m-1,m+n-1):
                        if temp_board[c][d]==0:
                            isKey=False
                if isKey == True:
                    # for t in temp_board:
                    #     print(t)
                    return True
    return False

# 답지 코드
# def rotate_a_matrix_by_90_degree(a):
#     n = len(a)
#     m = len(a[0])
#     result = [[0]* n for _ in range(m)]
#     for i in range(n):
#         for j in range(m):
#             result[j][n-i-1]=a[i][j]
#     return result
# def check(new_lock):
#     lock_length = len(new_lock)//3
#     for i in range(lock_length,lock_length*2):
#         for j in range(lock_length,lock_length*2):
#             if new_lock[i][j]!=1:
#                 return False
#     return True
# def solution(key, lock):
#     n = len(lock)
#     m = len(key)

#     new_lock = [[0]*(n*3) for _ in range(n*3)] # 새롭게 확장하는 보드의 크기를 적당히 크게 확장해줘도 된다.(index 계산하기 편하게)
    
#     for i in range(n):
#         for j in range(n):
#             new_lock[i+n][j+n] = lock[i][j]
            
#     for rotation in range(4):
#         key = rotate_a_matrix_by_90_degree(key)
#         for x in range(n*2):
#             for y in range(n*2):
#                 for i in range(m):
#                     for j in range(m):
#                         new_lock[x+i][y+j]+=key[i][j]
#                     if check(new_lock)==True:
#                         return True
#                     for i in range(m):
#                         for j in range(m):
#                             new_lock[x+i][y+j]-=key[i][j]
    return False
if __name__ == "__main__":
    # key = [[0,0,0],[1,0,0],[0,1,1]]
    # for _ in range(4):
    #     key = turn_clock(key)
    #     for k in key:
    #         print(k)
        # print()
    print(solution([[0,0,0],[1,0,0],[0,1,1]],[[1,1,1],[1,1,0],[1,0,1]]))