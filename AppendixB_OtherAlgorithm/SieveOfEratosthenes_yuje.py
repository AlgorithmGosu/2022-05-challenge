# 에라토스테네스의 체
# N보다 작거나 같은 모든 소수를 찾을 때 사용
# 방법
# 1. 2부터 N까지 모든 자연수를 나열한다.
# 2. 남은 수중에서 아직 처리하지 않은 가장 작은 수 i를 찾는다.
# 3. 남은 수 중에서 i의 ㅂ배수를 모두 제거한다.
# 4. 더 이상 반복할 수 없을 때까지 2,3번 과정을 반복한다.

import math
n = 1000
array = [True for i in range(n+1)]

for i in range(2,int(math.sqrt(n)+1)):
    if array[i] == True: # i가 소수인 경우 ( 남은 수인 경우)
        # i를 제외한 i의 모든 배수를 지우기
        j = 2
        while i*j<=n:
            array[i*j] = False
            j +=1
for i in range(2,n+1):
    if array[i]:
        print(i,end=' ')
