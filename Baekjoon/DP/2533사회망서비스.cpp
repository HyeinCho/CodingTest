#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int n, u, v;
vector<int> graph[1000001];
bool visited[1000001];
int dp[1000001][2];

// 단방향으로 진행하면서
// dp 업데이트
void dfs(int x) {
	visited[x] = true;
	dp[x][0] = 0;
	dp[x][1] = 1;
	for (int i = 0; i < graph[x].size(); i++) {
		int nx = graph[x][i];
		if (visited[nx]) continue;
		dfs(nx);
		dp[x][0] += dp[nx][1]; // x가 얼리가 아니라면, 자식은 얼리여야함.
		dp[x][1] += min(dp[nx][0], dp[nx][1]); // x가 얼리어답터면, 자식은 얼리든 말든 상관없음
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	for (int i = 0; i < n - 1; i++) {
		cin >> u >> v;
		graph[u].push_back(v);
		graph[v].push_back(u);
	}

	dfs(1);

	cout << min(dp[1][0], dp[1][1]);

	return 0;
}
