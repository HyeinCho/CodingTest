#include<iostream>
#include<queue>
#include<vector>

using namespace std;

int n, t, s;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	
	priority_queue<pair<int, int>> pq;
	while (n--) {
		cin >> t >> s;
		pq.push({ s, t });
	}

	int time = pq.top().first;
	while (!pq.empty() && time >= 0) {
		pair<int, int> cur = pq.top();
		pq.pop();
		if (cur.first >= time) {
			time -= cur.second;
		}
		else {
			time = cur.first - cur.second;
		}
	}

	if (time < 0) cout << -1;
	else cout << time;

	return 0;
}
