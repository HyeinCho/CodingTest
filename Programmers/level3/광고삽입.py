def change_second(time):
    time = list(map(int, time.split(':')))
    second = 0
    sixty = 1
    for i in range(2, -1, -1):
        second += time[i] * sixty
        sixty *= 60
    return second


def change_time(second):
    s = ''
    sixty = 3600
    for i in range(3):
        time = second // sixty

        if 0 <= time <= 9:
            s += '0'
        s += str(time) + ':'

        second %= sixty
        sixty //= 60

    return s[:-1]


def solution(play_time, adv_time, logs):
    answer = ''
    play_time_second = change_second(play_time)
    adv_time_second = change_second(adv_time)

    dp = [0] * (play_time_second + 1)
    for log in logs:
        start = change_second(log[:8])
        end = change_second(log[9:])
        dp[start] += 1
        dp[end] -= 1

    for i in range(1, play_time_second + 1):
        dp[i] += dp[i - 1]

    cur_time = sum(dp[:adv_time_second])
    max_time = cur_time  # 누적 재생 최대 시간
    answer_time = adv_time_second - 1  # 끝 시간
    for i in range(adv_time_second, play_time_second + 1):
        cur_time -= dp[i - adv_time_second]
        cur_time += dp[i]
        if max_time < cur_time:
            max_time = cur_time
            answer_time = i

    answer = change_time(answer_time - adv_time_second + 1)

    return answer
