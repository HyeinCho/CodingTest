#include<iostream>
#include<vector>

using namespace std;

int n, r;
int answer = 0;
vector<pair<int, int>> graph[200001];
bool visited[200001];

pair<int, int> getPillar(int x, int sum) {
	visited[x] = true;
	if (graph[x].size() > 2) return { x, sum };
	if (graph[r].size() == 2) return { x, sum };
	
	for (int i = 0; i < graph[x].size(); i++) {
		int nx = graph[x][i].first;
		if (visited[nx]) continue;
		return getPillar(nx, sum + graph[x][i].second);
	}
	return { x, sum };
}

void getBranch(int x, int sum) {
	if (graph[x].size() == 1) {
		if (answer < sum) answer = sum;
		return;
	}

	for (int i = 0; i < graph[x].size(); i++) {
		int nx = graph[x][i].first;
		if (visited[nx]) continue;
		visited[nx] = true;
		getBranch(nx, sum + graph[x][i].second);
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	
	cin >> n >> r;
	for (int i = 0; i < n - 1; i++) {
		int a, b, d;
		cin >> a >> b >> d;
		graph[a].push_back({ b,d });
		graph[b].push_back({ a,d });
	}

	pair<int, int> tmp = getPillar(r, 0);
	getBranch(tmp.first, 0);
	cout << tmp.second << ' ' << answer;

	return 0;
}
