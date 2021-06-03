#include<iostream>
#include<vector>
#include<math.h>
#include<algorithm>

using namespace std;

int n, m;
vector<pair<double, pair<int, int>>> v;
vector<int> parent;

double dist(pair<long long, long long> a, pair<long long, long long> b) {
	return sqrt((a.first - b.first) * (a.first - b.first) + (a.second - b.second) * (a.second - b.second));
}

int find(int x) {
	if (parent[x] == x) return x;
	return parent[x] = find(parent[x]);
}

void _union(int x, int y) {
	int p_x = find(x);
	int p_y = find(y);

	if (p_x > p_y) parent[p_x] = p_y;
	else parent[p_y] = p_x;
}

bool isCycle(int x, int y) {
	int p_x = find(x);
	int p_y = find(y);

	if (p_x == p_y) return true;
	else return false;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;
	vector<pair<int, int>> tmp(n);
	for (int i = 0; i < n; i++) {
		cin >> tmp[i].first >> tmp[i].second;
	}

	parent.resize(n + 1);
	for (int i = 1; i <= n; i++) parent[i] = i;

	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		if (!isCycle(a, b)) {
			_union(a, b);
		}
	}

	// 모든 간선간의 거리
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			double d = dist(tmp[i], tmp[j]);
			v.push_back({ d, {i + 1, j + 1} });
		}
	}

	sort(v.begin(), v.end());

	double answer = 0;
	for (int i = 0; i < v.size(); i++) {
		if (!isCycle(v[i].second.first, v[i].second.second)) {
			answer += v[i].first;
			_union(v[i].second.first, v[i].second.second);
		}
	}
	cout << fixed;
	cout.precision(2);
	cout << answer;

	return 0;
}
