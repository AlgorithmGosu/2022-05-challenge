array = [7,5,9,0,3,1,6,2,4,8]
minV,maxV = min(array),max(array)
count = [0]*(maxV-minV+1)
for a in array:
    count[a-minV] +=1
for i,c in zip(range(minV,maxV+1),count):
    for _ in range(c):
        print(i)

count = [0]*(max(array)+1)

for i in range(len(array)):
    count[array[i]] += 1

for i in range(len(count)):
    for j in range(count[i]):
        print(i, end=' ')