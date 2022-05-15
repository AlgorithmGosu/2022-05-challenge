# 접두사합: 맨 앞에서 특정 위치까지 더해놓고, 나중에 l - r해주면 구간 합 구할 수 있음.
n = 5
data=[1,2,3,4,5]

sum_value = 0
prefix_sum=[0]
for i in data:
    sum_value +=i
    prefix_sum.append(sum_value)

l=3
r=4
print(prefix_sum[r]-prefix_sum[l-1])
