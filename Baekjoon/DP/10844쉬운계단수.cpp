#include<iostream>

using namespace std;

long long dp[101][10];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin >> n;

	for (int i = 1; i < 10; i++) dp[1][i] = 1;
	for (int i = 2; i <= n; i++) {
		
		dp[i][0] = dp[i - 1][1];
		dp[i][9] = dp[i - 1][8];
		for (int j = 1; j < 9; j++) {
			dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j + 1]) % 1000000000;
		}
	}

	long long answer = 0;
	for (int i = 0; i < 10; i++) {
		answer += dp[n][i];
	}

	cout << answer % 1000000000;

	return 0;
}
