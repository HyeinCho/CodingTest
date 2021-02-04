#include<iostream>
#include<vector>
#define MAX 51

using namespace std;

struct fireball{
	int x;
	int y;
	int m;
	int s;
	int d;

	fireball(int x, int y, int m, int s, int d) {
		this->x = x;
		this->y = y;
		this->m = m;
		this->s = s;
		this->d = d;
	}
};

int n, m, k;

int dx[] = { -1,-1,0,1,1,1,0,-1 };
int dy[] = { 0,1,1,1,0,-1,-1,-1 };

vector<fireball> fb;
vector<fireball> board[MAX][MAX];

void move() {
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			board[i][j].clear();
		}
	}

	for (fireball shark : fb) {
		int next_d = shark.s % n;
		int nx = shark.x + next_d * dx[shark.d];
		int ny = shark.y + next_d * dy[shark.d];
		if (nx > n) nx -= n;
		if (ny > n) ny -= n;
		if (nx < 1) nx += n;
		if (ny < 1) ny += n;
		shark.x = nx;
		shark.y = ny;
		board[nx][ny].push_back(fireball(nx, ny, shark.m, shark.s, shark.d));
	}
}

void divideFire() {
	vector<fireball> tmp;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (board[i][j].empty()) continue;
			if (board[i][j].size() == 1) {
				tmp.push_back({ board[i][j][0] });
				continue;
			}
			int sum_m = 0;
			int sum_s = 0;
			int flag = 0;
			for (int k = 0; k < board[i][j].size(); k++) {
				sum_m += board[i][j][k].m;
				sum_s += board[i][j][k].s;
				if (board[i][j][k].d % 2) flag++;
			}
			sum_m /= 5;
			sum_s /= board[i][j].size();
			if (sum_m == 0) continue;

			if (flag == 0 || flag == board[i][j].size()) { // 0,2,4,6
				for (int k = 0; k < 8; k += 2) {
					tmp.push_back({ i,j,sum_m, sum_s, k });
				}
			}
			else {
				for (int k = 1; k < 8; k += 2) {
					tmp.push_back({ i,j,sum_m, sum_s, k });
				}
			}
		}
	}
	fb = tmp;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m >> k;
	for (int i = 0; i < m; i++) {
		int r, c, m, s, d;
		cin >> r >> c >> m >> s >> d;
		fb.push_back(fireball(r, c, m, s, d));
		board[r][c].push_back(fireball(r, c, m, s, d));
	}

	while (k--) {
		move();
		divideFire();
	}

	int answer = 0;
	for (int i = 0; i < fb.size(); i++) answer += fb[i].m;
	cout << answer;

	return 0;
}
