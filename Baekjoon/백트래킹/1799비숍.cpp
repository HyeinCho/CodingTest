#include<iostream>

using namespace std;

int n;
int maxi = 0;
int chess[10][10];
bool visited[10][10];
bool verti1[20];
bool verti2[20];

// 이걸 이용하면 시간초과
//bool verti(int x, int y) {
//	// 하향 대각선
//	for (int i = 1; i < n; i++) {
//		int nx = x + i;
//		int ny = y + i;
//		if (nx < 0 || nx >= n || ny < 0 || ny >= n) break;
//		if (visited[nx][ny]) return false;
//	}
//	for (int i = 1; i < n; i++) {
//		int nx = x - i;
//		int ny = y - i;
//		if (nx < 0 || nx >= n || ny < 0 || ny >= n) break;
//		if (visited[nx][ny]) return false;
//	}
//
//	// 상향 대각선
//	for (int i = 1; i < n; i++) {
//		int nx = x + i;
//		int ny = y - i;
//		if (nx < 0 || nx >= n || ny < 0 || ny >= n) break;
//		if (visited[nx][ny]) return false;
//	}
//	for (int i = 1; i < n; i++) {
//		int nx = x - i;
//		int ny = y + i;
//		if (nx < 0 || nx >= n || ny < 0 || ny >= n) break;
//		if (visited[nx][ny]) return false;
//	}
//	return true;
//}

void dfs(int cnt, int x, int y) {
	if (maxi < cnt) maxi = cnt;
	if (x == n) return;

	for (int i = y; i < n; i++) {
		if (chess[x][i] == 0 || visited[x][i] || verti1[x + i] || verti2[x - i + n - 1]) {
			if (i == n - 1) dfs(cnt, x + 1, 0);
			else continue;
		}
		else {
			verti1[x + i] = true;
			verti2[x - i + n - 1] = true;
			visited[x][i] = true;
			if (i == n - 1) {
				dfs(cnt + 1, x + 1, 0);
			}
			else {
				dfs(cnt + 1, x, i + 1);
			}
			visited[x][i] = false;
			verti1[x + i] = false;
			verti2[x - i + n - 1] = false;
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) cin >> chess[i][j]; //비숍을 놓을 수 있는 곳 1
	}
	dfs(0, 0, 0);
	cout << maxi;

	return 0;
}
