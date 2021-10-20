#include<iostream>
#include<cmath>
#include<queue>

using namespace std;

int n, q, l;
int dx[] = { 0,1,0,-1,0 };
int dy[] = { 1,0,-1,0,1 };
int ice[64][64];
bool visited[64][64];

void rotate(int x, int y, int size) {
	queue<int> q;

	int nx = x;
	int ny = y;
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < size - 1; j++) {
			nx += dx[i];
			ny += dy[i];
			q.push(ice[nx][ny]);
		}
	}

	nx = x;
	ny = y + size - 1;
	for (int i = 1; i < 5; i++) {
		for (int j = 0; j < size - 1; j++) {
			nx += dx[i];
			ny += dy[i];
			ice[nx][ny] = q.front();
			q.pop();
		}
	}

	if(size > 2) rotate(x + 1, y + 1, size - 2);
}

void meltIce() {
	queue<pair<int, int>> q;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (ice[i][j] == 0) continue;
			int cnt = 0;
			for (int d = 0; d < 4; d++) {
				int nx = i + dx[d];
				int ny = j + dy[d];
				if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
				if (ice[nx][ny] > 0) cnt++;
			}
			if (cnt < 3) {
				q.push({ i, j });
			}
		}
	}

	while (!q.empty()) {
		ice[q.front().first][q.front().second]--;
		q.pop();
	}
}

int mergeCount(int x, int y) {
	int cnt = 1;
	queue<pair<int, int>> q;
	q.push({ x, y });
	visited[x][y] = true;

	while (!q.empty())
	{
		x = q.front().first;
		y = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
			if (visited[nx][ny] || ice[nx][ny] == 0) continue;
			visited[nx][ny] = true;
			q.push({ nx, ny });
			cnt++;
		}

	}

	return cnt;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> q;
	n = pow(2, n);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) cin >> ice[i][j];
	}

	while (q--) {
		cin >> l;
		l = pow(2, l);
		for (int i = 0; i < n; i += l) {
			for (int j = 0; j < n; j += l) {
				rotate(i, j, l);
			}
		}

		meltIce();
	}

	int answer1 = 0;
	int answer2 = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			answer1 += ice[i][j];
			if (!visited[i][j] && ice[i][j] > 0) {
				int tmp = mergeCount(i, j);
				if (answer2 < tmp) answer2 = tmp;
			}
		}
	}

	cout << answer1 << '\n' << answer2;

	return 0;
}
