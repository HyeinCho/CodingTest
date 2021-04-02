#include<iostream>
#include<vector>
#include<queue>
#define MAX 1000000

using namespace std;

int f, s, g, u, d;
vector<int> dist(MAX + 1, MAX + 1);

int dijstra() {
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>> > pq;
	pq.push({ 0, s });
	dist[s] = 0;

	while (!pq.empty()) {
		int cost = pq.top().first;
		int x = pq.top().second;
		pq.pop();

		if (x == g) return cost;

		if (dist[x] < cost) continue;

		if (x + u <= f && dist[x + u] > cost + 1) {
			dist[x + u] = cost + 1;
			pq.push({ cost + 1, x + u });
		}
		if (x > d && dist[x - d] > cost + 1) {
			dist[x - d] = cost + 1;
			pq.push({ cost + 1, x - d });
		}

	}
	return -1;

}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> f >> s >> g >> u >> d;
	
	int answer = dijstra();
	if (answer == -1) cout << "use the stairs";
	else cout << answer;


	return 0;
}
