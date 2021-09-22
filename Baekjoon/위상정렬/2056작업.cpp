#include<iostream>
#include<vector>
#include<queue>

using namespace std;

int n, a, b;
int work[10001];
int degree[10001];
int dp[10001];
vector<vector<int>> graph(10001);

int topologySort() {
	int answer = 0;
	queue<int> q;
	vector<int> result;
	
	for (int i = 1; i <= n; i++) {
		if (degree[i] == 0) {
			q.push(i);
			dp[i] = work[i];
		}
	}

	while (!q.empty()) {
		int x = q.front();
		q.pop();

		for (int i = 0; i < graph[x].size(); i++) {
			int nx = graph[x][i];
			degree[nx]--;
			if (dp[nx] < dp[x] + work[nx]) {
				dp[nx] = dp[x] + work[nx];
			}
			if (degree[nx] == 0) {
				q.push(nx);
			}
		}
	}

	for (int i = 1; i <= n; i++) {
		if (answer < dp[i]) answer = dp[i];
	}
	return answer;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> work[i] >> a;
		while (a--) {
			cin >> b;
			graph[b].push_back(i);
			degree[i]++;
		}
	}

	cout << topologySort();

	return 0;
}
