import itertools
l,c=map(int,input().split())
data = list(map(str,input().split()))
data.sort()
vowel = ['a','e','i','o','u']
for x in itertools.combinations(data,l):
    count = 0
    for spell in x:
        if spell in vowel:
            count+=1
    if 1<=count<=l-2:
        print(''.join(x))