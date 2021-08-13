#include<iostream>
#include<algorithm>
#include<queue>

using namespace std;

int s;
bool dp[1001][1001]; // dp[i][j] : i개가 화면에 복붙, j개가 클립보드에 있음

int imoji() {
	queue<pair<pair<int, int>, int >> q;
	dp[1][0] = true;
	q.push({ {1,0}, 0 }); // {i, j}가 time만큼 시간이 걸렸다 

	while (!q.empty()) {
		int x = q.front().first.first;
		int y = q.front().first.second;
		int time = q.front().second;
		q.pop();

		if (x == s) {
			return time;
		}

		// 화면에 있는거 복붙 후 클립보드에 저장
		if (!dp[x][x]) {
			dp[x][x] = true;
			q.push({ {x, x}, time + 1 });
		}

		// 클립보드에 있는 모든 임티를 화면에 붙여넣기
		if (x + y < 1001 && !dp[x + y][y]) {
			dp[x + y][y] = true;
			q.push({ {x + y, y}, time + 1 });
		}

		// 화면에 있는 임티 중 하나 삭제
		if (x > 1 && !dp[x - 1][y]) {
			dp[x - 1][y] = true;
			q.push({ {x - 1, y}, time + 1 });
		}

	}
}

int main() {
	cin >> s;
	cout << imoji();
	return 0;
}
