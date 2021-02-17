#include<iostream>
#include<vector>
#include<queue>

using namespace std;

int n;
int people[11]; // 인구수
bool info[11][11];
bool current[11]; // 선거구 A
int answer = 2147000000;

bool checkConnect(bool flag) {
	vector<int> tmp;
	vector<bool> visited(n + 1, false);
	for (int i = 1; i <= n; i++) {
		if (current[i] == flag) {
			tmp.push_back(i);
		}
	}
	int cnt = 1;

	queue<int> q;
	q.push(tmp[0]);
	visited[tmp[0]] = true;

	while (!q.empty()) {
		int x = q.front();
		q.pop();

		for (int i = 0; i < tmp.size(); i++) {
			if (info[x][tmp[i]] && !visited[tmp[i]]) {
				q.push(tmp[i]);
				visited[tmp[i]] = true;
				cnt++;
			}
		}
	}

	if (cnt == tmp.size()) return true;
	return false;
}

int diff() {
	int diff1 = 0;
	int diff2 = 0;
	for (int i = 1; i <= n; i++) {
		if (current[i]) diff1 += people[i];
		else diff2 += people[i];
	}
	return abs(diff1 - diff2);
}

void dfs(int idx, int cnt) {
	if (cnt > 0 && cnt < n && checkConnect(true) && checkConnect(false)) {
		int val = diff();
		if (answer > val) {
			answer = val;
		}
	}


	for (int i = idx; i <= n; i++) {
		current[i] = true;
		dfs(i + 1, cnt + 1);
		current[i] = false;
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> people[i];
	for (int i = 1; i <= n; i++) {
		int a;
		cin >> a;
		for (int j = 0; j < a; j++) {
			int b;
			cin >> b;
			info[i][b] = true;
		}
	}

	dfs(1, 0);
	if (answer == 2147000000) answer = -1;
	cout << answer;

	return 0;
}
