def solution(enter, leave):
    n = len(enter)
    
    answer = [0] * n
    
    room = []
    left = 0
    right = 0
    while left < n or right < n:
        if leave[right] in room:
            answer[leave[right]-1] += len(room) - 1
            for i in room:
                if i == leave[right]: 
                    continue
                answer[i-1] += 1
            room.remove(leave[right])
            right += 1
        else:
            room.append(enter[left])
            left += 1
        
    
    return answer
