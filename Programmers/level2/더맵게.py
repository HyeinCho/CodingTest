from heapq import heappush, heappop, heapify

def solution(scoville, K):
    answer = -1
    heapify(scoville)
    
    cnt = 0
    while scoville:
        a = heappop(scoville)
        if a >= K:
            answer = cnt
            break
            
        if not scoville:
            break
        
        b = heappop(scoville)
        heappush(scoville, a + b * 2)
        cnt += 1
    
    return answer
