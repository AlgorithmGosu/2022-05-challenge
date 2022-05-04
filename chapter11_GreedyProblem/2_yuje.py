s = input()
result = 0
for i in range(len(s)):
    n = int(s[i]) 
    if result <= 1 or n<=1:
        result += n
    else:
        result*=n
print(result)