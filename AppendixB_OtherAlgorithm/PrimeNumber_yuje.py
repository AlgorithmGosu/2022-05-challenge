def is_prime_number(x):
    for i in range(2,x):
        if x % i == 0:
            return False
    return True
print(is_prime_number(4))
print(is_prime_number(7))

# 숫자의 특징
# 16 = 1 x 16
#      2 x 8
#      4 x 4 => 제곱근까지만 확인하면 됨.
import math
def is_prime_number(x):
    for i in range(2,int(math.sqrt(x)+1)):
        if x % i ==0:
            return False
    return True

print(is_prime_number(4))
print(is_prime_number(7))