def solution(operations):
    answer = []
    
    dq = []
    for oper in operations:
        command, num = oper.split()
        if command == 'I':
            dq.append(int(num))
        else:
            if not dq:
                continue
            dq.sort()
            if num == '-1':
                dq.pop(0)
            else:
                dq.pop()
    
    if dq:
        dq.sort()
        answer = [dq[-1], dq[0]]
    else:
        answer = [0, 0]
    return answer
