#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int T, n;
	cin >> T;
	while (T--) {
		cin >> n;
		vector<vector<int>> v(2, vector<int>(n));
		for (int i = 0; i < 2; i++) {
			for (int j = 0; j < n; j++) cin >> v[i][j];
		}

		vector<vector<int>> dp(2, vector<int>(n, 0));
		dp[0][0] = v[0][0];
		dp[1][0] = v[1][0];
		dp[0][1] = dp[1][0] + v[0][1];
		dp[1][1] = dp[0][0] + v[1][1];
		for (int j = 2; j < n; j++) {
			for (int i = 0; i < 2; i++) {
				dp[i][j] = v[i][j] + max(dp[(i + 1) % 2][j - 2], dp[(i + 1) % 2][j - 1]);
			}
		}
		
		cout << max(dp[0][n - 1], dp[1][n - 1]) << '\n';
	}

	return 0;
}
