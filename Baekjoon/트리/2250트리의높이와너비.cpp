#include<iostream>
#include<algorithm>

using namespace std;

int n, node_idx;
int node[10001];
int low[10001];
int high[10001];
pair<int, int> tree[10001];

void inorder(int idx, int cnt) {
	// 왼
	if (tree[idx].first > 0) {
		inorder(tree[idx].first, cnt + 1);
	}

	// 중간
	low[cnt] = min(low[cnt], node_idx);
	high[cnt] = max(high[cnt], node_idx);
	node_idx++;

	// 오른
	if (tree[idx].second > 0) {
		inorder(tree[idx].second, cnt + 1);
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;

	for (int i = 0; i < 10001; i++) low[i] = 2147000000;

	for (int i = 1; i <= n; i++) {
		int parent, left, right;
		cin >> parent >> left >> right;

		tree[parent] = { left, right };

		node[parent]++;
		if (left != -1) node[left]++;
		if (right != -1) node[right]++;
	}

	// 루트 찾기
	int root = -1;
	for (int i = 1; i <= n; i++) {
		if (node[i] == 1) {
			root = i;
			break;
		}
	}

	node_idx = 1;
	inorder(root, 1);

	int answer = -2;
	int level = -1;
	for (int i = 1; i <= n; i++) {
		int tmp = high[i] - low[i];
		if (answer < tmp) {
			answer = tmp;
			level = i;
		}
	}

	cout << level << ' ' << answer + 1;

	return 0;
}
