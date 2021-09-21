G = int(input())

e = 1
s = 1
flag = False

while True:
    mid = e ** 2 - s ** 2

    if mid > G:
        if e - s == 1:
            break
        s += 1
    elif mid < G:
        e += 1
    else:
        print(e)
        flag = True
        e += 1

if not flag:
    print(-1)
