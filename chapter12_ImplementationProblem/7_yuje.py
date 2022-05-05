data = list(map(int,input()))
length = len(data)
left = 0
right = 0
for i in range(length):
    if i < length //2:
        left += data[i]
    else:
        right += data[i]
if left == right:
    print("LUCKY")
else:
    print("READY")