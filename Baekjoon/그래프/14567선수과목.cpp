#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int n, m;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;
	vector<int> answer(n + 1, 1);
	vector<vector<int>> tmp(m, vector<int>(2));
	for (int i = 0; i < m; i++) {
		cin >> tmp[i][0] >> tmp[i][1];
	}
	sort(tmp.begin(), tmp.end());
	for (int i = 0; i < m; i++) {
		if (answer[tmp[i][0]] + 1 > answer[tmp[i][1]]) {
			answer[tmp[i][1]] = answer[tmp[i][0]] + 1;
		}
	}

	for (int i = 1; i <= n; i++) cout << answer[i] << ' ';

	return 0;
}
