# import sys
# from bisect import bisect_left,bisect_right

# input = sys.stdin.readline
# n,x=map(int,input().split())
# data=list(map(int,input().split()))
# # solution1
# if bisect_right(data,x)==0 or bisect_left(data,x)==len(data):
#     print(-1)
# else:
#     print(bisect_right(data,x)-bisect_left(data,x))

# # solution2
# def my_left(x):
#     left = 0
#     right = len(data)-1
#     while left <=right:
#         mid = (left+right)//2
#         if data[mid] == x and (mid==0 or data[mid-1]!=x):
#             return mid
#         elif data[mid]>=x:
#             right = mid-1
#         else:
#             left = mid+1
#     return -1
# def my_right(x):
#     left = 0
#     right = len(data)-1
#     while left <=right:
#         mid = (left+right)//2
#         if data[mid] == x and (mid==len(data)-1 or data[mid+1]!=x):
#             return mid
#         elif data[mid]<=x:
#             left = mid+1
#         else:
#             right = mid-1
#     return -1
# # print(my_left(x))
# # print(my_right(x))
# print(my_right(x)-my_left(x)+1)

def count_by_value(array,x):
    n = len(array)
    a = first(array,x,0,n-1)
    if a == None:
        return 0
    b = last(array,x,0,n-1)
    return b -a +1

def first(array,target,start,end):
    if start > end:
        return None
    mid = (start+end)//2
    # (가장 왼쪽이거나, 왼쪽보다 크고) 타겟이랑 값이 같을 때
    if (mid == 0 or target > array[mid-1]) and array[mid] == target:
        return mid
    # 중간점의 값 보다 찾고자 하는 값이 작거나 같은 경우 왼쪽 확인
    elif array[mid]>= target:
        return first(array,target,start,mid-1)
    else:
        return first(array,target,mid+1,end)
def last(array,target,start,end):
    start = 0
    end = len(array)-1
    while start<=end:
        mid = (start+end)//2
        if (mid == len(array)-1 or array[mid+1]>target) and array[mid]==target:
            return mid
        elif array[mid] <= target:
            start  = mid +1
        else:
            end = mid -1
    return None

n,x = map(int,input().split())
array = list(map(int,input().split()))
count = count_by_value(array,x)
if count == 0:
    print(-1)
else:
    print(count)