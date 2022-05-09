def query_pos(query):
    if query[0] == '?' and query[-1]=='?':
        return (-1,-1)
    qs,qe = None,None
    if query[-1] != '?': # ??odo
        qe = len(query)
        left = 0
        right = len(query)-1
        while left<=right:
            mid = (left+right)//2
            if query[mid] != '?' and query[mid-1]=='?':
                qs = mid
                break
            else:
                right = mid-1
    elif query[0]!='?': # f????
        qs = 0
        left = 0
        right = len(query)-1
        while left<=right:
            mid = (left+right)//2
            if query[mid]!='?' and query[mid+1]=='?':
                qe = mid+1
                break
            else:
                left = mid+1
    return qs,qe

def solution(words,queries):
    words.sort()
    result = []
    def count_query(query):
        words_left = None
        words_right = None
        qs,qe = query_pos(query)
        if qs==-1 and qe == -1:
            return len(words)
        # words_left 찾는 중
        left = 0
        right = len(words)-1
        while left<=right:
            mid = (left+right)//2
            if len(words[mid])==len(query) and words[mid][qs:qe] == query[qs:qe] and words[mid-1][qs:qe]!=query[qs:qe]:
                words_left = mid
                break
            elif  query[qs:qe]<=words[mid][qs:qe]  or len(words[mid])<=len(query):
                right -=1
            else:
                left +=1
        
        left = 0
        right = len(words)-1
        while left<=right:
            mid = (left+right)//2
            if len(words[mid])==len(query) and words[mid][qs:qe] == query[qs:qe] and words[mid+1][qs:qe]!=query[qs:qe]:
                words_right = mid
                break
            elif  query[qs:qe]>=words[mid][qs:qe]  or len(words[mid])>=len(query):
                left +=1
            else:
                right -=1
        print(query,words_left,words_right)
        return words_right - words_left +1
    
    for query in queries:
        result.append(count_query(query))
    return result
if __name__ == '__main__':
    print(query_pos('fro??'))
    print(solution(	["frodo", "front", "frost", "frozen", "frame", "kakao"], ["fro??", "????o", "fr???", "fro???", "pro?"]))