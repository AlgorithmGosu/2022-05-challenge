N,M = map(int,input().split())
data = list(map(int,input().split()))

start=0
end = max(data)

while(start<=end):
    mid = (start+end)//2
    cut = [(d-mid) if d-mid>0 else 0 for d in data]
    if sum(cut) == M:
        print(mid)
        break
    if sum(cut)< M:
        end = mid -1
    else:
        start = mid+1

