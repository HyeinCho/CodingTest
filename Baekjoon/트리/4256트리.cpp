#include<iostream>
#include<vector>

using namespace std;

int n;
int idx;
vector<int> preTree;
vector<int> inTree;

void find(int front, int rear) {
	if (front > rear) return;

	for (int i = front; i <= rear; i++) {
		if (inTree[i] == preTree[idx]) {
			idx++;
			find(front, i - 1);
			find(i + 1, rear);
			cout << inTree[i] << ' ';
			break;
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int T;
	cin >> T;
	for (int tc = 0; tc < T; tc++) {
		cin >> n;
		preTree.resize(n);
		inTree.resize(n);
		for (int i = 0; i < n; i++) cin >> preTree[i];
		for (int i = 0; i < n; i++) cin >> inTree[i];
		idx = 0;
		find(0, n - 1);
		cout << '\n';
	}


	return 0;
}
