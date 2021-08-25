#include<iostream>
#include<vector>

using namespace std;

int n, m; // 아이들 수, 놀이기구 수
int play[10000];

long long search(long long mid) { // mid라는 시간 동안 총 몇명이 탈 수 있는지
	long long sum = m;
	for (int i = 0; i < m; i++) {
		sum += mid / play[i];
	}
	return sum;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		cin >> play[i];
	}
	if (n <= m) cout << n;
	else {
		long long s = 0;
		long long e = (long long)n * 30;
		long long mid = 0;
		long long sum = 0; // 몇 명이 탈 수 있나
		while (s <= e) {
			mid = (s + e) / 2;

			sum = search(mid);
			if (search(mid + 1) >= n && sum < n) {
				break;
			}
			else if (sum < n) {
				s = mid + 1;
			}
			else {
				e = mid - 1;
			}
		}

		int i;
		for (i = 0; i < m; i++) {
			if ((mid + 1) % play[i] == 0) {
				sum++;
			}
			if (sum >= n) break;
		}
		cout << i + 1;
	}
	return 0;
}
