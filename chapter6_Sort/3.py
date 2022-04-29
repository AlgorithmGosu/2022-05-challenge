N = int(input())
data = []
for _ in range(N):
    name,score = input().split()
    score = int(score)
    data.append((name,score))

data.sort(key=lambda x:x[1])
for d in data:
    print(d[0], end=' ')