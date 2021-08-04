#include<iostream>

using namespace std;

long long dp[11][2001];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	for (int j = 1; j <= 2000; j++) dp[1][j] = j;

	/*
	dp[i][j] : i번째 수를 고를 때, 1 ~ j 중 선택하는 경우의 수
	*/
	for (int i = 2; i <= 10; i++) {
		for (int j = 1; j <= 2000; j++) {
			// dp[i - 1][j / 2]: i-1에서 절반한거에 본인을 선택하는 경우
			// dp[i][j - 1] : 바로 이전 경우의 수를 그대로 이용하는 경우
			dp[i][j] = dp[i - 1][j / 2] + dp[i][j - 1];
		}
	}

	int n, m, T;
	cin >> T;
	while (T--) {
		cin >> n >> m;
		cout << dp[n][m] << '\n';
	}

	return 0;
}
