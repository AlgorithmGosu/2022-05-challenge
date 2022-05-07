data = list(map(str,input()))
# ord(문자) => 숫자
# chr(숫자) => 문자
# 문자.isalpha, 문자(숫자).isdigit
num = 0
eng = []
for d in data:
    if ord('0')<= ord(d)<=ord('9'):
        num+=int(d)
    else:
        eng.append(d)
eng.sort()
answer = ''
for e in eng:
    answer+=e
if num != 0:
    answer += str(num)

print(answer)

