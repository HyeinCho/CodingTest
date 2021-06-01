#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int n, h;
int answer;
int answer_cnt = 0;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> h;
	answer = n + 1;

	vector<int> bottom(n / 2), up(n / 2);
	for (int i = 0; i < n / 2; i++) {
		cin >> bottom[i] >> up[i];
	}
	sort(bottom.begin(), bottom.end());
	sort(up.begin(), up.end());

	for (int i = 1; i <= h; i++) {
		// i값 이상인 수의 가장 첫 번째 원소의 위치
		int cnt = n / 2 - (lower_bound(bottom.begin(), bottom.end(), i) - bottom.begin());
		
		// h-i를 초과하는 가장 첫 번째 원소의 위치
		cnt += n / 2 - (upper_bound(up.begin(), up.end(), h - i) - up.begin());
		if (answer > cnt) {
			answer = cnt;
			answer_cnt = 1;
		}
		else if (answer == cnt) {
			answer_cnt++;
		}
	}

	cout << answer << ' ' << answer_cnt;

	return 0;
}
