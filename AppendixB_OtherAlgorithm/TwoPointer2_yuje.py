# 정렬된 두 배열
# 정렬 유지 머지방법 O(N+M)
n,m=3,4
a=[1,3,5]
b=[2,4,6,8]

result = [0]*(n+m)
i=j=k=0

while i<n or j<m:
    if j>=m or (i<n and a[i]<b[j]):
        result[k]=a[i]
        i+=1
    else:
        result[k]=b[j]
        j+=1
    k+=1
for i in result:
    print(i,end = ' ')