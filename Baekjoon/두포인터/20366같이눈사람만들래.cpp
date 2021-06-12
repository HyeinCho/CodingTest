#include<iostream>
#include<algorithm>

using namespace std;

int snow[600];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin >> n;

	for (int i = 0; i < n; i++) cin >> snow[i];
	sort(snow, snow + n);

	int answer = 2000000001;
	for (int i = 0; i < n - 3; i++) {
		for (int j = i + 3; j < n; j++) {
			int h1 = snow[i] + snow[j];

			int l = i + 1;
			int r = j - 1;
			while (l < r)
			{
				int h2 = snow[l] + snow[r];
				if (h1 < h2) {
					if (answer > h2 - h1) answer = h2 - h1;
					r--;
				}
				else if (h1 > h2) {
					if (answer > h1 - h2) answer = h1 - h2;
					l++;
				}
				else {
					answer = 0;
					break;
				}
			}
		}
	}

	cout << answer;

	return 0;
}
