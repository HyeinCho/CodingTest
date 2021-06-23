#include<iostream>

using namespace std;

long long n, k;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> k;

	bool answer = false;
	long long front = 0;
	long long rear = n;
	while (front <= rear) {
		long long mid1 = (front + rear) / 2;
		long long mid2 = n - mid1;

		long long cnt = (mid1 + 1) * (mid2 + 1);
		if (cnt < k) {
			front = mid1 + 1;
		}
		else if (cnt > k) {
			rear = mid1 - 1;
		}
		else {
			answer = true;
			break;
		}
	}

	if (answer) cout << "YES";
	else cout << "NO";

	return 0;
}
