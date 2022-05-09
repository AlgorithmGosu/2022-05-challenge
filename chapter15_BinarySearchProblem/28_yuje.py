# import sys
# n = int(input())
# input = sys.stdin.readline
# data = list(map(int,input().split()))
# left = 0
# right = len(data)-1
# while left<=right:
#     mid = (left+right)//2
#     if data[mid] == mid:
#         print(mid)
#         break
#     # 타깃보다 왼쪽에 있다는 것
#     elif data[mid] < mid:
#         left = mid +1
#     elif data[mid]> mid:
#         right = mid -1

# if left>right:
#     print(-1)

def binary_search(array,start,end):
    if start > end:
        return None
    mid = (start+end)//2
    if array[mid]==mid:
        return mid
    elif array[mid]>mid:
        return binary_search(array,start,mid-1)
    else:
        return binary_search(array,mid+1,end)
n =int(input())
array=list(map(int,input().split()))
index = binary_search(array,0,n-1)
if index == None:
    print(-1)
else:
    print(index)