n = int(input())
front = 1
rear = n

while front <= rear:
    mid = (front + rear) // 2
    if mid*mid > n:
        rear = mid - 1
    elif mid*mid < n:
        front = mid + 1
    else:
        print(mid)
        break
