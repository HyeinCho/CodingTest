#include<iostream>
#include<string>
#include<algorithm>

using namespace std;

int num[] = { 0,0,1,7,4,2,0,8,10 };
long long dp[101];

void makeMin() {
	for (int i = 2; i <= 8; i++) {
		dp[i] = num[i];
	}
	dp[6] = 6; // 성냥이 6개 필요한 한 자리수는 0 이 아니라, 6

	for (int i = 9; i < 101; i++) {
		dp[i] = dp[i - 2] * 10 + num[2];
		for (int j = 3; j < 8; j++) {
			dp[i] = min(dp[i], dp[i - j] * 10 + num[j]);
		}
	}
}

string makeMax(int n) {
	string tmp = "1";
	if (n % 2) tmp = "7";
	
	for (int i = 0; i < n / 2 - 1; i++) {
		tmp += '1';
	}
	return tmp;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int T, n;
	cin >> T;
	int maxi = 0;
	int mini = 0;
	makeMin();
	for (int tc = 1; tc <= T; tc++) {
		cin >> n;
		// 최소값 구하기
		cout << dp[n] << ' ';

		// 최대값 구하기
		cout << makeMax(n) << '\n';

	}

	return 0;
}
