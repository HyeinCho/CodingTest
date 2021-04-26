answer = 0


def calculate(calc, opers):
    if len(calc) == 1:
        global answer
        calc[0] = abs(calc[0])
        if answer < calc[0]:
            answer = calc[0]
        return

    for i in range(3):
        if opers[i] == 0:
            continue

        opers[i] = 0

        tmp = []
        idx = 0
        while idx < len(calc):
            num = calc[idx]
            if i == 0 and num == '-':
                next_num = tmp.pop() - calc[idx + 1]
                tmp.append(next_num)
                idx += 2
            elif i == 1 and num == '+':
                next_num = tmp.pop() + calc[idx + 1]
                tmp.append(next_num)
                idx += 2
            elif i == 2 and num == '*':
                next_num = tmp.pop() * calc[idx + 1]
                tmp.append(next_num)
                idx += 2
            else:
                tmp.append(num)
                idx += 1

        calculate(tmp, opers)
        opers[i] = 1


def solution(expression):
    tmp = ''
    calc = []
    opers = [0] * 3  # - + *
    for x in expression:
        if x in '-+*':
            calc.append(int(tmp))
            calc.append(x)
            tmp = ''
            if x == '-':
                opers[0] = 1
            elif x == '+':
                opers[1] = 1
            else:
                opers[2] = 1
        else:
            tmp += x
    calc.append(int(tmp))

    calculate(calc, opers)

    global answer
    return answer
