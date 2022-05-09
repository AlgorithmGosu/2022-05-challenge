n = int(input())
data = list(map(int,input().split()))
nums = [0]*n

for i in range(n-1,-1,-1):
    if i == n-1:
        nums[i]=1
        continue
    largest = 0
    for j in range(n-1,i-1,-1):
        if data[i] > data[j]:
            largest = max(nums[j],largest)
    nums[i] = largest+1
print(n -max(nums))