#include<iostream>
#include<algorithm>

using namespace std;

long long tree[1000000];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int n, m;
	cin >> n >> m;

	int h = 0;
	for (int i = 0; i < n; i++) {
		cin >> tree[i];
	}

	sort(tree, tree + n);

	long long front = 0;
	long long rear = tree[n - 1];
	long long answer = 0;
	while (front <= rear) {
		long long mid = (front + rear) / 2;
		long long sum = 0;
		for (int i = n - 1; i >= 0; i--) {
			if (tree[i] >= mid) sum += (tree[i] - mid);
			else break;
		}
		if (sum >= m) { // 정확하게 m이 나오지 않을 경우도 있기 때문에 m보다 많은 나무를 자른 경우는 answer을 계속 업데이트
			answer = mid;
			front = mid + 1;
		}
		else {
			rear = mid - 1;
		}
	}
	cout << answer;

	return 0;
}
