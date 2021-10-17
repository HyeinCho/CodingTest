#include<iostream>
#include<deque>

using namespace std;

int n, k, a;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> k;
	deque<pair<bool, int>> dq; // 로봇 유무, 내구도
	for (int i = 0; i < 2 * n; i++) {
		cin >> a;
		dq.push_back({ false, a });
	}

	int cnt = 0;
	int time = 0;
	while (cnt < k) {
		// 1. 벨트, 로봇 회전
		int x = dq.back().second;
		dq.pop_back();
		dq.push_front({ false, x });
		dq.at(n - 1).first = false;

		// 2. 로봇들 시계방향 한 칸 이동
		for (int i = n - 2; i >= 0; i--) {
			if (dq.at(i).first && !dq.at(i+1).first && dq.at(i+1).second >= 1) {
				dq.at(i).first = false;
				dq.at(i + 1).first = true;
				dq.at(i + 1).second--;
				if (dq.at(i + 1).second == 0) cnt++;
			}
		}
		dq.at(n - 1).first = false; // 내리는 위치에서 로봇 내리기

		// 3. 로봇 올리는 위치에 올리기
		if (!dq.front().first && dq.front().second >= 1) {
			dq.front().first = true;
			dq.front().second--;
			if (dq.front().second == 0) cnt++;
		}

		time++;
	}

	cout << time;

	return 0;
}
