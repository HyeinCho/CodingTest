#include<iostream>

using namespace std;

int n;

bool isPrime(int num) {
	if (num == 0 || num == 1) return false;
	for (int j = 2; j * j <= num; j++) {
		if (num % j == 0) {
			return false;
		}
	}
	return true;
};

void dfs(int num, int cnt) {
	if (cnt == n) {
		cout << num << '\n';
		return;
	}

	for (int i = 0; i < 10; i++) {
		int tmp = num * 10 + i;
		if (isPrime(tmp)) {
			dfs(tmp, cnt + 1);
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	dfs(0, 0);

	return 0;
}
