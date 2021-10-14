#include<iostream>
#include<algorithm>

using namespace std;

int l, c;
char word[15];

void dfs(int idx, string s, int vowel, int consonant) {
	if (s.size() == l) {
		if(vowel > 0 && consonant > 1) cout << s << '\n';
		return;
	}
	else if (idx >= c) return;

	s.push_back(word[idx]);
	if (word[idx] == 'a' || word[idx] == 'e' || word[idx] == 'i' || word[idx] == 'o' || word[idx] == 'u') {
		dfs(idx + 1, s, vowel + 1, consonant);
	}
	else {
		dfs(idx + 1, s, vowel, consonant + 1);
	}
	
	s.pop_back();
	dfs(idx + 1, s, vowel, consonant);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> l >> c;
	for (int i = 0; i < c; i++) cin >> word[i];
	sort(word, word + c);
	dfs(0, "", 0, 0);

	return 0;
}
