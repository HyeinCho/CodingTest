#include<iostream>
#include<string>

using namespace std;

int chess[8][8];
int dx[] = { 0, 0, 1, -1, -1, -1, 1, 1 };
int dy[] = { 1, -1, 0, 0, 1, -1, 1, -1 };
string d[] = { "R", "L", "B", "T", "RT", "LT", "RB", "LB" };

pair<int, int> findLocation(string s) {
	pair<int, int> tmp;
	tmp.second = s[0] - 'A';
	tmp.first = 8 - (s[1] - '0');
	return tmp;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	string a, b;
	int n;
	cin >> a >> b >> n;
	pair<int, int> king = findLocation(a);
	pair<int, int> stone = findLocation(b);

	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		for (int j = 0; j < 8; j++) {
			if (d[j] == s) {
				int nx = king.first + dx[j];
				int ny = king.second + dy[j];
				if (nx < 0 || nx >= 8 || ny < 0 || ny >= 8) break;
				if (nx == stone.first && ny == stone.second) {
					int sx = stone.first + dx[j];
					int sy = stone.second + dy[j];
					if (sx < 0 || sx >= 8 || sy < 0 || sy >= 8) break;
					stone.first = sx;
					stone.second = sy;
				}
				king.first = nx;
				king.second = ny;
				break;
			}
		}
	}
	a = king.second + 'A';
	a += 8 - king.first + '0';
	b = stone.second + 'A';
	b += 8 - stone.first + '0';
	cout << a << '\n';
	cout << b << '\n';

	return 0;
}
