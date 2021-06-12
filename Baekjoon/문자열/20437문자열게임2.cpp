#include<iostream>
#include<vector>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int T, k;
	string w;
	cin >> T;
	for (int tc = 0; tc < T; tc++) {
		cin >> w >> k;
		vector<vector<int>> alphabet(26);
		int answer1 = w.size() + 1;
		int answer2 = -1;
		for (int i = 0; i < w.size(); i++) alphabet[w[i] - 'a'].push_back(i);

		for (int i = 0; i < 26; i++) {
			if (alphabet[i].size() >= k) {
				for (int j = 0; j < alphabet[i].size() - k + 1; j++) {
					int tmp = alphabet[i][j + k - 1] - alphabet[i][j] + 1;
					if (answer1 > tmp) answer1 = tmp;
					if (answer2 < tmp) answer2 = tmp;
				}
			}
		}

		if (answer1 == w.size() + 1) cout << -1 << '\n';
		else cout << answer1 << ' ' << answer2 << '\n';
	}

	return 0;
}
