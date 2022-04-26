# 내가 한 거
# N = int(input())
# coin = 0
# while(N>=500):
#     N-=500
#     coin+=1
# while(N>=100):
#     N-=100
#     coin+=1
# while(N>=50):
#     N-=50
#     coin+=1
# while(N>=10):
#     N-=10
#     coin+=1
# print(coin)

# 답지 참조
N = int(input())
coins = [500,100,50,10]
num = 0
for coin in coins:
    num+=N//coin # // => 5 // 2 = 2
    N %= coin # % => 5 % 2 = 1 (나머지)
print(num)