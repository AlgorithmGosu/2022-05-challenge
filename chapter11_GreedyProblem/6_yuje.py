import heapq
def solution(food_times, k):
    if sum(food_times)<=k:
        return -1
    answer = 0
    q = []
    
    for i in range(len(food_times)):
        heapq.heappush(q,(food_times[i],i+1))
    
    sum_time = 0
    pre = 0
    now_len = len(food_times)
    
    while sum_time + ((q[0][0] - pre) * now_len) <=k:
        now = heapq.heappop(q)[0]
        sum_time += (now-pre)*now_len
        now_len -=1
        pre = now
        
    remainder_time = k - sum_time
    food_len = len(q)
    res = sorted(q,key=lambda x:x[1])
    temp = remainder_time //food_len
    remainder_time -= temp*food_len
    
    return res[remainder_time][1]