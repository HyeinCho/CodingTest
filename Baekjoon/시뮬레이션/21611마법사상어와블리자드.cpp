#include<iostream>
#include<vector>
#include<deque>
#include<string.h>

using namespace std;

int n, m, d, s;
int shark_size = 0;
int answer[4] = { 0,0,0,0 };
int dx[] = { -1,1,0,0 };
int dy[] = { 0,0,-1,1 };
int torx[] = { 0,1,0,-1 };
int tory[] = { -1,0,1,0 };
bool visited[50][50];
int arr[50][50];

void deployDS() {
	int x = n / 2;
	int y = n / 2;
	int dir = 0;

	for (int i = 1; i <= s; i++) {
		int nx = x + i * dx[d - 1];
		int ny = y + i * dy[d - 1];
		if (nx < 0 || nx >= n || ny < 0 || ny >= n) break;
		arr[nx][ny] = 0;
	}

	// 달팽이 모양 동글뱅이 
	vector<int> tmp;
	for (int len = 1; len < n; len++) {
		for (int i = 0; i < 2; i++) {
			for (int j = 0; j < len; j++) {
				x += torx[dir];
				y += tory[dir];
				if (arr[x][y] != 0) tmp.push_back(arr[x][y]);
			}
			dir = (dir + 1) % 4;
		}

	}
	for (int i = n - 2; i >= 0; i--) {
		if (arr[0][i]) tmp.push_back(arr[0][i]);
	}

	// 앞에서부터 채워넣기
	int idx = 0;
	x = n / 2;
	y = n / 2;
	dir = 0;

	for (int len = 1; len < n; len++) {
		for (int i = 0; i < 2; i++) {
			for (int j = 0; j < len; j++) {
				x += torx[dir];
				y += tory[dir];
				if (idx < tmp.size()) arr[x][y] = tmp[idx];
				else arr[x][y] = 0;
				idx++;
			}
			dir = (dir + 1) % 4;
		}
	}
	for (int i = n - 2; i >= 0; i--) {
		if (idx < tmp.size()) arr[0][i] = tmp[idx];
		else arr[0][i] = 0;
		idx++;
	}

	shark_size = tmp.size();
}

void deployOver4() {

	while (true)
	{
		deque<int> q;
		int x = n / 2;
		int y = n / 2;
		int dir = 0;
		int prev = 0;
		int cnt = 0;
		for (int len = 1; len < n; len++) {
			for (int i = 0; i < 2; i++) {
				for (int j = 0; j < len; j++) {
					x += torx[dir];
					y += tory[dir];
					if (arr[x][y] == 0) break;
					if (arr[x][y] == prev) { // 이전이랑 같으면
						cnt++;
					}
					else { // 이전이랑 다르면
						if (cnt >= 4) {
							for (int j = 0; j < cnt; j++) q.pop_back();
							answer[prev] += cnt;
						}
						prev = arr[x][y];
						cnt = 1;
					}
					q.push_back(arr[x][y]);
				}
				dir = (dir + 1) % 4;
				if (arr[x][y] == 0) break;
			}
			if (arr[x][y] == 0) break;
		}
		for (int i = n - 2; i >= 0; i--) {
			if (arr[0][i] == 0) break;
			if (arr[0][i] == prev) { // 이전이랑 같으면
				cnt++;
			}
			else { // 이전이랑 다르면
				if (cnt >= 4) {
					for (int j = 0; j < cnt; j++) q.pop_back();
					answer[prev] += cnt;
				}
				prev = arr[0][i];
				cnt = 1;
			}
			q.push_back(arr[0][i]);
		}

		if (cnt >= 4) {
			for (int j = 0; j < cnt; j++) q.pop_back();
			answer[prev] += cnt;
		}

		if (q.size() == shark_size) break;
		shark_size = q.size();

		// 앞에서부터 채워넣기
		x = n / 2;
		y = n / 2;
		dir = 0;

		for (int len = 1; len < n; len++) {
			for (int i = 0; i < 2; i++) {
				for (int j = 0; j < len; j++) {
					x += torx[dir];
					y += tory[dir];
					if (!q.empty()) {
						arr[x][y] = q.front();
						q.pop_front();
					}
					else arr[x][y] = 0;
				}
				dir = (dir + 1) % 4;
			}
		}
		for (int i = n - 2; i >= 0; i--) {
			if (!q.empty()) {
				arr[0][i] = q.front();
				q.pop_front();
			}
			else arr[0][i] = 0;
		}

	}

}

void groupAB() {
	for (int i = 0; i < n; i++) memset(visited[i], false, sizeof(visited[i]));

	deque<int> q;
	int x = n / 2;
	int y = n / 2;
	int dir = 0;
	int prev = 0;
	int cnt = 0;
	bool flag = false;
	for (int len = 1; len < n; len++) {
		for (int i = 0; i < 2; i++) {
			for (int j = 0; j < len; j++) {
				x += torx[dir];
				y += tory[dir];
				if (arr[x][y] == 0) {
					q.push_back(cnt);
					q.push_back(prev);
					flag = true;
					break;
				}
				if (arr[x][y] == prev) { // 이전이랑 같으면
					cnt++;
				}
				else { // 이전이랑 다르면
					q.push_back(cnt);
					q.push_back(prev);
					prev = arr[x][y];
					cnt = 1;
				}
			}
			dir = (dir + 1) % 4;
			if (flag) break;
			if (q.size() >= n * n + 2) break;
		}
		if (flag) break;
		if (q.size() >= n * n + 2) break;
	}
	if (!flag) {
		for (int i = n - 2; i >= 0; i--) {
			if (arr[0][i] == 0) {
				q.push_back(cnt);
				q.push_back(prev);
				cnt = -1;
				prev = -1;
				break;
			}
			if (arr[0][i] == prev) { // 이전이랑 같으면
				cnt++;
			}
			else { // 이전이랑 다르면
				q.push_back(cnt);
				q.push_back(prev);
				prev = arr[0][i];
				cnt = 1;
			}
		}

		if (cnt != -1) {
			q.push_back(cnt);
			q.push_back(prev);
		}
	}

	q.pop_front();
	q.pop_front();

	// 앞에서부터 채워넣기
	x = n / 2;
	y = n / 2;
	dir = 0;

	for (int len = 1; len < n; len++) {
		for (int i = 0; i < 2; i++) {
			for (int j = 0; j < len; j++) {
				x += torx[dir];
				y += tory[dir];
				if (!q.empty()) {
					arr[x][y] = q.front();
					q.pop_front();
				}
				else arr[x][y] = 0;
			}
			dir = (dir + 1) % 4;
		}
	}
	for (int i = n - 2; i >= 0; i--) {
		if (!q.empty()) {
			arr[0][i] = q.front();
			q.pop_front();
		}
		else arr[0][i] = 0;
	}

}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> arr[i][j];
		}
	}

	for (int i = 0; i < m; i++) {
		cin >> d >> s;
		// 1. d방향 s개 파괴 및 구슬 이동
		deployDS();

		// 2. 4개 이상 연속 구슬 파괴 (4개 이상이 없을때까지)
		deployOver4();

		// 3. 구슬 변화
		groupAB();

		bool flag = false;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (arr[i][j] != 0) {
					flag = true;
					break;
				}
			}
		}
		if (!flag) break;
	}

	int result = 0;
	for (int i = 1; i < 4; i++) result += i * answer[i];
	cout << result;

	return 0;
}
