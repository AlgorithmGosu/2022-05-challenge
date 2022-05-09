n = int(input())
data =[]
for _ in range(n):
    data.append(list(map(int,input().split())))

for i in range(n-1):
    for j in range(len(data[i+1])):
        if j == 0 :
            data[i+1][j] += data[i][0]
        elif j == len(data[i+1])-1:
            data[i+1][j] += data[i][-1]
        else:
            data[i+1][j] += max(data[i][j-1],data[i][j]) 
# for d in data:
#     print(d)
print(max(data[-1]))