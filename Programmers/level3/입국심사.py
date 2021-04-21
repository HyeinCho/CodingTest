answer = 0


def binarysearch(s, e, n, times):
    if s > e:
        return

    mid = (s + e) // 2
    total = 0
    for time in times:
        total += mid // time

    if total >= n:
        global answer
        if answer > mid:
            answer = mid
        binarysearch(s, mid - 1, n, times)
    elif total < n:
        binarysearch(mid + 1, e, n, times)


def solution(n, times):
    global answer
    answer = max(times) * n + 1
    binarysearch(0, answer, n, times)
    return answer


n = 2
times = [1, 2]
print(solution(n, times))
