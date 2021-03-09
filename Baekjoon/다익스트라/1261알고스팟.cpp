#include<iostream>
#include<vector>
#include<queue>
#define INF 10000000

using namespace std;

int n, m;
int arr[100][100];
int dist[100][100];
int dx[] = { 1,0,-1,0 };
int dy[] = { 0,1,0,-1 };

void dijkstra() {
	priority_queue <pair< int, pair<int, int >>> pq;
	pq.push({ 0, {0,0} });

	while (!pq.empty())
	{
		int d = -pq.top().first;
		pair<int, int> cur = pq.top().second;
		pq.pop();

		if (d > dist[cur.first][cur.second]) continue;

		for (int i = 0; i < 4; i++) {
			int nx = cur.first + dx[i];
			int ny = cur.second + dy[i];

			if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
			// 0이면 안뿌셔 (dist)
			// 1이면 뿌셔 (dist + 1)
			if (dist[nx][ny] > d + arr[nx][ny]) {
				dist[nx][ny] = d + arr[nx][ny];
				pq.push({ -dist[nx][ny], {nx, ny} });
			}
		}
	}

}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> m >> n;
	for (int i = 0; i < n; i++) {
		string tmp;
		cin >> tmp;
		for (int j = 0; j < m; j++) {
			arr[i][j] = tmp[j] - '0';
			dist[i][j] = INF;
		}
	}
	
	dist[0][0] = 0;
	dijkstra();
	cout << dist[n - 1][m - 1];

	return 0;
}
