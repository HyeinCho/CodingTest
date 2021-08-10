#include<iostream>
#include<vector>

using namespace std;

int T, N, M, K, answer;
int house[200000];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> T; // 테스트케이스
	while (T--) {
		cin >> N >> M >> K; //집의 개수, 도둑이 훔칠 집 개수, 방범장치 울릴 금액
		answer = 0;
		for (int i = 0; i < N; i++) cin >> house[i];
		for (int i = 0; i < M; i++) house[i + N] = house[i];
		
		int sum = 0;
		for (int i = 0; i < M; i++) sum += house[i];
		if (sum < K) {
			answer++;
		}

		/*
		* n과 m이 같으면
		* 1
		  3 3 5
		  1 1 1

		  1-2-3
		  2-3-1
		  3-1-2
		  모두 같은 경우이므로
		  답은 1이어야함
		*/
		if (N != M) {
			for (int i = M; i < N + M - 1; i++) {
				sum += (house[i] - house[i - M]);
				if (sum < K) {
					answer++;
				}
			}
		}
		cout << answer << '\n';
	}


	return 0;
}
