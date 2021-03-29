#include<iostream>

using namespace std;

int gcd(int a, int b) {
	while (b) {
		int r = a % b;
		a = b;
		b = r;
	}
	return a;
}

int lcm(int a, int b) {
	return a * b / gcd(a, b);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	string a, b;
	cin >> a >> b;
	int size = lcm(a.size(), b.size());
	
	string s1 = "", s2 = "";
	for (int i = 0; i < size; i += a.size()) s1 += a;
	for (int i = 0; i < size; i += b.size()) s2 += b;
	if (s1 == s2) cout << 1;
	else cout << 0;

	return 0;
}
