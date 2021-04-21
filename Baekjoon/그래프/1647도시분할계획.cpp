#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int n, m;
vector<vector<int>> home;
bool visited[100001];
int parent[100001];

int getParent(int x) {
	if (parent[x] == x) return x;
	return parent[x] = getParent(parent[x]);
}

void unionParent(int x, int y) {
	int parent_x = getParent(x);
	int parent_y = getParent(y);

	if (parent_x < parent_y) parent[parent_y] = parent_x;
	else parent[parent_x] = parent_y;
}

bool sameParent(int x, int y) {
	int parent_x = getParent(x);
	int parent_y = getParent(y);

	if (parent_x == parent_y) return true;
	return false;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int answer = 0;
	cin >> n >> m;	

	for (int i = 0; i < m; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		home.push_back({ c,a,b });
	}
	sort(home.begin(), home.end());
	
	for (int i = 1; i <= n; i++) parent[i] = i;

	// 아이디어
	// 최대 가중치로 연결되어 있는 집 하나만 분리하면 됨!
	// n - 1개의 집만 연결되어 있으면 되니까, 간선의 갯수는 n - 2개
	// 구현 방법: 크루스칼 알고리즘
	int num = n - 2; 
	for (vector<int> h : home) {
		int cost = h[0], x = h[1], y = h[2];
		if (!sameParent(x, y)) {
			unionParent(x, y);
			answer += cost;
			num--;
			if (num == 0) break;
		}
	}

	cout << answer;

	return 0;
}
