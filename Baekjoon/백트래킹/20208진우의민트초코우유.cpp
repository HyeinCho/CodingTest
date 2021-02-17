#include<iostream>
#include<vector>

using namespace std;

int n, m, h;
int home_x, home_y;
vector<pair<int, int>> mint;
bool visited[10][10];
int answer = 0;

int dist(int x1, int y1, int x2, int y2) {
	int x = abs(x1 - x2);
	int y = abs(y1 - y2);
	return x + y;
}

void find(int x, int y, int cnt, int drink) {
	if (x == home_x && y == home_y && visited[x][y]) {
		if (answer < drink - 1) answer = drink - 1;
		return;
	}
	
	for (int i = 0; i < mint.size(); i++) {
		int nx = mint[i].first;
		int ny = mint[i].second;
		if (visited[nx][ny]) continue;
		int d = dist(x, y, nx, ny);
		if (d > cnt) continue;
		visited[nx][ny] = true;
		find(nx, ny, cnt - d + h, drink + 1);
		visited[nx][ny] = false;
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m >> h;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			int a;
			cin >> a;
			if (a == 1) {
				home_x = i;
				home_y = j;
				mint.push_back({ i,j });
			}
			else if (a == 2) {
				mint.push_back({ i,j });
			}
		}
	}

	find(home_x, home_y, m, 0);
	cout << answer;

	return 0;
}
