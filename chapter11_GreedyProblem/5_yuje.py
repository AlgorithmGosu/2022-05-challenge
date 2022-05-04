n,m=map(int,input().split())
data = list(map(int,input().split()))
# n <=1000 / m<=10 / 1<=k<=m 최대 무게 <= 공의 개수

count =0
# 복잡도 n^2 
for i in range(n):
    for j in range(i,n):
        if data[i]!=data[j]:
            count+=1
print(count)

array=[0]*11
for x in data:
    array[x]+=1
# 복잡도 훨씬 낮네
# 같은 무게는 안든다. => 무게로 array작성해볼 생각
result = 0
for i in range(1,m+1):
    n-=array[i]
    result += array[i]*n
print(count)