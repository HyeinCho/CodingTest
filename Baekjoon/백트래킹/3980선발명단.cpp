#include<iostream>
#include<string.h>

using namespace std;

int answer = 0;
int player[100][11];
bool visited[11];

void dfs(int idx, int sum) {
	if (idx == 11) {
		if (answer < sum) answer = sum;
		return;
	}

	for (int i = 0; i < 11; i++) {
		if (visited[i] || player[idx][i] == 0) continue;
		visited[i] = true;
		dfs(idx + 1, sum + player[idx][i]);
		visited[i] = false;
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int C;
	cin >> C;
	for (int tc = 1; tc <= C; tc++) {
		memset(visited, false, sizeof(visited));
		answer = 0;
		for (int i = 0; i < 11; i++) {
			for (int j = 0; j < 11; j++) {
				cin >> player[i][j];
			}
		}
		dfs(0, 0);
		cout << answer << '\n';
	}

	return 0;
}
