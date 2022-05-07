def cut(w):
    count = 0
    for i in range(len(w)):
        if w[i]=='(':
            count +=1
        else:
            count -=1
        if count ==0:
            break
    return w[:i+1],w[i+1:]
def collect(w):
    count = 0
    for i in range(len(w)):
        if w[i]=='(':
            count +=1
        else:
            count -=1
        if count <0:
            return False
    return True
def dfs(w):
    if w =='':
        return w
    u,v = cut(w)
    if collect(u):
        return u + dfs(v)
    s ='('+ dfs(v) + ')'
    for m in u[1:len(u)-1]:
        if m == '(':
            s+=')'
        else:
            s+='('
    return s

def solution(p):
    return dfs(p)