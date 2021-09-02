#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int n;
int parent[1000];

int getParent(int x) {
	if (x == parent[x]) return x;
	return parent[x] = getParent(parent[x]);
}

void _union(int x, int y) {
	int px = getParent(x);
	int py = getParent(y);

	if (px > py) parent[px] = py;
	else parent[py] = px;
}

bool isCycle(int x, int y) {
	int px = getParent(x);
	int py = getParent(y);

	if (px == py) return true;
	else return false;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) parent[i] = i;
	
	int num;
	vector<pair<int, pair<int, int>>> edge;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> num;
			if (i < j) edge.push_back({ num, {i,j} });
		}
	}
	sort(edge.begin(), edge.end());

	long long answer = 0;
	for (int i = 0; i < edge.size(); i++) {
		int cost = edge[i].first;
		int x = edge[i].second.first;
		int y = edge[i].second.second;
		if (!isCycle(x, y)) {
			_union(x, y);
			answer += cost;
		}
	}

	cout << answer;
	return 0;
}
