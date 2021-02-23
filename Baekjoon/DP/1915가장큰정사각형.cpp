#include<iostream>
#include<algorithm>

using namespace std;

int n, m;
int dp[1001][1001];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		string s;
		cin >> s;
		for (int j = 1; j <= m; j++) {
			dp[i][j] = s[j - 1] - '0';
		}
	}

	int answer = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (dp[i][j] != 0) {
				dp[i][j] = min(dp[i][j - 1], min(dp[i - 1][j - 1], dp[i - 1][j])) + 1;
				if (answer < dp[i][j]) answer = dp[i][j];
			}
		}
	}
	cout << answer * answer;

	return 0;
}
