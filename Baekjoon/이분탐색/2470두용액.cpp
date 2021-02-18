#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin >> n;
	vector<int> liquid(n);
	for (int i = 0; i < n; i++) cin >> liquid[i];
	sort(liquid.begin(), liquid.end());
	int left = 0;
	int right = n - 1;
	
	int answer = 2000000001;
	pair<int, int> p;
	while (left < right && left < n && right >= 0) {
		int sum = liquid[left] + liquid[right];
		if (answer > abs(sum)) {
			answer = abs(sum);
			p.first = liquid[left];
			p.second = liquid[right];
		}

		if (sum < 0) {
			left++;
		}
		else if (sum > 0) {
			right--;
		}
		else {
			break;
		}

	}

	cout << p.first << ' ' << p.second;
	return 0;
}
