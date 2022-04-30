import sys
N = int(input())
data1 = list(map(int,sys.stdin.readline().rstrip().split()))
M = int(input())
data2 = list(map(int,sys.stdin.readline().rstrip().split()))

def binary_search(array,target,start,end):
    while(start<=end):
        mid = (start+end)//2
        if array[mid] == target:
            return True
        elif array[mid] < target:
            start = mid+1
        else:
            end = mid-1
    return False

for d in data2:
    if binary_search(data1,d,0,len(data1)-1):
        print("yes",end = ' ')
    else:
        print('no',end=' ')

    
# set() 함수
n = int(input())
array = set(map(int,input().split()))

m = int(input())
x = list(map(int,input().split()))

for i in x:
    if i in array:
        print('yes',end =' ')
    else:
        print('no',end=' ')