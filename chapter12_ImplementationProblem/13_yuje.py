import sys
from itertools import combinations

input = sys.stdin.readline

n,m = map(int,input().split())
city = list(list(map(int,input().split())) for _ in range(n))
result = 1e8
house = []   # 집의 좌표
chicken = [] # 치킨집 좌표

for i in range(n):
  for j in range(n):
    if city[i][j]==1:
      house.append([i,j])
    elif city[i][j]==2:
      chicken.append([i,j])
for chi in combinations(chicken,m):
  temp = 0
  for h in house:
    chi_len = 999
    for j in range(m):
        chi_len = min(chi_len, abs(h[0] - chi[j][0]) + abs(h[1] - chi[j][1]))
    temp += chi_len
  result = min(result, temp)

print(result)