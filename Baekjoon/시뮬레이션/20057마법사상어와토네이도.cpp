#include<iostream>
#include<algorithm>

using namespace std;

int n;
int answer = 0;
int arr[500][500];
bool visited[500][500];
int dx[] = { 0, 1, 0, -1 };
int dy[] = { -1,0,1,0 };
int rate[] = { 1, 7, 2, 10 };

void calc_verti(int x, int y, int sand, int dir_reverse, int num) {
	for (int i = dir_reverse; i < 4; i += 2) {
		int nx = x + num * dx[i];
		int ny = y + num * dy[i];
		if (nx < 0 || nx >= n || ny < 0 || ny >= n) {
			answer += sand;
		}
		else {
			arr[nx][ny] += sand;
		}
	}
}

void calc_hori(int x, int y, int sand, int dir) {

	if (x < 0 || x >= n || y < 0 || y >= n) {
		answer += sand;
	}
	else {
		arr[x][y] += sand;
	}
}

void move(int x, int y, int dir) {
	if (x == 0 && y == 0) return;

	int nx = x + dx[dir];
	int ny = y + dy[dir];
	if (nx < 0 || nx >= n || ny < 0 || ny >= n) {
		dir = dir + 1 ? dir < 3 : 0;
		nx = x + dx[dir];
		ny = y + dy[dir];
	}
	visited[nx][ny] = true;
	int cost = arr[nx][ny];
	int tmp = 0;
	int sand = 0;
	for (int i = 0; i < 4; i++) {
		sand = cost * rate[i] / 100;
		if (i == 0) {
			calc_verti(x, y, sand, (dir + 1) % 2, 1);
		}
		else if (i == 1) {
			calc_verti(x + dx[dir], y + dy[dir], sand, (dir + 1) % 2, 1);
		}
		else if (i == 2) {
			calc_verti(x + dx[dir], y + dy[dir], sand, (dir + 1) % 2, 2);
		}
		else if (i == 3) {
			calc_verti(x + 2 * dx[dir], y + 2 * dy[dir], sand, (dir + 1) % 2, 1);
		}

		tmp += (2 * sand);

	}

	sand = cost * 0.05;
	tmp += sand;
	calc_hori(x + 3 * dx[dir], y + 3 * dy[dir], sand, dir);
	
	calc_hori(x + 2 * dx[dir], y + 2 * dy[dir], cost - tmp, dir);
	arr[nx][ny] = 0;

	if (!visited[nx + dx[(dir + 1) % 4]][ny + dy[(dir + 1) % 4]]) dir = (dir + 1) % 4;

	move(nx, ny, dir);

}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> arr[i][j];
		}
	}

	visited[n / 2][n / 2] = true;
	move(n / 2, n / 2, 0);
	cout << answer;

	return 0;
}
