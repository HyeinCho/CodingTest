#include<iostream>
#include<vector>

using namespace std;

int n;
int end_point = 0;
int answer = 0;
vector<vector<pair<int,int>>> v;
vector<bool> visited;

void dfs(int node, int sum) {
	if (node >= end_point && sum > 0) {
		if (answer < sum) answer = sum;
		return;
	}
	if (node == 1) {
		if (answer < sum) answer = sum;
	}

	for (int i = 0; i < v[node].size(); i++) {
		if (visited[v[node][i].first]) continue;
		visited[v[node][i].first] = true;
		dfs(v[node][i].first, sum + v[node][i].second);
		visited[v[node][i].first] = false;
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	v.resize(n + 1);
	visited.resize(n + 1);
	int a, b, c;
	for (int i = 0; i < n - 1; i++) {
		cin >> a >> b >> c;
		v[a].push_back({ b,c });
		v[b].push_back({ a,c });
		if (end_point < a) end_point = a;
	}
	
	end_point++;
	for (int i = end_point; i <= n; i++) {
		visited[i] = true;
		dfs(i, 0);
		visited[i] = false;
	}
	cout << answer;
	return 0;
}
