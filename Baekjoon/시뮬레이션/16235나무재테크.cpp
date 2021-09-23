#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int n, m, k;
int dx[] = { 0,1,1,1,0,-1,-1,-1 };
int dy[] = { 1,1,0,-1,-1,-1,0,1 };
int A[10][10]; // 매해 추가되는 양분
int food[10][10];
vector<int> tree[10][10];

void springAndSummer() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (tree[i][j].size() == 0) continue;
			
			sort(tree[i][j].begin(), tree[i][j].end());
			vector<int> tmp;
			int dead = 0;
			
			for (int k = 0; k < tree[i][j].size(); k++) {
				int age = tree[i][j][k];
				if (age <= food[i][j]) { // 자신의 나이만큼 양분을 먹는다
					food[i][j] -= age;
					tmp.push_back(age + 1);
				}
				else {
					dead += age / 2;
				}
			}
			tree[i][j].clear();
			for (int k = 0; k < tmp.size(); k++) tree[i][j].push_back(tmp[k]);
			food[i][j] += dead;
		}
	}

}

void fallAndWinter() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			for (int k = 0; k < tree[i][j].size(); k++) {
				if (tree[i][j][k] % 5) continue;
				for (int d = 0; d < 8; d++) {
					int nx = i + dx[d];
					int ny = j + dy[d];
					if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
					tree[nx][ny].push_back(1);
				}
			}
			food[i][j] += A[i][j]; // 입력받은 양분 추가
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m >> k;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> A[i][j];
			food[i][j] = 5;
		}
	}

	for (int i = 0; i < m; i++) {
		int x, y, z;
		cin >> x >> y >> z;
		tree[x - 1][y - 1].push_back(z);
	}

	while (k--)
	{
		springAndSummer();
		fallAndWinter();
	}

	int answer = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			answer += tree[i][j].size();
		}
	}
	cout << answer << '\n';

	return 0;
}
