# n = int(input())

# data =[0]+list(map(int,input().split()))
# dp_table = [0]*101
# dp_table[1]=data[1]
# dp_table[2]=max(data[1],data[2])

# for i in range(2,n+1):
#     if dp_table[i-2]+data[i] > dp_table[i-1]:
#         dp_table[i]=dp_table[i-2]+data[i]
#     else:
#         dp_table[i]=dp_table[i-1]
# print(dp_table[n])

n = int(input())
data = list(map(int,input().split()))
dp_table= [0]*100

dp_table[0]=data[0]
dp_table[1]=max(data[0],data[1])

for i in range(2,n):
    dp_table[i]=max(dp_table[i-1],dp_table[i-2]+data[i])
print(dp_table[n-1])