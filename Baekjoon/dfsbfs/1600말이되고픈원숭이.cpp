#include<iostream>
#include<queue>

using namespace std;

int k, w, h;
int board[200][200];
bool visited[200][200][31];
int dx[] = { 1, 2, 2, 1, -1, -2, -2, -1, 1, 0, -1, 0 };
int dy[] = { 2, 1, -1, -2, 2, 1, -1, -2, 0, 1, 0, -1 };

int bfs() {
	queue<vector<int>> q;
	q.push({ 0,0,k,0 });
	visited[0][0][k] = true;

	while (!q.empty()) {
		vector<int> v = q.front();
		q.pop();

		if (v[0] == h - 1 && v[1] == w - 1) {
			return v[3];
		}

		for (int i = 0; i < 12; i++) {
			int nx = v[0] + dx[i];
			int ny = v[1] + dy[i];
			if (nx < 0 || nx >= h || ny < 0 || ny >= w) continue;
			if (board[nx][ny]) continue;
			
			if (i < 8) {
				if (v[2] > 0 && !visited[nx][ny][v[2] - 1]) {
					q.push({ nx, ny, v[2] - 1, v[3] + 1 });
					visited[nx][ny][v[2] - 1] = true;
				}
			}
			else {
				if (!visited[nx][ny][v[2]]) {
					q.push({ nx, ny, v[2], v[3] + 1 });
					visited[nx][ny][v[2]] = true;
				}
			}
			
		}
	}

	return -1;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> k;
	cin >> w >> h;
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) cin >> board[i][j];
	}

	cout << bfs();

	return 0;
}
