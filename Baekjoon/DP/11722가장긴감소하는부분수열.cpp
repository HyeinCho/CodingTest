#include<iostream>
#include<vector>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int N;
	cin >> N;
	vector<int> A(N);
	vector<int> dp(N);
	for (int i = 0; i < N; i++) cin >> A[i];

	for (int i = 0; i < N; i++) {
		dp[i] = 1; // 본인만 수열인 경우
		for (int j = 0; j < i; j++) {
			// 이전(j)보다 숫자가 작아야함 (감소하기 때문에)
			// 이전 dp + 1이 현재 dp보다 더 큰 경우만 업데이트 진행
			if (A[i] < A[j] && dp[i] < dp[j] + 1) {
				dp[i] = dp[j] + 1;
			}
		}
	}

	int answer = 0;
	for (int i = 0; i < N; i++) {
		if (answer < dp[i]) answer = dp[i];
	}
	cout << answer;

	return 0;
}
