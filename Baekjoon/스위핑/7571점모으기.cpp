#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int n, m;
vector<int> x, y;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;
	x.resize(m);
	y.resize(m);
	for (int i = 0; i < m; i++) {
		cin >> x[i] >> y[i];
	}
	sort(x.begin(), x.end());
	sort(y.begin(), y.end());

	int dx = x[m / 2];
	int dy = y[m / 2];
	int answer = 0;
	for (int i = 0; i < m; i++) {
		answer += abs(x[i] - dx) + abs(y[i] - dy);
	}
	cout << answer;
	return 0;
}
