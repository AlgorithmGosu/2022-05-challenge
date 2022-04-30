# insert sort
# 0~i까지를 정렬한 array / i+1 ~ N 까지를 정렬하지 않은 array로 판단.
# i+1번째 아이템을 꺼내서 정렬된 array에서 올바른 위치에 삽입.
array = [7,5,9,0,3,1,6,2,4,8]
# 7
# 5 7
# 5 7 9
# 5 7 0 9
# 5 0 7 9
# 0 5 7 9
for i in range(1,len(array)):
    for j in range(i,0,-1):
        if array[j]<array[j-1]:
            array[j],array[j-1] = array[j-1],array[j]
        else:
            break
print(array)