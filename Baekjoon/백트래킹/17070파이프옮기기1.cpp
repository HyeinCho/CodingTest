#include<iostream>

using namespace std;

int n;
int answer = 0;
int arr[16][16];

int dx[] = { 0,1,1 };
int dy[] = { 1,0,1 };

void dfs(int x, int y, int dir) {
	if (x == n - 1 && y == n - 1) {
		answer++;
		return;
	}

	for (int i = 0; i < 3; i++) {
		if (dir == 0 && i == 1) continue;
		else if (dir == 1 && i == 0) continue;
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
		if (arr[nx][ny] == 1) continue;
		if (i == 2) {
			if (arr[nx - 1][ny] == 1 || arr[nx][ny - 1] == 1) continue;
		}
		dfs(nx, ny, i);
	}
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> arr[i][j];
		}
	}

	dfs(0, 1, 0);
	cout << answer;

	return 0;
}
