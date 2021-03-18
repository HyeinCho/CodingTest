#include<iostream>
#include<queue>
#include<string.h>
#define MAX 100001

using namespace std;

int n, k;
bool dist[MAX];

int dijkstra() {
	priority_queue < pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
	q.push({ 0, n });
	dist[n] = true;

	while (!q.empty())
	{
		int cost = q.top().first;
		int dir = q.top().second;
		q.pop();

		if (dir == k) return cost;

		if (dir * 2 < MAX) {
			if (!dist[dir * 2]) {
				dist[dir * 2] = true;
				q.push({ cost, dir * 2 });
			}
		}
		if (dir + 1 < MAX) {
			if (!dist[dir + 1]) {
				dist[dir + 1] = true;
				q.push({ (cost + 1), dir + 1 });
			}
		}
		if (dir > 0) {
			if (!dist[dir - 1]) {
				dist[dir - 1] = true;
				q.push({ (cost + 1), dir - 1 });
			}
		}

	}
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> n >> k;
	cout << dijkstra();

	return 0;
}
