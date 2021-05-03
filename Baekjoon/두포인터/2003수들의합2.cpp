#include<iostream>

using namespace std;

int n, m;
int a[10000];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;
	for (int i = 0; i < n; i++) cin >> a[i];

	int answer = 0;
	int front = 0;
	int rear = 0;
	int sum = 0;
	while (front <= rear && front < n) {
		if (sum == m) {
			answer++;
			sum -= a[front++];
		}
		else if (sum < m) {
			sum += a[rear++];
		}
		else {
			sum -= a[front++];
		}
	}
	cout << answer;
	return 0;
}
