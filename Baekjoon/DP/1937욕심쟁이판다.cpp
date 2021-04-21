#include<iostream>
#include<string.h>

using namespace std;

int n;
int forest[500][500];
// 상하좌우
int dx[] = { -1, 1, 0, 0 };
int dy[] = { 0, 0, -1, 1 };
int dp[500][500];

int dfs(int x, int y, int cnt) { // dfs + dp
	if (dp[x][y] != -1) {
		return dp[x][y];
	}

	bool flag = false;
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
		if (forest[x][y] < forest[nx][ny]) {
			flag = true;
			int tmp = dfs(nx, ny, cnt + 1) + 1;
			if (dp[x][y] < tmp) dp[x][y] = tmp;
		}
	}

	if (!flag) {
		return dp[x][y] = 1;
	}
	else {
		return dp[x][y];
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> forest[i][j];
		}
	}
	memset(dp, -1, sizeof(dp));
	
	int answer = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			int result = dfs(i, j, 0);
			if (answer < result) answer = result;
		}
	}
	cout << answer;

	return 0;
}
