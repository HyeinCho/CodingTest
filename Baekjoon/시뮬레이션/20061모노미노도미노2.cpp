#include<iostream>
#include<vector>

using namespace std;

int n;
int answer = 0;

int count_num(vector<vector<bool>>& v) {
	int result = 0;
	for (int i = 0; i < 6; i++) {
		for (int j = 0; j < 4; j++) {
			if (v[i][j]) result++;
		}
	}
	return result;
}

void simulate(int t, int y, vector<vector<bool>>& v) {
	
	// 블럭 쌓기
	int nx = 0;
	int ny = y;
	for (int i = 0; i < 6; i++) {
		if (t == 2) {
			if (v[i][y] || v[i][y + 1]) break;
		}
		else {
			if (v[i][y]) break;
		}
		nx = i;
	}

	v[nx][y] = true;
	if (t == 2) v[nx][y + 1] = true;
	else if (t == 3) v[nx - 1][y] = true;

	// 채워진 행 지우기
	bool flag = true;
	for (int i = 0; i < 4; i++) {
		if (!v[nx][i]) {
			flag = false;
			break;
		}
	}
	
	if (flag) {
		answer++;
		for (int i = nx - 1; i >= 0; i--) {
			for (int j = 0; j < 4; j++) {
				v[i + 1][j] = v[i][j];
			}
		}
	}

	if (t == 3) {
		if (flag) {
			bool flag2 = true;
			for (int i = 0; i < 4; i++) {
				if (!v[nx][i]) {
					flag2 = false;
					break;
				}
			}

			if (flag2) {
				answer++;
				for (int i = nx - 1; i >= 0; i--) {
					for (int j = 0; j < 4; j++) {
						v[i + 1][j] = v[i][j];
					}
				}
				
			}

		}
		else {
			bool flag2 = true;
			for (int i = 0; i < 4; i++) {
				if (!v[nx - 1][i]) {
					flag2 = false;
					break;
				}
			}

			if (flag2) {
				answer++;
				for (int i = nx - 2; i >= 0; i--) {
					for (int j = 0; j < 4; j++) {
						v[i + 1][j] = v[i][j];
					}
				}
			}
		}
		
		
	}

	// 연한 칸인 경우
	int idx = -1;
	for (int i = 1; i >= 0; i--) {
		for (int j = 0; j < 4; j++) {
			if (v[i][j]) {
				idx = i;
				break;
			}
			
		}
	}
	int cnt = 0;
	if (idx != -1) {
		if (idx == 0) cnt = 2;
		else if (idx == 1) cnt = 1;

		for (int i = 5 - cnt; i >= 0; i--) {
			for (int j = 0; j < 4; j++) {
				v[i + cnt][j] = v[i][j];
			}
		}
		for (int i = 0; i < cnt; i++) {
			for (int j = 0; j < 4; j++) {
				v[i][j] = false;
			}
		}
	}

}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	vector<vector<bool>> green(6, vector<bool>(4));
	vector<vector<bool>> blue(6, vector<bool>(4));

	int t, x, y;
	for (int i = 0; i < n; i++) {
		cin >> t >> x >> y;
		// 그린
		simulate(t, y, green);

		// 블루
		if (t == 2) t = 3;
		else if (t == 3) t = 2;
		simulate(t, x, blue);
		
	}

	int total = count_num(green) + count_num(blue);
	cout << answer << '\n' << total << '\n';

	return 0;
}
