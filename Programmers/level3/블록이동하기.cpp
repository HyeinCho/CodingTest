#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <string.h>

using namespace std;

int dx[] = { 0,1,0,-1 };
int dy[] = { 1,0,-1,0 };
int node[100][100][2];
bool visited[100][100][2];

struct info {
    int x;
    int y;
    int dir; // 가로, 세로
    int cnt;

    info(int x, int y, int dir, int cnt) {
        this->x = x;
        this->y = y;
        this->dir = dir;
        this->cnt = cnt;
    }
};

int bfs(vector<vector<int>> board) {
    queue<info> q;
    q.push(info(0, 0, 0, 0));
    visited[0][0][0] = 1; // 가로로 시작

    int n = board.size();

    while (!q.empty()) {
        info robot = q.front();
        q.pop();

        if (robot.x == n - 1 && robot.y == n - 2 && robot.dir == 0) { // 가로
            return robot.cnt;
        }else if(robot.x == n - 2 && robot.y == n - 1 && robot.dir == 1) { // 세로
            return robot.cnt;
        }

        for (int i = 0; i < 4; i++) { // 상하좌우
            int nx = robot.x + dx[i];
            int ny = robot.y + dy[i];
            if (nx >= 0 && nx < n && ny >= 0 && ny < n && node[nx][ny][robot.dir] == 1 && visited[nx][ny][robot.dir] == 0) {
                visited[nx][ny][robot.dir] = 1;
                q.push(info(nx, ny, robot.dir, robot.cnt + 1));
            }
        }

        // 회전
        if (robot.dir == 0) { // 가로 -> 세로
            // 아래로
            if (robot.x < n - 1 && robot.y < n - 1 && board[robot.x + 1][robot.y] == 0 && board[robot.x + 1][robot.y + 1] == 0) {
                if (visited[robot.x][robot.y][1] == 0) { 
                    visited[robot.x][robot.y][1] = 1;
                    q.push(info(robot.x, robot.y, 1, robot.cnt + 1));
                }
                if (visited[robot.x][robot.y + 1][1] == 0) {
                    visited[robot.x][robot.y + 1][1] = 1;
                    q.push(info(robot.x, robot.y + 1, 1, robot.cnt + 1));
                }
            }
            // 위로
            if (robot.x > 0 && robot.y < n - 1 && board[robot.x - 1][robot.y] == 0 && board[robot.x - 1][robot.y + 1] == 0) {
                if (visited[robot.x - 1][robot.y][1] == 0) {
                    visited[robot.x - 1][robot.y][1] = 1;
                    q.push(info(robot.x - 1, robot.y, 1, robot.cnt + 1));
                }
                if (visited[robot.x - 1][robot.y + 1][1] == 0) {
                    visited[robot.x - 1][robot.y + 1][1] = 1;
                    q.push(info(robot.x - 1, robot.y + 1, 1, robot.cnt + 1));
                }
            }
        }
        else { // 세로 -> 가로
            // 오른쪽
            if (robot.x < n - 1 && robot.y < n - 1 && board[robot.x][robot.y + 1] == 0 && board[robot.x + 1][robot.y + 1] == 0) {
                if (visited[robot.x][robot.y][0] == 0) {
                    visited[robot.x][robot.y][0] = 1;
                    q.push(info(robot.x, robot.y, 0, robot.cnt + 1));
                }
                if (visited[robot.x + 1][robot.y][0] == 0) {
                    visited[robot.x + 1][robot.y][0] = 1;
                    q.push(info(robot.x + 1, robot.y, 0, robot.cnt + 1));
                }
            }
            // 왼쪽
            if (robot.y > 0 && robot.x < n - 1 && board[robot.x][robot.y - 1] == 0 && board[robot.x + 1][robot.y - 1] == 0) {
                if (visited[robot.x][robot.y - 1][0] == 0) {
                    visited[robot.x][robot.y - 1][0] = 1;
                    q.push(info(robot.x, robot.y - 1, 0, robot.cnt + 1));
                }
                if (visited[robot.x + 1][robot.y - 1][0] == 0) {
                    visited[robot.x + 1][robot.y - 1][0] = 1;
                    q.push(info(robot.x + 1, robot.y - 1, 0, robot.cnt + 1));
                }
            }

        }
    }
}

int solution(vector<vector<int>> board) {
    int answer = 0;
    int dir = 0;
    // 가로
    for (int i = 0; i < board.size(); i++) {
        for (int j = 0; j < board.size() - 1; j++) {
            if (board[i][j] == 0 && board[i][j + 1] == 0) node[i][j][0] = 1;
        }
    }
    // 세로
    for (int i = 0; i < board.size() - 1; i++) {
        for (int j = 0; j < board.size(); j++) {
            if (board[i][j] == 0 && board[i + 1][j] == 0) node[i][j][1] = 1;
        }
    }
    memset(visited, 0, sizeof(visited));
    answer = bfs(board);

    return answer;
}
