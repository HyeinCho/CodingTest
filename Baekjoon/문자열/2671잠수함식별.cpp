#include<iostream>

using namespace std;

string s;

// 1000001110000001 => SUBMARINE
string sound() { // (100~1~|01)~
	int i = 0;
	int n = s.size();
	while (i < n) {
		if (s[i] == '1') {
			if (i < n - 2 && s[i + 1] == '0' && s[i + 2] == '0') {
				i += 3;
				while (i < n && s[i] == '0') {
					i++;
				}

				if (i < n && s[i] == '1') {
					i++;
					while (i < n && s[i] == '1') {
						if (i < n - 2 && s[i + 1] == '0' && s[i + 2] == '0') break;
						i++;
					}
				}
				else return "NOISE";
			}
			else return "NOISE";
		}
		else { // s[i] == '0'
			if (i < n - 1 && s[i+1] == '1') {
				i += 2;
			}
			else return "NOISE";
		}
	}

	return "SUBMARINE";
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> s;
	cout << sound();
	return 0;
}
