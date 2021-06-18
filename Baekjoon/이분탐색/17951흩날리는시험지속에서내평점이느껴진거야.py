N, K = map(int, input().split())
nums = list(map(int, input().split()))

front = 0
rear = sum(nums)
while front <= rear:
    mid = (front + rear) // 2
    cnt, total = 0, 0
    for num in nums:
        total += num
        if total >= mid:
            cnt += 1
            total = 0

    if cnt >= K:
        front = mid + 1
    else:
        rear = mid - 1

print(rear)
