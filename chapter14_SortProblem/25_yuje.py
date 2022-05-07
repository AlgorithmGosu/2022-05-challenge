def solution(n, stages):
    blockedAt = [0]*(n+2)
    users = len(stages)
    for i in range(len(stages)):
        blockedAt[stages[i]]+=1
    fail = [0]*(n+2)
    for i in range(1,n+2):
        if users == 0:
            fail[i] = (0,i)
        else:
            fail[i] = (blockedAt[i]/users,i)
        users -= blockedAt[i]
    answer = sorted(fail[1:-1],key=lambda x:[-x[0],x[1]])
    answer = [a[1] for a in answer]
    
    return answer

print(solution(4,[4,4,4,4,4]))