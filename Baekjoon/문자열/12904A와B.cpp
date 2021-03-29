#include<iostream>
#include<string>
#include<algorithm>

using namespace std;

string s, t;
bool flag = false;

void game(string str) {
	if (flag) return;
	else if (str.size() <= s.size()) {
		if (str == s) {
			flag = true;
		}
		return;
	}

	char c = str.back();
	str.pop_back();
	if (c == 'A') {
		game(str);
	}
	else { // 'B'
		reverse(str.begin(), str.end());
		game(str);
		reverse(str.begin(), str.end());
	}
	str.push_back(c);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> s >> t;
	game(t);
	if (flag) cout << 1;
	else cout << 0;

	return 0;
}
