#include<iostream>
#include<vector>
#include<queue>
#include<deque>

using namespace std;

int n, k, l;
int board[101][101];
deque<pair<int, int>> snake;
queue<pair<int, char>> change;
int dx[] = { 0,1,0,-1 }; //시계
int dy[] = { 1,0,-1,0 };

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> k;

	for (int i = 0; i < k; i++) {
		int a, b;
		cin >> a >> b;
		board[a][b] = 2;
	}
	cin >> l;
	for (int i = 0; i < l; i++) {
		int a;
		char b;
		cin >> a >> b;
		change.push({ a,b });
	}

	snake.push_front({ 1,1 });
	board[1][1] = 1;
	int time = 0;
	int dir = 0;
	while (1) {
		time++;
		int nx = snake.front().first + dx[dir];
		int ny = snake.front().second + dy[dir];
		if (nx <= 0 || nx > n || ny <= 0 || ny > n) break; //벽에 부딧히면
		if (board[nx][ny] == 1) break; //본인의 몸과 부딧히면
		
		snake.push_front({ nx,ny });
		if (board[nx][ny] == 0) {
			int tx = snake.back().first;
			int ty = snake.back().second;
			snake.pop_back();
			board[tx][ty] = 0;
		}
		board[nx][ny] = 1;

		if (!change.empty() && time == change.front().first) {
			if (change.front().second == 'L') { //반시계
				dir = dir == 0 ? 3 : dir - 1;
			}
			else { //시계
				dir = dir == 3 ? 0 : dir + 1;
			}
			change.pop();
		}
	}

	cout << time;
	return 0;
}
