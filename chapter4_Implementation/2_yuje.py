# 이동할 수 있는 방법: 8가지
# 내 코드
# input_str = input()
# lr,ud = input_str[0],input_str[1]
# ud = int(ud)
# # 아스키코드 a:97~z:113(27개) / A:64~Z:90 ord(str) -> ascii / chr(int) -> ascii
# lr = ord(lr) - 96
# # 위왼 / 위오 / 아왼 / 아오/ 왼위/왼아 /오위/오아
# dlr =[-1,1,-1,1,-2,-2,2,2]
# dud =[-2,-2,2,2,-1,1,-1,1]
# count =0
# for x,y in zip(dlr,dud):
#     nlr,nud = lr + x,ud+y
#     if 1<=nlr<=8 and 1<=nud<=8:
#         count+=1
# print(count)

#답 코드
input_data = input()
row = int(input_data[1])
column = int(ord(input_data[0])) - int(ord('a')) + 1 # => 인풋아스키값 - a아스키값 + 1 => a ~ z: 1 ~ 27로 설정할 수가 있음.

steps = [(-2,1),(-1,-2),(1,-2),(2,-1),(2,1),(1,2),(-1,2),(-2,1)] # 두 리스트로 할지, 한 리스트에 튜플로 할진 상황에 따라

result = 0
for s in steps:
    next_row = row + s[0]
    next_column = column + s[1]
    if 1<=next_row<=8 and 1<=next_column<=8: # nlr => next_lr의 약자로 사용하면 될듯?
        result+=1
print(result)