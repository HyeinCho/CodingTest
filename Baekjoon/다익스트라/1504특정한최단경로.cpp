#include<iostream>
#include<queue>
#include<vector>
#include<string.h>
#define MAX 2147000000

using namespace std;

int n, e, v, w;
int a, b, c;
vector<pair<int, int>> arr[801];
int dist[801];

int dijkstra(int start, int end) {
	if (start == end) return 0;

	for (int i = 1; i <= n; i++) dist[i] = MAX;
	priority_queue<pair<int, int>> pq;
	dist[start] = 0;
	pq.push({ 0, start });

	while (!pq.empty())
	{
		pair<int, int> tmp = pq.top();
		int cost = -tmp.first;
		int x = tmp.second;
		pq.pop();

		if (dist[x] < cost) continue;

		for (int i = 0; i < arr[x].size(); i++) {
			int ncost = arr[x][i].second + cost;
			int nx = arr[x][i].first;
			if (dist[nx] > ncost) {
				dist[nx] = ncost;
				pq.push({ -dist[nx], nx });
			}
		}
		
	}

	return dist[end];
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	long long answer = -1;
	cin >> n >> e;
	for (int i = 0; i < e; i++) {
		cin >> a >> b >> c;
		arr[a].push_back({ b, c });
		arr[b].push_back({ a, c });
	}
	cin >> v >> w;
	// 1 -> v -> w -> n
	a = dijkstra(1, v);
	b = dijkstra(v, w);
	c = dijkstra(w, n);
	if (a != MAX && b != MAX && c != MAX) {
		answer = (long long)a + (long long)b + (long long)c;
	}

	// 1 -> w -> v -> n
	a = dijkstra(1, w);
	b = dijkstra(w, v);
	c = dijkstra(v, n);
	if (a != MAX && b != MAX && c != MAX) {
		long long sum = (long long)a + (long long)b + (long long)c;
		if (answer == -1 || answer > sum) answer = sum;
	}

	cout << answer;

	return 0;
}
