#include<iostream>
#include<vector>

using namespace std;

int n, k;
int arr[1001] = { -1, };
int parent[1001] = { -1, };

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	while (true)
	{
		cin >> n >> k;
		if (n == 0 && k == 0) break;

		int cnt = -1;
		int idx = 0;
		for (int i = 1; i <= n; i++) {
			cin >> arr[i];
			if (arr[i] == k) idx = i;
			if (arr[i] != arr[i - 1] + 1) cnt++;
			parent[i] = cnt;
		}
		
		int answer = 0;
		for (int i = 1; i <= n; i++) {
			if (parent[i] != parent[idx] && parent[parent[i]] == parent[parent[idx]]) answer++;
		}

		cout << answer << '\n';
	}

	return 0;
}
