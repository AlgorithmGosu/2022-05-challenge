def divide(x,y):
    if x >= 0:
        return x//y
    elif x<0:
        return -((-x)//y)

n = int(input())
data = list(map(int,input().split()))
# 0:+ 1:- 2:x 3://
oper = list(map(int,input().split()))
results = []
def dfs(value, oper_left,count):
    if count == n:
        results.append(value)
    for i in range(4):
        tvalue = value
        if oper_left[i]!=0:
            if i == 0:
                tvalue += data[count]
            elif i == 1:
                tvalue -= data[count]
            elif i == 2:
                tvalue *=data[count]
            else:
                tvalue = divide(tvalue,data[count])
            oper_left[i]-=1
            dfs(tvalue,oper_left,count+1)
            oper_left[i]+=1
dfs(data[0],oper,1)

print(max(results))
print(min(results))   