#include<iostream>
#include<queue>

using namespace std;

int n, m;
int dx[] = { 1,0,-1,0 };
int dy[] = { 0,1,0,-1 };
int cheese[100][100];
int melt[100][100]; // 치즈 내부 빈 공간 : 0, 치즈 : 1, 치즈 외부 : 2 

// 치즈 외부 파악하기
void surround(int x, int y) {
	queue<pair<int, int>> q;
	q.push({ x, y });

	while (!q.empty()) {
		pair<int, int> tmp = q.front();
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = tmp.first + dx[i];
			int ny = tmp.second + dy[i];

			if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
			if (melt[nx][ny] == 0) {
				melt[nx][ny] = 2;
				q.push({ nx, ny });
			}
		}
	}
}

int melting() {
	queue<pair<int, int>> soon;

	for (int i = 1; i < n - 1; i++) {
		for (int j = 1; j < m - 1; j++) {
			if (melt[i][j] == 1) {
				bool flag = true;
				for (int d = 0; d < 4; d++) {
					int nx = i + dx[d];
					int ny = j + dy[d];
					if (melt[nx][ny] == 2) {
						flag = false;
						break;
					}
				}
				if (!flag) { // 녹을 예정
					soon.push({ i, j });
				}
			}
		}
	}

	int cnt = soon.size(); // 녹은 치즈
	// 녹이기 (1 -> 2)
	while (!soon.empty()) {
		melt[soon.front().first][soon.front().second] = 2;
		soon.pop();
	}

	// 치즈가 녹아서 구멍이 열려 구멍 속으로 공기가 들어가게 된 경우
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (melt[i][j] == 2) surround(i, j);
		}
	}

	return cnt;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int time = 0, total = 0; // 걸린 시간, 모두 녹기 한 시간 전 치즈조각 갯수 

	cin >> n >> m;

	// 입력 받기
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> cheese[i][j];
			if (cheese[i][j] == 1) {
				melt[i][j] = 1;
				total++;
			}
		}
	}
	surround(0, 0); // 치즈 외부 파악하기
	
	while (++time) {
		int cnt = melting();
		if (total == cnt) { // 다 녹음
			break;
		}
		total -= cnt;
	}

	cout << time << '\n' << total;

	return 0;
}
