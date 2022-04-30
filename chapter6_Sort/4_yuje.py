N,K = map(int,input().split())
ary1 = list(map(int,input().split()))
ary2 = list(map(int,input().split()))

ary1.sort()
ary2.sort(reverse=True)

pivot = 0
for i in range(K):
    if ary1[i] < ary2[i]:
        ary1[i],ary2[i]=ary2[i],ary1[i]
print(sum(ary1))
