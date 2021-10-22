#include<iostream>
#include<vector>
#include<algorithm>
#include<string.h>

using namespace std;

int n;
int total = 0;
int info[5];
int a[21][21];
bool visited[21][21];

void fifthLocation(int x, int y, int d1, int d2) {
	memset(info, 0, sizeof(info));
	memset(visited, 0, sizeof(visited));

	// 경계선
	for (int i = 0; i <= d1; i++) {
		visited[x + i][y - i] = true;
		visited[x + d2 + i][y + d2 - i] = true;
		info[4] += a[x + i][y - i] + a[x + d2 + i][y + d2 - i];

	}
	for (int i = 1; i < d2; i++) {
		visited[x + i][y + i] = true;
		visited[x + d1 + i][y - d1 + i] = true;
		info[4] += a[x + i][y + i] + a[x + d1 + i][y - d1 + i];
	}

	// 경계선 내부
	for (int i = 0; i < d1; i++) {
		int j = 1;
		while (!visited[x + i + j][y - i]) {
			visited[x + i + j][y - i] = true;
			info[4] += a[x + i + j][y - i];
			j++;
		}
	}

	for (int i = 1; i < d2; i++) {
		int j = 1;
		while (!visited[x + i + j][y + i]) {
			visited[x + i + j][y + i] = true;
			info[4] += a[x + i + j][y + i];
			j++;
		}
	}
}

bool firstLocation(int i, int j, int x, int y, int d1, int d2) {
	return (i < x + d1 && j <= y);
}

bool secondLocation(int i, int j, int x, int y, int d1, int d2) {
	return (i <= x + d2 && j > y);
}

bool thirdLocation(int i, int j, int x, int y, int d1, int d2) {
	return (i >= x + d1 && j < y - d1 + d2);
}

bool fourthLocation(int i, int j, int x, int y, int d1, int d2) {
	return (i > x + d2 && j >= y - d1 + d2);
}

int calc(int x, int y, int d1, int d2) {
	fifthLocation(x, y, d1, d2);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (visited[i][j]) continue;
			if (firstLocation(i, j, x, y, d1, d2)) {
				info[0] += a[i][j];
				continue;
			}
			if (secondLocation(i, j, x, y, d1, d2)) {
				info[1] += a[i][j];
				continue;
			}
			if (thirdLocation(i, j, x, y, d1, d2)) {
				info[2] += a[i][j];
				continue;
			}
			if (fourthLocation(i, j, x, y, d1, d2)) {
				info[3] += a[i][j];
				continue;
			}
		}
	}

	return *max_element(info, info + 5) - *min_element(info, info + 5);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> a[i][j];
			total += a[i][j];
		}
	}
	
	int answer = 40000;
	for (int x = 1; x <= n - 2; x++) { // x
		for (int y = 2; y <= n - 1; y++) { // y
			for (int d1 = 1; d1 <= n - x - 1 && d1 <= y - 1; d1++) { // d1
				for (int d2 = 1; d2 <= n - x - 1 && d2 <= n - y; d2++) { // d2
					int tmp = calc(x, y, d1, d2);
					if (answer > tmp) answer = tmp;
				}
			}
		}
	}

	cout << answer;
	return 0;
}
