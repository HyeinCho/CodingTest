#include<iostream>
#include<queue>
#include<string.h>

using namespace std;

int n, m;
int map[1000][1000];
int visited[1000][1000];
int dx[] = { 1,0,-1,0 };
int dy[] = { 0,1,0,-1 };

void bfs(int x, int y) {
	queue<pair<int, int>> q;
	q.push({ x, y });
	visited[x][y] = 0;

	while (!q.empty())
	{
		x = q.front().first;
		y = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
			if (visited[nx][ny] == -1) {
				visited[nx][ny] = visited[x][y] + 1;
				q.push({ nx, ny });
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;
	int x, y;

	memset(visited, -1, sizeof(visited));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> map[i][j];
			if (map[i][j] == 2) {
				x = i;
				y = j;
			}
			else if (map[i][j] == 0) {
				visited[i][j] = 0;
			}
		}
	}

	bfs(x, y);

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cout << visited[i][j] << ' ';
		}
		cout << '\n';
	}

	return 0;
}
