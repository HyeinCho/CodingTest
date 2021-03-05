#include<iostream>
#include<algorithm>

using namespace std;

int n, m;
int card[500001];

int binSearch(int num) {
	int s = 0;
	int e = n;

	while (s <= e) {
		int mid = (s + e) / 2;
		if (card[mid] < num) {
			s = mid + 1;
		}
		else if (card[mid] > num) {
			e = mid - 1;
		}
		else {
			return 1;
		}
	}
	return 0;
	
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) cin >> card[i];
	sort(card, card + n);
	cin >> m;
	for (int i = 0; i < m; i++) {
		int tmp;
		cin >> tmp;
		cout << binSearch(tmp) << ' ';
	}

	return 0;
}
