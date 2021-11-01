#include<iostream>
#include<queue>
#include<string.h>

using namespace std;

int n, m;
int dx[] = { 1,0,-1,0 };
int dy[] = { 0,1,0,-1 };
int visited[3000][3000];
int arr[3000][3000];

void bfs(int x, int y) {
	queue<pair<int, int>> q;
	q.push({ x, y });
	visited[x][y] = 0;

	bool flag = false;
	while (!q.empty())
	{
		x = q.front().first;
		y = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
			if (arr[nx][ny] == 1 || visited[nx][ny] != -1) continue;
			visited[nx][ny] = visited[x][y] + 1;
			q.push({ nx, ny });
			if (arr[nx][ny] > 2) {
				cout << "TAK" << '\n';
				cout << visited[nx][ny] << '\n';
				return;
			}
		}
	}
	cout << "NIE" << '\n';
	return;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;

	int x, y;
	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		for (int j = 0; j < m; j++) {
			arr[i][j] = s[j] - '0';
			if (arr[i][j] == 2) {
				x = i;
				y = j;
				arr[i][j] = 0;
			}
			visited[i][j] = -1;
		}
	}
	
	bfs(x, y);
	return 0;
}
