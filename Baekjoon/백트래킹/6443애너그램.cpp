#include<iostream>
#include<string.h>

using namespace std;

int n;
int alpha[26];

void dfs(int cnt, string s, int size) {
	if (cnt == size) {
		cout << s << '\n';
		return;
	}

	for (int i = 0; i < 26; i++) {
		if (alpha[i] == 0) continue;
		alpha[i]--;
		s.push_back(i + 'a');
		dfs(cnt + 1, s, size);
		s.pop_back();
		alpha[i]++;
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> n;

	string str = "";
	while (n-- > 0) {
		cin >> str;
		memset(alpha, 0, sizeof(alpha));
		for (char c : str) {
			alpha[c - 'a']++;
		}
		dfs(0, "", str.size());
	}

	return 0;
}
