#include<iostream>
#include<algorithm>

using namespace std;

string s1, s2;
int dp[1001][1001];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> s1 >> s2;

	int n = s1.size();
	int m = s2.size();
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (s1[i] == s2[j]) {
				dp[i + 1][j + 1] = dp[i][j] + 1;
			}
			else {
				dp[i + 1][j + 1] = max(dp[i + 1][j], dp[i][j + 1]);
			}
		}
	}
	cout << dp[n][m];

	return 0;
}
