#include<iostream>
#include<string.h>

using namespace std;

int n, m;
int arr[500][500];
int dp[500][500];
int dx[] = { 1,0,-1,0 };
int dy[] = { 0,1,0,-1 };

int dfs(int x, int y) {
	if (x == m - 1 && y == n - 1) {
		return 1;
	}

	if (dp[x][y] != -1) return dp[x][y];

	dp[x][y] = 0;
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (nx < 0 || nx >= m || ny < 0 || ny >= n) continue;
		if (arr[x][y] > arr[nx][ny]) {
			dp[x][y] += dfs(nx, ny);
		}
	}
	return dp[x][y];
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	
	cin >> m >> n;
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) cin >> arr[i][j];
	}
	memset(dp, -1, sizeof(dp));
	dfs(0, 0);
	cout << dp[0][0];

	return 0;
}
