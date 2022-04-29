# select sort

array = [7,5,9,0,3,1,6,2,4,8]

# 가장 작은 것을 먼저 선택해서 정렬한다.
for i in range(len(array)):
    min_index = i
    for j in range(i,len(array)):
        if array[min_index] > array[j]: # 그냥 크기 비교할땐 index만 저장해서 접근해서 비교하자. 딱히 복잡도 신경안써도 되는듯
            min_index = j
    array[i],array[min_index] = array[min_index],array[i]
print(array)