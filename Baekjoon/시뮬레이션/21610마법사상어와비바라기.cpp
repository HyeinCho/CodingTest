#include<iostream>
#include<vector>

using namespace std;

int n, m, d, s;
int dx[] = { 0, 0,-1,-1,-1,0,1,1,1 };
int dy[] = { 0, -1,-1,0,1,1,1,0,-1 };
int a[50][50];
vector<pair<int, int>> cloud;

void moveCloud() {
	for (int i = 0; i < cloud.size(); i++) {
		int x = cloud[i].first;
		int y = cloud[i].second;
		x = (x + dx[d] * s) % n;
		y = (y + dy[d] * s) % n;
		if (x < 0) x += n;
		if (y < 0) y += n;
		cloud[i] = { x, y };
	}
}

void raining() {
	for (int i = 0; i < cloud.size(); i++) {
		a[cloud[i].first][cloud[i].second]++;
	}
}

void waterCopyMagic() {
	for (int i = 0; i < cloud.size(); i++) {
		int x = cloud[i].first;
		int y = cloud[i].second;
		for (int j = 1; j <= 4; j++) { // 2,4,6,8
			int nx = x + dx[j * 2];
			int ny = y + dy[j * 2];
			if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
			if (a[nx][ny] > 0) a[x][y]++;
		}
	}
}

void makeCloud() {
	vector<vector<bool>> visited(n, vector<bool>(n, false));
	for (int i = 0; i < cloud.size(); i++) {
		visited[cloud[i].first][cloud[i].second] = true;
	}

	cloud.clear();
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (a[i][j] >= 2 && !visited[i][j]) {
				cloud.push_back({ i, j });
				a[i][j] -= 2;
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> a[i][j];
		}
	}

	cloud.push_back({ n - 2, 0 });
	cloud.push_back({ n - 2, 1 });
	cloud.push_back({ n - 1, 0 });
	cloud.push_back({ n - 1, 1 });

	for (int i = 0; i < m; i++) {
		cin >> d >> s;
		// 1. 구름 이동
		moveCloud();

		// 2. 구름에서 비가 내려 물의 양 1 증가
		raining();

		// 3. 구름 사라짐

		// 4. 2에서 증가한 칸에 물복사버그 마법. 
		//	  대각선 방향으로 거리가 1인 칸에 물이 있는 바구니 수만큼 물의 양 증가
		waterCopyMagic();

		// 5. 물의 양이 2 이상인 모든 칸에 구름 생김 & 물의 양 2 줄어듬
		//	  이 때, 3에서 사라진 위치가 아니어야함
		makeCloud();
	}

	int answer = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			answer += a[i][j];
		}
	}

	cout << answer;

	return 0;
}
