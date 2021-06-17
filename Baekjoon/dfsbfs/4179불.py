from collections import deque

dx = [0, 0, 1, -1]
dy = [1, -1, 0, 0]


def bfs():
    dq = deque()
    for tmp in fire:
        dq.append(tmp)

    while dq:
        x, y = dq.popleft()

        for i in range(4):
            nx = x + dx[i]
            ny = y + dy[i]

            if 0 <= nx < R and 0 <= ny < C:
                if maze[nx][ny] == -1:
                    maze[nx][ny] = maze[x][y] + 1
                    dq.append([nx, ny])


def escape():
    dq = deque()
    dq.append(jihun)

    while dq:
        x, y = dq.popleft()

        for i in range(4):
            nx = x + dx[i]
            ny = y + dy[i]

            if 0 <= nx < R and 0 <= ny < C:
                if visited[nx][ny] != -1:
                    continue

                if maze[nx][ny] == -2:
                    continue
                elif maze[nx][ny] == -1:
                    visited[nx][ny] = visited[x][y] + 1
                    dq.append([nx, ny])
                else:
                    if maze[nx][ny] > visited[x][y] + 1:
                        visited[nx][ny] = visited[x][y] + 1
                        dq.append([nx, ny])
            else:
                global answer
                if answer > visited[x][y] + 1:
                    answer = visited[x][y] + 1
                return


R, C = map(int, input().split())
# -2: 벽, -1: 아직 불이 없는 지나갈수 있는 공간, 자연수 n: n초 후 불
maze = [[-2 for _ in range(C)] for _ in range(R)]
jihun = []
fire = []
for i in range(R):
    tmp = list(input())
    for j in range(C):
        if tmp[j] == 'J':
            jihun = [i, j]
            maze[i][j] = -1
        elif tmp[j] == 'F':
            fire.append([i, j])
            maze[i][j] = 0
        elif tmp[j] == '.':
            maze[i][j] = -1

bfs()

answer = R * C + 1
visited = [[-1 for _ in range(C)] for _ in range(R)]
visited[jihun[0]][jihun[1]] = 0
escape()

if answer == R * C + 1:
    print('IMPOSSIBLE')
else:
    print(answer)
