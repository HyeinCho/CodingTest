#include<iostream>

using namespace std;

bool prime[1000001];

void isPrime() {
	for (int i = 2; i < 1000001; i++) {
		for (int j = 2; j * j <= i; j++) {
			if (i % j == 0) {
				prime[i] = true;
				break;
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n, num, answer;
	isPrime();
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> num;
		answer = 0;
		for (int i = 2; i <= num / 2; i++) {
			if (!prime[i] && !prime[num - i]) answer++;
		}
		cout << answer << '\n';
	}

	return 0;
}
