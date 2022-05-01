n = int(input())
dp_table = [0]*n
dp_table[0]=1
dp_table[1]=3
for i in range(2,n):
    dp_table[i]=dp_table[i-1]+dp_table[i-2]*2
print(dp_table[n-1]%796796)