# 내 코드
# n = int(input())
# data = list(map(int,input().split()))
# nums = [0]*n

# for i in range(n-1,-1,-1):
#     if i == n-1:
#         nums[i]=1
#         continue
#     largest = 0
#     for j in range(n-1,i-1,-1):
#         if data[i] > data[j]:
#             largest = max(nums[j],largest)
#     nums[i] = largest+1
# print(nums)
# print(n -max(nums))

# n = int(input())
# array = list(map(int,input().split()))
# array.reverse()

# dp = [1]*n
# for i in range(1,n):
#     for j in range(0,i):
#         if array[j]<array[i]:
#             dp[i]=max(dp[i],dp[j]+1)
# print(dp)
# print(n-max(dp))