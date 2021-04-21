def solution(distance, rocks, n):
    answer = 0
    rocks.append(distance)
    rocks.sort()

    left = 1
    right = distance
    while left <= right:
        mid = (left + right) // 2  # 돌 사이 거리 최솟값이 mid인 경우
        prev = 0  # 이전 돌의 값
        remove_cnt = 0
        for rock in rocks:
            if rock - prev < mid:  # 돌 사이의 거리가 mid보다 작으면 안됨! -> 제거
                remove_cnt += 1
            else:
                prev = rock

        if remove_cnt <= n:  # 지운 갯수가 n보다 작거나 같다 -> 거리를 더 늘려봐야 함
            if answer < mid:  # 최댓값 구하기
                answer = mid
            left = mid + 1
        elif remove_cnt > n:  # 지우는게 더 많다 -> 거리를 줄여야함
            right = mid - 1

    return answer


distance = 25
rocks = [2, 14, 11, 21, 17]
n = 5
print(solution(distance, rocks, n))
