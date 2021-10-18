#include<iostream>
#include<vector>
#include<map>

using namespace std;

int answer;
int n, m, k, a;
int dx[] = { 0, -1, 1, 0, 0 };
int dy[] = { 0, 0, 0, -1, 1 };
vector< pair<int, int>> arr[20]; // 향수, 누가 뿌렸는지

struct Shark {
	bool dead;
	int number;
	int x;
	int y;
	int dir;
	vector<int> priority[5];

	Shark() {}
	//shark(int number, int x, int y) : dead(false), number(number), x(x), y(y), dir(0) { };
	Shark(int number, int x, int y) {
		this->dead = false;
		this->number = number;
		this->x = x;
		this->y = y;
	}
};

vector<Shark> sharks;

void moveShark() {
	map<pair<int, int>, int> tmp;
	for (int i = 1; i <= m; i++) {
		if (sharks[i].dead) continue;
		bool flag = false;
		int d = sharks[i].dir;
		for (int j = 0; j < 4; j++) {
			int nd = sharks[i].priority[d][j];
			int nx = sharks[i].x + dx[nd];
			int ny = sharks[i].y + dy[nd];
			if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
			if (arr[nx][ny].first > 0) continue;
			flag = true;
			if (tmp.find({ nx, ny }) == tmp.end()) tmp[{nx, ny}] = i;
			else {
				sharks[i].dead = true;
			}
			sharks[i].dir = nd;
			sharks[i].x = nx;
			sharks[i].y = ny;
			break;
		}
		if (!flag) { // 주변에 빈 칸이 없다 -> 내가 뿌린 냄새로 간다
			for (int j = 0; j < 4; j++) {
				int nd = sharks[i].priority[d][j];
				int nx = sharks[i].x + dx[nd];
				int ny = sharks[i].y + dy[nd];
				if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
				if (arr[nx][ny].second != i) continue;
				if (tmp.find({ nx, ny }) == tmp.end()) tmp[{nx, ny}] = i;
				else {
					/*if (tmp[{nx, ny}] > i) {
						sharks[tmp[{nx, ny}]].dead = true;
						tmp[{nx, ny}] = i;
					}
					else {
						sharks[i].dead = true;
					}*/
					sharks[i].dead = true;
				}
				sharks[i].dir = nd;
				sharks[i].x = nx;
				sharks[i].y = ny;
				break;
			}
		}

	}

	// 전체적으로 -1
	for (int k = 0; k < n; k++) {
		for (int j = 0; j < n; j++) {
			if (arr[k][j].first > 0) arr[k][j].first--;
			else if (arr[k][j].first == 0) arr[k][j].second = 0;
		}
	}

	for (auto iter = tmp.begin(); iter != tmp.end(); iter++) {
		arr[iter->first.first][iter->first.second] = { k, iter->second };
	}

}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m >> k;
	sharks.resize(m + 1);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> a; // 상어 번호
			if (a != 0) {
				/*arr[i][j].first = k;
				arr[i][j].second = a;*/
				arr[i].push_back({ k, a });
				Shark s(a, i, j);
				sharks[a] = s;
			}
			else {
				/*arr[i][j].first = 0;
				arr[i][j].second = 0;*/
				arr[i].push_back({ 0, 0 });
			}
		}
	}

	for (int i = 1; i <= m; i++) {
		cin >> a;
		sharks[i].dir = a;
	}

	for (int i = 1; i <= m; i++) {
		for (int j = 1; j <= 4; j++) {
			for (int k = 1; k <= 4; k++) {
				cin >> a;
				sharks[i].priority[j].push_back(a);
			}
		}
	}

	int time = 0;
	while (time++ < 1000) {
		moveShark();
		bool flag = false;
		for (int i = 2; i <= m; i++) {
			if (!sharks[i].dead) {
				flag = true;
				break;
			}
		}
		if (!flag) break;
	}

	if (time == 1001) cout << -1;
	else cout << time;
	return 0;
}
