/*
체스판 모든 곳을 다 들리면 O(2^(N * N))로 시간초과
=> 흑백은 서로 영향을 주지 않으므로 구분해서 진행하면 O(2^(N/2 * N/2))
*/
#include<iostream>

using namespace std;

int n;
int maxi[2];
int chess[10][10];
bool colors[10][10];
bool verti1[20];
bool verti2[20];

void dfs(int cnt, int x, int y, bool color) {
	if (maxi[color] < cnt) maxi[color] = cnt;
	if (x == n) return;

	for (int i = y; i < n; i++) {
		if (chess[x][i] == 0 || !colors[x][i] == color || verti1[x + i] || verti2[x - i + n - 1]) {
			if (i == n - 1) dfs(cnt, x + 1, 0, color);
			else continue;
		}
		else {
			verti1[x + i] = true;
			verti2[x - i + n - 1] = true;
			if (i == n - 1) {
				dfs(cnt + 1, x + 1, 0, color);
			}
			else {
				dfs(cnt + 1, x, i + 1, color);
			}
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
		for (int j = 0; j < n; j++) {
			cin >> chess[i][j]; //비숍을 놓을 수 있는 곳 1
			if (i % 2) {
				if (j % 2) colors[i][j] = true;
			}
			else {
				if (!(j % 2)) colors[i][j] = true;
			}
		}
	}
	dfs(0, 0, 0, 0);
	dfs(0, 0, 0, 1);
	cout << maxi[0] + maxi[1];

	return 0;
}
