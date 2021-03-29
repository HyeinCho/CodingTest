#include<iostream>

using namespace std;

int n;
int animal[41];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	int answer = 1;
	for (int i = 0; i < n; i++) {
		int tmp;
		cin >> tmp;
		animal[tmp] += 1;
		if (tmp >= n || animal[tmp] > 2) answer = 0;
	}
	
	if (answer != 0) {
		int cur = 2;
		bool flag = false;
		for (int i = 0; i < n; i++) {
			if (animal[i] > cur) {
				answer = 0;
				break;
			}
			else if (animal[i] == 2) {
				answer *= 2;
			}
			else if (animal[i] == 1 && !flag) {
				answer *= 2;
				flag = true;
			}
			cur = animal[i];
		}
	}
	cout << answer;

	return 0;
}
