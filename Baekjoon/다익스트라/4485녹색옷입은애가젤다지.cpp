#include<iostream>
#include<queue>
#include<string.h>

using namespace std;

int n;
int dx[] = { 1, 0, -1, 0 };
int dy[] = { 0, 1, 0, -1 };
int cave[125][125];

int dijkstra() {
	priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
	pq.push({ cave[0][0], {0,0} });
	vector<vector<int>> dist(n, vector<int>(n, 9 * n * n + 1));

	dist[0][0] = cave[0][0];

	while (!pq.empty()) {
		pair<int, pair<int, int>> tmp = pq.top();
		pq.pop();

		if (tmp.first > dist[tmp.second.first][tmp.second.second]) continue;
		
		for (int i = 0; i < 4; i++) {
			int nx = tmp.second.first + dx[i];
			int ny = tmp.second.second + dy[i];

			if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
			
			int ncost = tmp.first + cave[nx][ny];
			if (ncost < dist[nx][ny]) {
				dist[nx][ny] = ncost;
				pq.push({ ncost, {nx, ny} });
			}

		}
	}

	return dist[n - 1][n - 1];
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int tc = 1;
	while (true)
	{
		cin >> n;
		if (n == 0) break;

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				cin >> cave[i][j];
			}
		}

		cout << "Problem " << tc++ << ": " << dijkstra() << '\n';

	}

	return 0;
}
