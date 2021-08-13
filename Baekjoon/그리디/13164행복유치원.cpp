#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int n, k;
long long answer;
int child[300000];
vector< pair<int, int>> dist;

bool cmp(pair<int, int>& a, pair<int, int>& b) {
	return a.first > b.first;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin >> n >> k;
	cin >> child[0];
	for (int i = 1; i < n; i++) {
		cin >> child[i];
		dist.push_back({ child[i] - child[i - 1], i });
	}
	sort(dist.begin(), dist.end(), cmp);
	for (int i = k - 1; i < n - 1; i++) answer += dist[i].first;

	cout << answer;

	return 0;
}
