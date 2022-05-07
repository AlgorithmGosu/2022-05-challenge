# 내 코드
def solution(s):
    if len(s)==1: # 1일때 따로 처리.
        return 1
    step_result = [None]*(len(s)//2+1)
    # string_result = [None]*(len(s)//2+1)
    for step in range(1,len(s)//2+1):
        result = ''
        now_string = ''
        pre_string = s[0:step]
        count = 1
        now = step
        while True:
            if now + step > len(s):
                if count != 1:
                    result +=(pre_string+str(count))
                else:
                    result += pre_string
                break
            now_string = s[now:now+step]
            
            if now_string == pre_string:
                count+=1
                now = now+step
            else:
                if count != 1:
                    result += (pre_string+str(count))
                else:
                    result += pre_string
                count = 0
                pre_string = now_string
        result += s[now:len(s)]
        step_result[step]=len(result)
        # string_result[step]=(result)
    # print(string_result[1:])
    return min(step_result[1:])
if __name__ == "__main__":
    s = input()
    print(solution(s))
def solution(s):
    answer = len(s)
    for step in range(1,len(s)//2+1):
        compressed = ''
        prev = s[0:step]
        count=1
        for j in range(step,len(s),step): # j = step / step + step / step+ 2step ...
            if prev == s[j:j+step]:
                count+=1
            else:
                compressed += str(count)+ prev if count >=2 else prev # count>=2이면 str(count)+prev를, 그렇지 않으면 prev를
                prev = s[j:j+step]
                count+=1
        # 남아 있는 문자열에 대해서 처리
        compressed += str(count)+prev if count>=2 else prev # 이렇게 핵심 코드를 한줄로 작성하면 코드 작성하는데 훨씬 편해질듯
        answer = min(answer,len(compressed))
    return answer
                