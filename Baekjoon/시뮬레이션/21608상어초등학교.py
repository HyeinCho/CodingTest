dx = [1, 0, -1, 0]
dy = [0, 1, 0, -1]


def game():
    answer = []
    for i in range(1, N + 1):
        for j in range(1, N + 1):
            if board[i][j] != 0:
                continue
            tmp_cnt = 0
            empty_cnt = 0
            for k in range(4):
                nx = i + dx[k]
                ny = j + dy[k]
                if 0 < nx <= N and 0 < ny <= N:
                    for n in info[1:]:
                        if n == board[nx][ny]:
                            tmp_cnt += 1
                            break
                    if board[nx][ny] == 0:
                        empty_cnt += 1

            answer.append([tmp_cnt, empty_cnt, i, j])

    answer.sort(key=lambda x: (-x[0], -x[1], x[2], x[3]))
    board[answer[0][2]][answer[0][3]] = info[0]


def satisfy():
    total = 0
    for i in range(1, N + 1):
        for j in range(1, N + 1):
            tmp = 0
            for k in range(4):
                nx = i + dx[k]
                ny = j + dy[k]

                if 0 < nx <= N and 0 < ny <= N:
                    if board[nx][ny] in infos[board[i][j] - 1][1:]:
                        tmp += 1

            if tmp == 1:
                total += 1
            elif tmp == 2:
                total += 10
            elif tmp == 3:
                total += 100
            elif tmp == 4:
                total += 1000

    return total


N = int(input())
board = [[0 for _ in range(N + 1)] for _ in range(N + 1)]
infos = []
result = 0
for _ in range(N * N):
    info = list(map(int, input().split()))
    infos.append(info)
    game()

infos.sort()

print(satisfy())
