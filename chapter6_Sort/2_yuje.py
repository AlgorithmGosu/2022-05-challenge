N = int(input())
data = []
for _ in range(N):
    data.append(int(input()))
data.sort(reverse=True)
for d in data:
    print(d,end=' ')