#include<iostream>

using namespace std;

int alpha[26];
string s;
int answer = 0;

void dfs(string str) {
	if (str.size() == s.size()) {
		answer++;
		return;
	}

	for (int i = 0; i < 26; i++) {
		if (alpha[i] > 0 && (str.empty() || str.back() - 'a' != i)) {
			alpha[i]--;
			str.push_back(i + 'a');
			dfs(str);
			str.pop_back();
			alpha[i]++;
		}
	}

}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	
	cin >> s;
	for (char c : s) {
		alpha[c - 'a'] += 1;
	}
	dfs("");
	cout << answer;

	return 0;
}
