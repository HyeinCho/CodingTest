#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int n, m;
int parent[100001];

int getParent(int x) {
	if (parent[x] == x) return x;
	return getParent(parent[x]);
}

void _union(int x, int y) {
	int px = getParent(x);
	int py = getParent(y);

	if (px < py) parent[py] = px;
	else parent[px] = py;
}

bool isSame(int x, int y) {
	int px = getParent(x);
	int py = getParent(y);

	if (px == py) return true;
	else return false;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;
	vector<pair<int, pair<int, int>>> v;
	long long answer = 0;
	for (int i = 0; i < m; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		v.push_back({ c, {a, b} });
		answer += c;
	}
	sort(v.begin(), v.end());
	for (int i = 1; i <= n; i++) parent[i] = i;

	int cnt = 0;
	for (int i = 0; i < m; i++) {
		if (!isSame(v[i].second.first, v[i].second.second)) {
			_union(v[i].second.first, v[i].second.second);
			answer -= v[i].first;
			cnt++;
		}
	}
	if (cnt != n - 1) answer = -1;
	cout << answer;
	return 0;
}
