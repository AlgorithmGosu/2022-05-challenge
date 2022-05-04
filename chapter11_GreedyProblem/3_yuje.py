s = list(map(int,input()))

cnt0=0
cnt1=0
now = s[0]
for n in s:
    if n==1 and now ==0:
        cnt1+=1
        now=1
    elif n==0 and now ==1:
        cnt0+=1
        now=0
print(min(cnt0,cnt1))

# for i in range(len(s)-1):
#     if s[i] !=s[i+1]:
#         if s[i+1]=='1':
#             cnt0+=1
#         else:
#             cnt1+=1
# print(min(cnt0,cnt1))