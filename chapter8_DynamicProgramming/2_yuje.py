# from collections import deque
# n = int(input())
# dp_table= [None]*30000
# que = deque([n])
# dp_table[n]=0
# while(True):
#     node =que.popleft()
#     if node == 1:
#         print(dp_table[node])
#         break
#     if node % 5 ==0:
#         if dp_table[node//5]==None:
#             que.append(node//5)
#             dp_table[node//5] = dp_table[node]+1
#     if node % 3==0:
#         if dp_table[node//3]==None:
#             que.append(node//3)
#             dp_table[node//3] = dp_table[node]+1
#     if node % 2 == 0:
#         if dp_table[node//2]==None:
#             que.append(node//2)
#             dp_table[node//2] = dp_table[node]+1
#     if dp_table[node-1]==None:
#         que.append(node-1)
#         dp_table[node-1]=dp_table[node]+1

x = int(input())
d=[0]*27

#바텀업 다이나믹 프로그래밍 
for i in range(2,x+1):
    d[i]=d[i-1]+1
    if i%2==0:
        d[i]=min(d[i],d[i//2]+1)
    if i%3==0:
        d[i]=min(d[i],d[i//3]+1)
    if i%5==0:
        d[i]=min(d[i],d[i//5]+1)
    print(d[x])